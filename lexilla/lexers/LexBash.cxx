// Scintilla source code edit control
/** @file LexBash.cxx
 ** Lexer for Bash.
 **/
// Copyright 2004-2012 by Neil Hodgson <neilh@scintilla.org>
// Adapted from LexPerl by Kein-Hong Man 2004
// The License.txt file describes the conditions under which this software may be distributed.

#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdarg>

#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <functional>

#include "ILexer.h"
#include "Scintilla.h"
#include "SciLexer.h"

#include "StringCopy.h"
#include "WordList.h"
#include "LexAccessor.h"
#include "StyleContext.h"
#include "CharacterSet.h"
#include "LexerModule.h"
#include "OptionSet.h"
#include "SubStyles.h"
#include "DefaultLexer.h"

using namespace Scintilla;
using namespace Lexilla;

namespace {

#define HERE_DELIM_MAX			256

// define this if you want 'invalid octals' to be marked as errors
// usually, this is not a good idea, permissive lexing is better
#undef PEDANTIC_OCTAL

#define BASH_BASE_ERROR			65
#define BASH_BASE_DECIMAL		66
#define BASH_BASE_HEX			67
#ifdef PEDANTIC_OCTAL
#define BASH_BASE_OCTAL			68
#define	BASH_BASE_OCTAL_ERROR	69
#endif

// state constants for parts of a bash command segment
enum class CmdState {
	Body,
	Start,
	Word,
	Test,
	Arithmetic,
	Delimiter,
};

enum class TestExprType {
	Test,			// test
	DoubleBracket,	// [[]]
	SingleBracket,	// []
};

// state constants for nested delimiter pairs, used by
// SCE_SH_STRING, SCE_SH_PARAM and SCE_SH_BACKTICKS processing
enum class QuoteStyle {
	Literal,		// ''
	CString,		// $''
	String,			// ""
	LString,		// $""
	Backtick,		// ``, $``
	Parameter,		// ${}
	Command,		// $()
};

#define BASH_QUOTE_STACK_MAX	7

constexpr int translateBashDigit(int ch) noexcept {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 10;
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 36;
	} else if (ch == '@') {
		return 62;
	} else if (ch == '_') {
		return 63;
	}
	return BASH_BASE_ERROR;
}

int getBashNumberBase(char *s) noexcept {
	int i = 0;
	int base = 0;
	while (*s) {
		base = base * 10 + (*s++ - '0');
		i++;
	}
	if (base > 64 || i > 2) {
		return BASH_BASE_ERROR;
	}
	return base;
}

constexpr int opposite(int ch) noexcept {
	if (ch == '(') return ')';
	if (ch == '[') return ']';
	if (ch == '{') return '}';
	if (ch == '<') return '>';
	return ch;
}

int GlobScan(StyleContext &sc) {
	// forward scan for zsh globs, disambiguate versus bash arrays
	// complex expressions may still fail, e.g. unbalanced () '' "" etc
	int c;
	int sLen = 0;
	int pCount = 0;
	int hash = 0;
	while ((c = sc.GetRelativeCharacter(++sLen)) != 0) {
		if (IsASpace(c)) {
			return 0;
		} else if (c == '\'' || c == '\"') {
			if (hash != 2) return 0;
		} else if (c == '#' && hash == 0) {
			hash = (sLen == 1) ? 2:1;
		} else if (c == '(') {
			pCount++;
		} else if (c == ')') {
			if (pCount == 0) {
				if (hash) return sLen;
				return 0;
			}
			pCount--;
		}
	}
	return 0;
}

bool IsCommentLine(Sci_Position line, LexAccessor &styler) {
	const Sci_Position pos = styler.LineStart(line);
	const Sci_Position eol_pos = styler.LineStart(line + 1) - 1;
	for (Sci_Position i = pos; i < eol_pos; i++) {
		const char ch = styler[i];
		if (ch == '#')
			return true;
		else if (ch != ' ' && ch != '\t')
			return false;
	}
	return false;
}

struct OptionsBash {
	bool fold;
	bool foldComment;
	bool foldCompact;

	OptionsBash() {
		fold = false;
		foldComment = false;
		foldCompact = true;
	}
};

const char * const bashWordListDesc[] = {
	"Keywords",
	nullptr
};

struct OptionSetBash : public OptionSet<OptionsBash> {
	OptionSetBash() {
		DefineProperty("fold", &OptionsBash::fold);

		DefineProperty("fold.comment", &OptionsBash::foldComment);

		DefineProperty("fold.compact", &OptionsBash::foldCompact);

		DefineWordListSets(bashWordListDesc);
	}
};

const char styleSubable[] = { SCE_SH_IDENTIFIER, SCE_SH_SCALAR, 0 };

const LexicalClass lexicalClasses[] = {
	// Lexer Bash SCLEX_BASH SCE_SH_:
	0, "SCE_SH_DEFAULT", "default", "White space",
	1, "SCE_SH_ERROR", "error", "Error",
	2, "SCE_SH_COMMENTLINE", "comment line", "Line comment: #",
	3, "SCE_SH_NUMBER", "literal numeric", "Number",
	4, "SCE_SH_WORD", "keyword", "Keyword",
	5, "SCE_SH_STRING", "literal string", "String",
	6, "SCE_SH_CHARACTER", "literal string", "Single quoted string",
	7, "SCE_SH_OPERATOR", "operator", "Operators",
	8, "SCE_SH_IDENTIFIER", "identifier", "Identifiers",
	9, "SCE_SH_SCALAR", "identifier", "Scalar variable",
	10, "SCE_SH_PARAM", "identifier", "Parameter",
	11, "SCE_SH_BACKTICKS", "literal string", "Backtick quoted command",
	12, "SCE_SH_HERE_DELIM", "operator", "Heredoc delimiter",
	13, "SCE_SH_HERE_Q", "literal string", "Heredoc quoted string",
};

}

class LexerBash final : public DefaultLexer {
	WordList keywords;
	OptionsBash options;
	OptionSetBash osBash;
	enum { ssIdentifier, ssScalar };
	SubStyles subStyles;
public:
	LexerBash() :
		DefaultLexer("bash", SCLEX_BASH, lexicalClasses, ELEMENTS(lexicalClasses)),
		subStyles(styleSubable, 0x80, 0x40, 0) {
	}
	void SCI_METHOD Release() override {
		delete this;
	}
	int SCI_METHOD Version() const override {
		return lvRelease5;
	}
	const char * SCI_METHOD PropertyNames() override {
		return osBash.PropertyNames();
	}
	int SCI_METHOD PropertyType(const char* name) override {
		return osBash.PropertyType(name);
	}
	const char * SCI_METHOD DescribeProperty(const char *name) override {
		return osBash.DescribeProperty(name);
	}
	Sci_Position SCI_METHOD PropertySet(const char *key, const char *val) override;
	const char * SCI_METHOD PropertyGet(const char* key) override {
		return osBash.PropertyGet(key);
	}
	const char * SCI_METHOD DescribeWordListSets() override {
		return osBash.DescribeWordListSets();
	}
	Sci_Position SCI_METHOD WordListSet(int n, const char *wl) override;
	void SCI_METHOD Lex(Sci_PositionU startPos, Sci_Position length, int initStyle, IDocument *pAccess) override;
	void SCI_METHOD Fold(Sci_PositionU startPos, Sci_Position length, int initStyle, IDocument *pAccess) override;

	void * SCI_METHOD PrivateCall(int, void *) override {
		return nullptr;
	}

	int SCI_METHOD AllocateSubStyles(int styleBase, int numberStyles) override {
		return subStyles.Allocate(styleBase, numberStyles);
	}
	int SCI_METHOD SubStylesStart(int styleBase) override {
		return subStyles.Start(styleBase);
	}
	int SCI_METHOD SubStylesLength(int styleBase) override {
		return subStyles.Length(styleBase);
	}
	int SCI_METHOD StyleFromSubStyle(int subStyle) override {
		const int styleBase = subStyles.BaseStyle(subStyle);
		return styleBase;
	}
	int SCI_METHOD PrimaryStyleFromStyle(int style) override {
		return style;
	}
	void SCI_METHOD FreeSubStyles() override {
		subStyles.Free();
	}
	void SCI_METHOD SetIdentifiers(int style, const char *identifiers) override {
		subStyles.SetIdentifiers(style, identifiers);
	}
	int SCI_METHOD DistanceToSecondaryStyles() override {
		return 0;
	}
	const char *SCI_METHOD GetSubStyleBases() override {
		return styleSubable;
	}

	static ILexer5 *LexerFactoryBash() {
		return new LexerBash();
	}
};

Sci_Position SCI_METHOD LexerBash::PropertySet(const char *key, const char *val) {
	if (osBash.PropertySet(&options, key, val)) {
		return 0;
	}
	return -1;
}

Sci_Position SCI_METHOD LexerBash::WordListSet(int n, const char *wl) {
	WordList *wordListN = nullptr;
	switch (n) {
	case 0:
		wordListN = &keywords;
		break;
	}
	Sci_Position firstModification = -1;
	if (wordListN) {
		if (wordListN->Set(wl)) {
			firstModification = 0;
		}
	}
	return firstModification;
}

void SCI_METHOD LexerBash::Lex(Sci_PositionU startPos, Sci_Position length, int initStyle, IDocument *pAccess) {
	WordList cmdDelimiter;
	WordList bashStruct;
	WordList bashStruct_in;
	cmdDelimiter.Set("| || |& & && ; ;; ( ) { }");
	bashStruct.Set("if elif fi while until else then do done esac eval");
	bashStruct_in.Set("for case select");

	const CharacterSet setWordStart(CharacterSet::setAlpha, "_");
	// note that [+-] are often parts of identifiers in shell scripts
	const CharacterSet setWord(CharacterSet::setAlphaNum, "._+-");
	CharacterSet setMetaCharacter(CharacterSet::setNone, "|&;()<> \t\r\n");
	setMetaCharacter.Add(0);
	const CharacterSet setBashOperator(CharacterSet::setNone, "^&%()-+=|{}[]:;>,*/<?!.~@");
	const CharacterSet setSingleCharOp(CharacterSet::setNone, "rwxoRWXOezsfdlpSbctugkTBMACahGLNn");
	const CharacterSet setParam(CharacterSet::setAlphaNum, "$_");
	const CharacterSet setHereDoc(CharacterSet::setAlpha, "_\\-+!%*,./:?@[]^`{}~");
	const CharacterSet setHereDoc2(CharacterSet::setAlphaNum, "_-+!%*,./:=?@[]^`{}~");
	const CharacterSet setLeftShift(CharacterSet::setDigits, "$");

	class HereDocCls {	// Class to manage HERE document elements
	public:
		int State;		// 0: '<<' encountered
		// 1: collect the delimiter
		// 2: here doc text (lines after the delimiter)
		int Quote;		// the char after '<<'
		bool Quoted;		// true if Quote in ('\'','"','`')
		bool Indent;		// indented delimiter (for <<-)
		int DelimiterLength;	// strlen(Delimiter)
		char Delimiter[HERE_DELIM_MAX];	// the Delimiter
		HereDocCls() {
			State = 0;
			Quote = '\0';
			Quoted = false;
			Indent = false;
			DelimiterLength = 0;
			Delimiter[0] = '\0';
		}
		void Append(int ch) {
			Delimiter[DelimiterLength++] = static_cast<char>(ch);
			Delimiter[DelimiterLength] = '\0';
		}
	};
	HereDocCls HereDoc;

	class QuoteCls {	// Class to manage quote pairs (simplified vs LexPerl)
		public:
		int Count;
		int Up, Down;
		QuoteCls() {
			Count = 0;
			Up    = '\0';
			Down  = '\0';
		}
		void Open(int u) {
			Count++;
			Up    = u;
			Down  = opposite(Up);
		}
		void Start(int u) {
			Count = 0;
			Open(u);
		}
	};

	class QuoteStackCls {	// Class to manage quote pairs that nest
		public:
		int Count;
		int Up, Down;
		QuoteStyle Style;
		int Depth;			// levels pushed
		int CountStack[BASH_QUOTE_STACK_MAX];
		int UpStack   [BASH_QUOTE_STACK_MAX];
		QuoteStyle StyleStack[BASH_QUOTE_STACK_MAX];
		QuoteStackCls() {
			Count = 0;
			Up    = '\0';
			Down  = '\0';
			Style = QuoteStyle::Literal;
			Depth = 0;
		}
		void Start(int u, QuoteStyle s) {
			Count = 1;
			Up    = u;
			Down  = opposite(Up);
			Style = s;
		}
		void Push(int u, QuoteStyle s) {
			if (Depth >= BASH_QUOTE_STACK_MAX)
				return;
			CountStack[Depth] = Count;
			UpStack   [Depth] = Up;
			StyleStack[Depth] = Style;
			Depth++;
			Count = 1;
			Up    = u;
			Down  = opposite(Up);
			Style = s;
		}
		void Pop(void) {
			if (Depth <= 0)
				return;
			Depth--;
			Count = CountStack[Depth];
			Up    = UpStack   [Depth];
			Style = StyleStack[Depth];
			Down  = opposite(Up);
		}
	};
	QuoteStackCls QuoteStack;

	const WordClassifier &classifierIdentifiers = subStyles.Classifier(SCE_SH_IDENTIFIER);
	const WordClassifier &classifierScalars = subStyles.Classifier(SCE_SH_SCALAR);

	int numBase = 0;
	int digit;
	const Sci_PositionU endPos = startPos + length;
	CmdState cmdState = CmdState::Start;
	TestExprType testExprType = TestExprType::Test;
	LexAccessor styler(pAccess);

	// Always backtracks to the start of a line that is not a continuation
	// of the previous line (i.e. start of a bash command segment)
	Sci_Position ln = styler.GetLine(startPos);
	if (ln > 0 && startPos == static_cast<Sci_PositionU>(styler.LineStart(ln)))
		ln--;
	for (;;) {
		startPos = styler.LineStart(ln);
		if (ln == 0 || styler.GetLineState(ln) == static_cast<int>(CmdState::Start))
			break;
		ln--;
	}
	initStyle = SCE_SH_DEFAULT;

	StyleContext sc(startPos, endPos - startPos, initStyle, styler);

	for (; sc.More(); sc.Forward()) {

		// handle line continuation, updates per-line stored state
		if (sc.atLineStart) {
			ln = styler.GetLine(sc.currentPos);
			if (sc.state == SCE_SH_STRING
			 || sc.state == SCE_SH_BACKTICKS
			 || sc.state == SCE_SH_CHARACTER
			 || sc.state == SCE_SH_HERE_Q
			 || sc.state == SCE_SH_COMMENTLINE
			 || sc.state == SCE_SH_PARAM) {
				// force backtrack while retaining cmdState
				styler.SetLineState(ln, static_cast<int>(CmdState::Body));
			} else {
				if (ln > 0) {
					if ((sc.GetRelative(-3) == '\\' && sc.GetRelative(-2) == '\r' && sc.chPrev == '\n')
					 || sc.GetRelative(-2) == '\\') {	// handle '\' line continuation
						// retain last line's state
					} else
						cmdState = CmdState::Start;
				}
				styler.SetLineState(ln, static_cast<int>(cmdState));
			}
		}

		// controls change of cmdState at the end of a non-whitespace element
		// states Body|Test|Arithmetic persist until the end of a command segment
		// state Word persist, but ends with 'in' or 'do' construct keywords
		CmdState cmdStateNew = CmdState::Body;
		if (cmdState == CmdState::Test || cmdState == CmdState::Arithmetic || cmdState == CmdState::Word)
			cmdStateNew = cmdState;
		const int stylePrev = sc.state;

		// Determine if the current state should terminate.
		switch (sc.state) {
			case SCE_SH_OPERATOR:
				sc.SetState(SCE_SH_DEFAULT);
				if (cmdState == CmdState::Delimiter)		// if command delimiter, start new command
					cmdStateNew = CmdState::Start;
				else if (sc.chPrev == '\\')			// propagate command state if line continued
					cmdStateNew = cmdState;
				break;
			case SCE_SH_WORD:
				// "." never used in Bash variable names but used in file names
				if (!setWord.Contains(sc.ch)) {
					char s[500];
					char s2[10];
					sc.GetCurrent(s, sizeof(s));
					int identifierStyle = SCE_SH_IDENTIFIER;
					const int subStyle = classifierIdentifiers.ValueFor(s);
					if (subStyle >= 0) {
						identifierStyle = subStyle;
					}
					// allow keywords ending in a whitespace or command delimiter
					s2[0] = static_cast<char>(sc.ch);
					s2[1] = '\0';
					const bool keywordEnds = IsASpace(sc.ch) || cmdDelimiter.InList(s2);
					// 'in' or 'do' may be construct keywords
					if (cmdState == CmdState::Word) {
						if (strcmp(s, "in") == 0 && keywordEnds)
							cmdStateNew = CmdState::Body;
						else if (strcmp(s, "do") == 0 && keywordEnds)
							cmdStateNew = CmdState::Start;
						else
							sc.ChangeState(identifierStyle);
						sc.SetState(SCE_SH_DEFAULT);
						break;
					}
					// a 'test' keyword starts a test expression
					if (strcmp(s, "test") == 0) {
						if (cmdState == CmdState::Start && keywordEnds) {
							cmdStateNew = CmdState::Test;
							testExprType = TestExprType::Test;
						} else
							sc.ChangeState(identifierStyle);
					}
					// detect bash construct keywords
					else if (bashStruct.InList(s)) {
						if (cmdState == CmdState::Start && keywordEnds)
							cmdStateNew = CmdState::Start;
						else
							sc.ChangeState(identifierStyle);
					}
					// 'for'|'case'|'select' needs 'in'|'do' to be highlighted later
					else if (bashStruct_in.InList(s)) {
						if (cmdState == CmdState::Start && keywordEnds)
							cmdStateNew = CmdState::Word;
						else
							sc.ChangeState(identifierStyle);
					}
					// disambiguate option items and file test operators
					else if (s[0] == '-') {
						if (cmdState != CmdState::Test)
							sc.ChangeState(identifierStyle);
					}
					// disambiguate keywords and identifiers
					else if (cmdState != CmdState::Start
						  || !(keywords.InList(s) && keywordEnds)) {
						sc.ChangeState(identifierStyle);
					}
					sc.SetState(SCE_SH_DEFAULT);
				}
				break;
			case SCE_SH_IDENTIFIER:
				if (sc.chPrev == '\\' || !setWord.Contains(sc.ch) ||
					  (cmdState == CmdState::Arithmetic && !setWordStart.Contains(sc.ch))) {
					char s[500];
					sc.GetCurrent(s, sizeof(s));
					const int subStyle = classifierIdentifiers.ValueFor(s);
					if (subStyle >= 0) {
						sc.ChangeState(subStyle);
					}
					if (sc.chPrev == '\\') {	// for escaped chars
						sc.ForwardSetState(SCE_SH_DEFAULT);
					} else {
						sc.SetState(SCE_SH_DEFAULT);
					}
				}
				break;
			case SCE_SH_NUMBER:
				digit = translateBashDigit(sc.ch);
				if (numBase == BASH_BASE_DECIMAL) {
					if (sc.ch == '#') {
						char s[10];
						sc.GetCurrent(s, sizeof(s));
						numBase = getBashNumberBase(s);
						if (numBase != BASH_BASE_ERROR)
							break;
					} else if (IsADigit(sc.ch))
						break;
				} else if (numBase == BASH_BASE_HEX) {
					if (IsADigit(sc.ch, 16))
						break;
#ifdef PEDANTIC_OCTAL
				} else if (numBase == BASH_BASE_OCTAL ||
						   numBase == BASH_BASE_OCTAL_ERROR) {
					if (digit <= 7)
						break;
					if (digit <= 9) {
						numBase = BASH_BASE_OCTAL_ERROR;
						break;
					}
#endif
				} else if (numBase == BASH_BASE_ERROR) {
					if (digit <= 9)
						break;
				} else {	// DD#DDDD number style handling
					if (digit != BASH_BASE_ERROR) {
						if (numBase <= 36) {
							// case-insensitive if base<=36
							if (digit >= 36) digit -= 26;
						}
						if (digit < numBase)
							break;
						if (digit <= 9) {
							numBase = BASH_BASE_ERROR;
							break;
						}
					}
				}
				// fallthrough when number is at an end or error
				if (numBase == BASH_BASE_ERROR
#ifdef PEDANTIC_OCTAL
					|| numBase == BASH_BASE_OCTAL_ERROR
#endif
				) {
					sc.ChangeState(SCE_SH_ERROR);
				}
				sc.SetState(SCE_SH_DEFAULT);
				break;
			case SCE_SH_COMMENTLINE:
				if (sc.MatchLineEnd() && sc.chPrev != '\\') {
					sc.SetState(SCE_SH_DEFAULT);
				}
				break;
			case SCE_SH_HERE_DELIM:
				// From Bash info:
				// ---------------
				// Specifier format is: <<[-]WORD
				// Optional '-' is for removal of leading tabs from here-doc.
				// Whitespace acceptable after <<[-] operator
				//
				if (HereDoc.State == 0) { // '<<' encountered
					HereDoc.Quote = sc.chNext;
					HereDoc.Quoted = false;
					HereDoc.DelimiterLength = 0;
					HereDoc.Delimiter[HereDoc.DelimiterLength] = '\0';
					if (sc.chNext == '\'' || sc.chNext == '\"') {	// a quoted here-doc delimiter (' or ")
						sc.Forward();
						HereDoc.Quoted = true;
						HereDoc.State = 1;
					} else if (setHereDoc.Contains(sc.chNext) ||
					           (sc.chNext == '=' && cmdState != CmdState::Arithmetic)) {
						// an unquoted here-doc delimiter, no special handling
						HereDoc.State = 1;
					} else if (sc.chNext == '<') {	// HERE string <<<
						sc.Forward();
						sc.ForwardSetState(SCE_SH_DEFAULT);
					} else if (IsASpace(sc.chNext)) {
						// eat whitespace
					} else if (setLeftShift.Contains(sc.chNext) ||
					           (sc.chNext == '=' && cmdState == CmdState::Arithmetic)) {
						// left shift <<$var or <<= cases
						sc.ChangeState(SCE_SH_OPERATOR);
						sc.ForwardSetState(SCE_SH_DEFAULT);
					} else {
						// symbols terminates; deprecated zero-length delimiter
						HereDoc.State = 1;
					}
				} else if (HereDoc.State == 1) { // collect the delimiter
					// * if single quoted, there's no escape
					// * if double quoted, there are \\ and \" escapes
					if ((HereDoc.Quote == '\'' && sc.ch != HereDoc.Quote) ||
					    (HereDoc.Quoted && sc.ch != HereDoc.Quote && sc.ch != '\\') ||
					    (HereDoc.Quote != '\'' && sc.chPrev == '\\') ||
					    (setHereDoc2.Contains(sc.ch))) {
						HereDoc.Append(sc.ch);
					} else if (HereDoc.Quoted && sc.ch == HereDoc.Quote) {	// closing quote => end of delimiter
						sc.ForwardSetState(SCE_SH_DEFAULT);
					} else if (sc.ch == '\\') {
						if (HereDoc.Quoted && sc.chNext != HereDoc.Quote && sc.chNext != '\\') {
							// in quoted prefixes only \ and the quote eat the escape
							HereDoc.Append(sc.ch);
						} else {
							// skip escape prefix
						}
					} else if (!HereDoc.Quoted) {
						sc.SetState(SCE_SH_DEFAULT);
					}
					if (HereDoc.DelimiterLength >= HERE_DELIM_MAX - 1) {	// force blowup
						sc.SetState(SCE_SH_ERROR);
						HereDoc.State = 0;
					}
				}
				break;
			case SCE_SH_HERE_Q:
				// HereDoc.State == 2
				if (sc.atLineStart) {
					sc.SetState(SCE_SH_HERE_Q);
					int prefixws = 0;
					while (sc.ch == '\t' && !sc.MatchLineEnd()) {	// tabulation prefix
						sc.Forward();
						prefixws++;
					}
					if (prefixws > 0)
						sc.SetState(SCE_SH_HERE_Q);
					while (!sc.MatchLineEnd()) {
						sc.Forward();
					}
					char s[HERE_DELIM_MAX];
					sc.GetCurrent(s, sizeof(s));
					if (sc.LengthCurrent() == 0) {  // '' or "" delimiters
						if ((prefixws == 0 || HereDoc.Indent) &&
							HereDoc.Quoted && HereDoc.DelimiterLength == 0)
							sc.SetState(SCE_SH_DEFAULT);
						break;
					}
					if (s[strlen(s) - 1] == '\r')
						s[strlen(s) - 1] = '\0';
					if (strcmp(HereDoc.Delimiter, s) == 0) {
						if ((prefixws == 0) ||	// indentation rule
							(prefixws > 0 && HereDoc.Indent)) {
							sc.SetState(SCE_SH_DEFAULT);
							break;
						}
					}
				}
				break;
			case SCE_SH_SCALAR:	// variable names
				if (!setParam.Contains(sc.ch)) {
					char s[500];
					sc.GetCurrent(s, sizeof(s));
					const int subStyle = classifierScalars.ValueFor(&s[1]); // skip the $
					if (subStyle >= 0) {
						sc.ChangeState(subStyle);
					}
					if (sc.LengthCurrent() == 1) {
						// Special variable: $(, $_ etc.
						sc.ForwardSetState(SCE_SH_DEFAULT);
					} else {
						sc.SetState(SCE_SH_DEFAULT);
					}
				}
				break;
			case SCE_SH_STRING:	// delimited styles, can nest
			case SCE_SH_PARAM: // ${parameter}
			case SCE_SH_BACKTICKS:
				if (sc.ch == '\\' && QuoteStack.Up != '\\') {
					if (QuoteStack.Style != QuoteStyle::Literal)
						sc.Forward();
				} else if (sc.ch == QuoteStack.Down) {
					QuoteStack.Count--;
					if (QuoteStack.Count == 0) {
						if (QuoteStack.Depth > 0) {
							QuoteStack.Pop();
						} else
							sc.ForwardSetState(SCE_SH_DEFAULT);
					}
				} else if (sc.ch == QuoteStack.Up) {
					QuoteStack.Count++;
				} else {
					if (QuoteStack.Style == QuoteStyle::String ||
						QuoteStack.Style == QuoteStyle::LString
					) {	// do nesting for "string", $"locale-string"
						if (sc.ch == '`') {
							QuoteStack.Push(sc.ch, QuoteStyle::Backtick);
						} else if (sc.ch == '$' && sc.chNext == '(') {
							sc.Forward();
							QuoteStack.Push(sc.ch, QuoteStyle::Command);
						}
					} else if (QuoteStack.Style == QuoteStyle::Command ||
							   QuoteStack.Style == QuoteStyle::Parameter ||
							   QuoteStack.Style == QuoteStyle::Backtick
					) {	// do nesting for $(command), `command`, ${parameter}
						if (sc.ch == '\'') {
							QuoteStack.Push(sc.ch, QuoteStyle::Literal);
						} else if (sc.ch == '\"') {
							QuoteStack.Push(sc.ch, QuoteStyle::String);
						} else if (sc.ch == '`') {
							QuoteStack.Push(sc.ch, QuoteStyle::Backtick);
						} else if (sc.ch == '$') {
							if (sc.chNext == '\'') {
								sc.Forward();
								QuoteStack.Push(sc.ch, QuoteStyle::CString);
							} else if (sc.chNext == '\"') {
								sc.Forward();
								QuoteStack.Push(sc.ch, QuoteStyle::LString);
							} else if (sc.chNext == '{') {
								sc.Forward();
								QuoteStack.Push(sc.ch, QuoteStyle::Parameter);
							} else if (sc.chNext == '(') {
								sc.Forward();
								QuoteStack.Push(sc.ch, QuoteStyle::Command);
							}
						}
					}
				}
				break;
			case SCE_SH_CHARACTER: // singly-quoted strings
				if (sc.ch == '\'') {
					sc.ForwardSetState(SCE_SH_DEFAULT);
				}
				break;
		}

		// Must check end of HereDoc state 1 before default state is handled
		if (HereDoc.State == 1 && sc.MatchLineEnd()) {
			// Begin of here-doc (the line after the here-doc delimiter):
			// Lexically, the here-doc starts from the next line after the >>, but the
			// first line of here-doc seem to follow the style of the last EOL sequence
			HereDoc.State = 2;
			if (HereDoc.Quoted) {
				if (sc.state == SCE_SH_HERE_DELIM) {
					// Missing quote at end of string! Syntax error in bash 4.3
					// Mark this bit as an error, do not colour any here-doc
					sc.ChangeState(SCE_SH_ERROR);
					sc.SetState(SCE_SH_DEFAULT);
				} else {
					// HereDoc.Quote always == '\''
					sc.SetState(SCE_SH_HERE_Q);
				}
			} else if (HereDoc.DelimiterLength == 0) {
				// no delimiter, illegal (but '' and "" are legal)
				sc.ChangeState(SCE_SH_ERROR);
				sc.SetState(SCE_SH_DEFAULT);
			} else {
				sc.SetState(SCE_SH_HERE_Q);
			}
		}

		// update cmdState about the current command segment
		if (stylePrev != SCE_SH_DEFAULT && sc.state == SCE_SH_DEFAULT) {
			cmdState = cmdStateNew;
		}
		// Determine if a new state should be entered.
		if (sc.state == SCE_SH_DEFAULT) {
			if (sc.ch == '\\') {
				// Bash can escape any non-newline as a literal
				sc.SetState(SCE_SH_IDENTIFIER);
				if (sc.chNext == '\r' || sc.chNext == '\n')
					sc.SetState(SCE_SH_OPERATOR);
			} else if (IsADigit(sc.ch)) {
				sc.SetState(SCE_SH_NUMBER);
				numBase = BASH_BASE_DECIMAL;
				if (sc.ch == '0') {	// hex,octal
					if (sc.chNext == 'x' || sc.chNext == 'X') {
						numBase = BASH_BASE_HEX;
						sc.Forward();
					} else if (IsADigit(sc.chNext)) {
#ifdef PEDANTIC_OCTAL
						numBase = BASH_BASE_OCTAL;
#else
						numBase = BASH_BASE_HEX;
#endif
					}
				}
			} else if (setWordStart.Contains(sc.ch)) {
				sc.SetState(SCE_SH_WORD);
			} else if (sc.ch == '#') {
				if (stylePrev != SCE_SH_WORD && stylePrev != SCE_SH_IDENTIFIER &&
					(sc.currentPos == 0 || setMetaCharacter.Contains(sc.chPrev))) {
					sc.SetState(SCE_SH_COMMENTLINE);
				} else {
					sc.SetState(SCE_SH_WORD);
				}
				// handle some zsh features within arithmetic expressions only
				if (cmdState == CmdState::Arithmetic) {
					if (sc.chPrev == '[') {	// [#8] [##8] output digit setting
						sc.SetState(SCE_SH_WORD);
						if (sc.chNext == '#') {
							sc.Forward();
						}
					} else if (sc.Match("##^") && IsUpperCase(sc.GetRelative(3))) {	// ##^A
						sc.SetState(SCE_SH_IDENTIFIER);
						sc.Forward(3);
					} else if (sc.chNext == '#' && !IsASpace(sc.GetRelative(2))) {	// ##a
						sc.SetState(SCE_SH_IDENTIFIER);
						sc.Forward(2);
					} else if (setWordStart.Contains(sc.chNext)) {	// #name
						sc.SetState(SCE_SH_IDENTIFIER);
					}
				}
			} else if (sc.ch == '\"') {
				sc.SetState(SCE_SH_STRING);
				QuoteStack.Start(sc.ch, QuoteStyle::String);
			} else if (sc.ch == '\'') {
				sc.SetState(SCE_SH_CHARACTER);
			} else if (sc.ch == '`') {
				sc.SetState(SCE_SH_BACKTICKS);
				QuoteStack.Start(sc.ch, QuoteStyle::Backtick);
			} else if (sc.ch == '$') {
				if (sc.Match("$((")) {
					sc.SetState(SCE_SH_OPERATOR);	// handle '((' later
					continue;
				}
				sc.SetState(SCE_SH_SCALAR);
				sc.Forward();
				if (sc.ch == '{') {
					sc.ChangeState(SCE_SH_PARAM);
					QuoteStack.Start(sc.ch, QuoteStyle::Parameter);
				} else if (sc.ch == '\'') {
					sc.ChangeState(SCE_SH_STRING);
					QuoteStack.Start(sc.ch, QuoteStyle::CString);
				} else if (sc.ch == '"') {
					sc.ChangeState(SCE_SH_STRING);
					QuoteStack.Start(sc.ch, QuoteStyle::LString);
				} else if (sc.ch == '(') {
					sc.ChangeState(SCE_SH_BACKTICKS);
					QuoteStack.Start(sc.ch, QuoteStyle::Command);
				} else if (sc.ch == '`') {	// $` seen in a configure script, valid?
					sc.ChangeState(SCE_SH_BACKTICKS);
					QuoteStack.Start(sc.ch, QuoteStyle::Backtick);
				} else {
					continue;	// scalar has no delimiter pair
				}
			} else if (sc.Match('<', '<')) {
				sc.SetState(SCE_SH_HERE_DELIM);
				HereDoc.State = 0;
				if (sc.GetRelative(2) == '-') {	// <<- indent case
					HereDoc.Indent = true;
					sc.Forward();
				} else {
					HereDoc.Indent = false;
				}
			} else if (sc.ch == '-'	&&	// one-char file test operators
					   setSingleCharOp.Contains(sc.chNext) &&
					   !setWord.Contains(sc.GetRelative(2)) &&
					   IsASpace(sc.chPrev)) {
				sc.SetState(SCE_SH_WORD);
				sc.Forward();
			} else if (setBashOperator.Contains(sc.ch)) {
				char s[10];
				bool isCmdDelim = false;
				sc.SetState(SCE_SH_OPERATOR);
				// globs have no whitespace, do not appear in arithmetic expressions
				if (cmdState != CmdState::Arithmetic && sc.ch == '(' && sc.chNext != '(') {
					const int i = GlobScan(sc);
					if (i > 1) {
						sc.SetState(SCE_SH_IDENTIFIER);
						sc.Forward(i);
						continue;
					}
				}
				// handle opening delimiters for test/arithmetic expressions - ((,[[,[
				if (cmdState == CmdState::Start
				 || cmdState == CmdState::Body) {
					if (sc.Match('(', '(')) {
						cmdState = CmdState::Arithmetic;
						sc.Forward();
					} else if (sc.Match('[', '[') && IsASpace(sc.GetRelative(2))) {
						cmdState = CmdState::Test;
						testExprType = TestExprType::DoubleBracket;
						sc.Forward();
					} else if (sc.ch == '[' && IsASpace(sc.chNext)) {
						cmdState = CmdState::Test;
						testExprType = TestExprType::SingleBracket;
					}
				}
				// special state -- for ((x;y;z)) in ... looping
				if (cmdState == CmdState::Word && sc.Match('(', '(')) {
					cmdState = CmdState::Arithmetic;
					sc.Forward();
					continue;
				}
				// handle command delimiters in command Start|Body|Word state, also Test if 'test'
				if (cmdState == CmdState::Start
				 || cmdState == CmdState::Body
				 || cmdState == CmdState::Word
				 || (cmdState == CmdState::Test && testExprType == TestExprType::Test)) {
					s[0] = static_cast<char>(sc.ch);
					if (setBashOperator.Contains(sc.chNext)) {
						s[1] = static_cast<char>(sc.chNext);
						s[2] = '\0';
						isCmdDelim = cmdDelimiter.InList(s);
						if (isCmdDelim)
							sc.Forward();
					}
					if (!isCmdDelim) {
						s[1] = '\0';
						isCmdDelim = cmdDelimiter.InList(s);
					}
					if (isCmdDelim) {
						cmdState = CmdState::Delimiter;
						continue;
					}
				}
				// handle closing delimiters for test/arithmetic expressions - )),]],]
				if (cmdState == CmdState::Arithmetic && sc.Match(')', ')')) {
					cmdState = CmdState::Body;
					sc.Forward();
				} else if (cmdState == CmdState::Test && IsASpace(sc.chPrev)) {
					if (sc.Match(']', ']') && testExprType == TestExprType::DoubleBracket) {
						sc.Forward();
						cmdState = CmdState::Body;
					} else if (sc.ch == ']' && testExprType == TestExprType::SingleBracket) {
						cmdState = CmdState::Body;
					}
				}
			}
		}// sc.state
	}
	sc.Complete();
	if (sc.state == SCE_SH_HERE_Q) {
		styler.ChangeLexerState(sc.currentPos, styler.Length());
	}
	sc.Complete();
}

void SCI_METHOD LexerBash::Fold(Sci_PositionU startPos, Sci_Position length, int, IDocument *pAccess) {
	if(!options.fold)
		return;

	LexAccessor styler(pAccess);

	const Sci_PositionU endPos = startPos + length;
	int visibleChars = 0;
	int skipHereCh = 0;
	Sci_Position lineCurrent = styler.GetLine(startPos);
	int levelPrev = styler.LevelAt(lineCurrent) & SC_FOLDLEVELNUMBERMASK;
	int levelCurrent = levelPrev;
	char chNext = styler[startPos];
	int styleNext = styler.StyleIndexAt(startPos);
	char word[8] = { '\0' }; // we're not interested in long words anyway
	unsigned int wordlen = 0;
	for (Sci_PositionU i = startPos; i < endPos; i++) {
		const char ch = chNext;
		chNext = styler.SafeGetCharAt(i + 1);
		const int style = styleNext;
		styleNext = styler.StyleIndexAt(i + 1);
		const bool atEOL = (ch == '\r' && chNext != '\n') || (ch == '\n');
		// Comment folding
		if (options.foldComment && atEOL && IsCommentLine(lineCurrent, styler))
		{
			if (!IsCommentLine(lineCurrent - 1, styler)
				&& IsCommentLine(lineCurrent + 1, styler))
				levelCurrent++;
			else if (IsCommentLine(lineCurrent - 1, styler)
					 && !IsCommentLine(lineCurrent + 1, styler))
				levelCurrent--;
		}
		if (style == SCE_SH_WORD) {
			if ((wordlen + 1) < sizeof(word))
				word[wordlen++] = ch;
			if (styleNext != style) {
				word[wordlen] = '\0';
				wordlen = 0;
				if (strcmp(word, "if") == 0 || strcmp(word, "case") == 0 || strcmp(word, "do") == 0) {
					levelCurrent++;
				} else if (strcmp(word, "fi") == 0 || strcmp(word, "esac") == 0 || strcmp(word, "done") == 0) {
					levelCurrent--;
				}
			}
		}
		if (style == SCE_SH_OPERATOR) {
			if (ch == '{') {
				levelCurrent++;
			} else if (ch == '}') {
				levelCurrent--;
			}
		}
		// Here Document folding
		if (style == SCE_SH_HERE_DELIM) {
			if (ch == '<' && chNext == '<') {
				if (styler.SafeGetCharAt(i + 2) == '<') {
					skipHereCh = 1;
				} else {
					if (skipHereCh == 0) {
						levelCurrent++;
					} else {
						skipHereCh = 0;
					}
				}
			}
		} else if (style == SCE_SH_HERE_Q && styler.StyleAt(i+1) == SCE_SH_DEFAULT) {
			levelCurrent--;
		}
		if (atEOL) {
			int lev = levelPrev;
			if (visibleChars == 0 && options.foldCompact)
				lev |= SC_FOLDLEVELWHITEFLAG;
			if ((levelCurrent > levelPrev) && (visibleChars > 0))
				lev |= SC_FOLDLEVELHEADERFLAG;
			if (lev != styler.LevelAt(lineCurrent)) {
				styler.SetLevel(lineCurrent, lev);
			}
			lineCurrent++;
			levelPrev = levelCurrent;
			visibleChars = 0;
		}
		if (!isspacechar(ch))
			visibleChars++;
	}
	// Fill in the real level of the next line, keeping the current flags as they will be filled in later
	const int flagsNext = styler.LevelAt(lineCurrent) & ~SC_FOLDLEVELNUMBERMASK;
	styler.SetLevel(lineCurrent, levelPrev | flagsNext);
}

LexerModule lmBash(SCLEX_BASH, LexerBash::LexerFactoryBash, "bash", bashWordListDesc);

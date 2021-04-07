//{{NO_DEPENDENCIES}}
// common language (MUI) defines
//
#pragma once
#ifndef _COMMON_RES_H_
#define _COMMON_RES_H_

// undefined Sub-Language
#define SUBLANG_SPANISH_LATIN_AMERICA 0x16

#if defined(MUI_BASE_LNG_EN_US)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)
#elif defined(MUI_BASE_LNG_AF_ZA)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_AFRIKAANS, SUBLANG_AFRIKAANS_SOUTH_AFRICA)
#elif defined(MUI_BASE_LNG_BE_BY)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_BELARUSIAN, SUBLANG_BELARUSIAN_BELARUS)
#elif defined(MUI_BASE_LNG_DE_DE)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_GERMAN, SUBLANG_GERMAN)
#elif defined(MUI_BASE_LNG_EL_GR)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_GREEK, SUBLANG_GREEK_GREECE)
#elif defined(MUI_BASE_LNG_EN_GB)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_UK)
#elif defined(MUI_BASE_LNG_ES_419)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_SPANISH, SUBLANG_SPANISH_LATIN_AMERICA)
#elif defined(MUI_BASE_LNG_ES_ES)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_SPANISH, SUBLANG_SPANISH_MODERN)
#elif defined(MUI_BASE_LNG_FR_FR)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_FRENCH, SUBLANG_FRENCH)
#elif defined(MUI_BASE_LNG_HI_IN)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_HINDI, SUBLANG_HINDI_INDIA)
#elif defined(MUI_BASE_LNG_HU_HU)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_HUNGARIAN, SUBLANG_HUNGARIAN_HUNGARY)
#elif defined(MUI_BASE_LNG_ID_ID)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_INDONESIAN, SUBLANG_INDONESIAN_INDONESIA)
#elif defined(MUI_BASE_LNG_IT_IT)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_ITALIAN, SUBLANG_ITALIAN)
#elif defined(MUI_BASE_LNG_JA_JP)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_JAPANESE, SUBLANG_JAPANESE_JAPAN)
#elif defined(MUI_BASE_LNG_KO_KR)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_KOREAN, SUBLANG_KOREAN)
#elif defined(MUI_BASE_LNG_NL_NL)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_DUTCH, SUBLANG_DUTCH)
#elif defined(MUI_BASE_LNG_PL_PL)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_POLISH, SUBLANG_POLISH_POLAND)
#elif defined(MUI_BASE_LNG_PT_BR)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_PORTUGUESE, SUBLANG_PORTUGUESE_BRAZILIAN)
#elif defined(MUI_BASE_LNG_PT_PT)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_PORTUGUESE, SUBLANG_PORTUGUESE)
#elif defined(MUI_BASE_LNG_RU_RU)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA)
#elif defined(MUI_BASE_LNG_SK_SK)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_SLOVAK, SUBLANG_SLOVAK_SLOVAKIA)
#elif defined(MUI_BASE_LNG_SV_SE)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_SWEDISH, SUBLANG_SWEDISH)
#elif defined(MUI_BASE_LNG_TR_TR)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_TURKISH, SUBLANG_TURKISH_TURKEY)
#elif defined(MUI_BASE_LNG_VI_VN)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_VIETNAMESE, SUBLANG_VIETNAMESE_VIETNAM)
#elif defined(MUI_BASE_LNG_ZH_CN)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED)
#elif defined(MUI_BASE_LNG_ZH_TW)
#define MUI_BASE_LNG_ID MAKELANGID(LANG_CHINESE_TRADITIONAL, SUBLANG_CHINESE_TRADITIONAL)
#else
#define MUI_BASE_LNG_ID MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)
#endif

// ==========================================

#ifndef IDC_STATIC
#define IDC_STATIC                       (-1)
#endif
#define IDC_STATIC2                      (-2)
#define IDC_STATIC3                      (-3)
#define IDC_STATIC4                      (-4)
#define IDC_STATIC5                      (-5)
#define IDC_STATIC6                      (-6)

#define IDR_MUI_MAINMENU                10001
#define IDR_MUI_POPUPMENU               10002

#define IDT_FILE_NEW                    11000
#define IDT_FILE_OPEN                   11001
#define IDT_FILE_BROWSE                 11002
#define IDT_FILE_SAVE                   11003
#define IDT_EDIT_UNDO                   11004
#define IDT_EDIT_REDO                   11005
#define IDT_EDIT_CUT                    11006
#define IDT_EDIT_COPY                   11007
#define IDT_EDIT_PASTE                  11008
#define IDT_EDIT_FIND                   11009
#define IDT_EDIT_REPLACE                11010
#define IDT_VIEW_WORDWRAP               11011
#define IDT_VIEW_ZOOMIN                 11012
#define IDT_VIEW_ZOOMOUT                11013
#define IDT_VIEW_SCHEME                 11014
#define IDT_VIEW_SCHEMECONFIG           11015
#define IDT_FILE_EXIT                   11016
#define IDT_FILE_SAVEAS                 11017
#define IDT_FILE_SAVECOPY               11018
#define IDT_EDIT_CLEAR                  11019
#define IDT_FILE_PRINT                  11020
#define IDT_FILE_OPENFAV                11021
#define IDT_FILE_ADDTOFAV               11022
#define IDT_VIEW_TOGGLEFOLDS            11023
#define IDT_FILE_LAUNCH                 11024
#define IDT_VIEW_TOGGLE_VIEW            11025
#define IDT_VIEW_CHASING_DOCTAIL        11026
#define IDT_FILE_RECENT                 11027
#define IDT_VIEW_PIN_ON_TOP             11028
#define IDT_GREP_WIN_TOOL               11029

#define IDS_MUI_APPTITLE_ELEVATED       12006
#define IDS_MUI_APPTITLE_PASTEBOARD     12007
#define IDS_MUI_UNTITLED                12008
#define IDS_MUI_TITLEEXCERPT            12009
#define IDS_MUI_READONLY                12010
#define IDS_MUI_FILELOCKED              12011
#define IDS_MUI_LOADFILE                12012
#define IDS_MUI_SAVEFILE                12013
#define IDS_MUI_PRINTFILE               12014
#define IDS_MUI_SAVINGSETTINGS          12015
#define IDS_MUI_LINKDESCRIPTION         12016
#define IDS_MUI_FILTER_ALL              12017
#define IDS_MUI_FILTER_EXE              12018
#define IDS_MUI_FILTER_INI              12019
#define IDS_MUI_FILTER_BITMAP           12020
#define IDS_MUI_OPENWITH                12021
#define IDS_MUI_FAVORITES               12022
#define IDS_MUI_BACKSLASHHELP           12023
#define IDS_MUI_REGEXPHELP              12024
#define IDS_MUI_WILDCARDHELP            12025
#define IDS_CLEAR_ALL                   12026

#define IDS_MUI_ERR_LOADFILE            13000
#define IDS_MUI_ERR_SAVEFILE            13001
#define IDS_MUI_ERR_BROWSE              13002
#define IDS_MUI_ERR_GREPWIN             13003
#define IDS_MUI_ERR_MRUDLG              13004
#define IDS_MUI_ERR_CREATELINK          13005
#define IDS_MUI_ERR_PREVWINDISABLED     13006
#define IDS_MUI_ERR_ENCODINGNA          13007
#define IDS_MUI_ERR_UNICODE             13008
#define IDS_MUI_ERR_UNICODE2            13009
#define IDS_MUI_ERR_DROP                13010
#define IDS_MUI_ERR_ACCESSDENIED        13011
#define IDS_MUI_ERR_ADMINEXE            13012
#define IDS_MUI_ERR_BITMAP              13013
#define IDS_MUI_ERR_ELEVATED_RIGHTS     13014
#define IDS_MUI_WARN_LOAD_BIG_FILE      13015
#define IDS_MUI_ERR_FILE_TOO_LARGE      13016
#define IDS_MUI_WARN_UNKNOWN_EXT        13017
#define IDS_MUI_ERR_DLG_FORMAT          13018
// keep order (CRLF(0),  CR(1),  LF(2))
#define IDS_MUI_EOLMODENAME_CRLF        13020
#define IDS_MUI_EOLMODENAME_CR          13021
#define IDS_MUI_EOLMODENAME_LF          13022
#define IDS_MUI_WARN_NORMALIZE_EOLS     13023
#define IDS_MUI_INF_PRSVFILEMODTM       13024

#define IDS_MUI_SELRECT                 14000
#define IDS_MUI_BUFFERTOOSMALL          14001
#define IDS_MUI_FIND_WRAPFW             14002
#define IDS_MUI_FIND_WRAPRE             14003
#define IDS_MUI_NOTFOUND                14004
#define IDS_MUI_REPLCOUNT               14005
#define IDS_MUI_ASK_ENCODING            14006
#define IDS_MUI_ASK_ENCODING2           14007
#define IDS_MUI_READONLY_SAVE           14008
#define IDS_MUI_FILECHANGENOTIFY        14009
#define IDS_MUI_FILECHANGENOTIFY2       14010
#define IDS_MUI_FILELOCK_ERROR          14011
#define IDS_MUI_STICKYWINPOS            14012
#define IDS_MUI_SAVEDSETTINGS           14013
#define IDS_MUI_CREATEINI_FAIL          14014
#define IDS_MUI_WRITEINI_FAIL           14015
#define IDS_MUI_SETTINGSNOTSAVED        14016
#define IDS_MUI_EXPORT_FAIL             14017
#define IDS_MUI_REGEX_INVALID           14018
#define IDS_MUI_DROP_NO_FILE            14019
#define IDS_MUI_SELMULTI                14020
#define IDS_MUI_SELRECTORMULTI          14021
#define IDS_MUI_INIFILE_READONLY        14022

#define IDS_MUI_ASK_SAVE                15000
#define IDS_MUI_ASK_REVERT              15001
#define IDS_MUI_ASK_RECODE              15002
#define IDS_MUI_ASK_CREATE              15003
#define IDS_MUI_PRINT_HEADER            15004
#define IDS_MUI_PRINT_FOOTER            15005
#define IDS_MUI_PRINT_COLOR             15006
#define IDS_MUI_PRINT_PAGENUM           15007
#define IDS_MUI_PRINT_EMPTY             15008
#define IDS_MUI_PRINT_ERROR             15009
#define IDS_MUI_FAV_SUCCESS             15010
#define IDS_MUI_FAV_FAILURE             15011
#define IDS_MUI_READONLY_MODIFY         15012
#define IDS_MUI_SAVEPOS                 15013
#define IDS_MUI_RESETPOS                15014
#define IDS_MUI_PREVIEW                 15015
#define IDS_MUI_PASS_FAILURE            15016
#define IDS_MUI_NOPASS                  15017
#define IDS_MUI_CMDLINEHELP             15018
#define IDS_MUI_STY_BASESTD             15019
#define IDS_MUI_STY_BASE2ND             15020
#define IDS_MUI_STY_LEXDEF              15021
#define IDS_MUI_STY_LEXSTYLE            15022
#define IDS_MUI_TITLE_RELBASE           15023
#define IDS_MUI_TITLE_FIXBASE           15024
#define IDS_MUI_TITLE_RELCUR            15025
#define IDS_MUI_TITLE_FIXCUR            15026
#define IDS_MUI_TITLE_RELARB            15027
#define IDS_MUI_TITLE_FIXARB            15028
#define IDS_MUI_ABOUT_RTF_0             15029
#define IDS_MUI_ABOUT_RTF_1             15030
#define IDS_MUI_ABOUT_RTF_2             15031
#define IDS_MUI_ABOUT_RTF_3             15032
#define IDS_MUI_ABOUT_RTF_4             15033
#define IDS_MUI_ABOUT_RTF_5             15034
#define IDS_MUI_ABOUT_RTF_6             15035
#define IDS_MUI_ABOUT_DEV               15036
#define IDS_MUI_ABOUT_CONTRIBS          15037
#define IDS_MUI_ABOUT_LIBS              15038
#define IDS_MUI_ABOUT_ACKNOWLEDGES      15039
#define IDS_MUI_ABOUT_MORE              15040
#define IDS_MUI_ABOUT_LICENSES          15041
#define IDS_MUI_CLEAR_FIND_HISTORY      15042
#define IDS_MUI_CLEAR_REPL_HISTORY      15043
#define IDS_MUI_WRAPSEARCH_FWD          15044
#define IDS_MUI_WRAPSEARCH_BCK          15045

#define IDS_MUI_TRANSL_AUTHOR           15050
#define IDS_MUI_ASSOCIATED_EXT          15051
#define IDS_MUI_ZERO_LEN_MATCH          15053
#define IDS_MUI_STYLEEDIT_HELP          15054
#define IDS_MUI_GOTO_LINE               15055
#define IDS_MUI_GOTO_COLUMN             15056
#define IDS_MUI_INDENT_CONSISTENT       15057
#define IDS_MUI_URL_OPEN_FILE           15058
#define IDS_MUI_URL_OPEN_BROWSER        15059
#define IDS_MUI_STATUSBAR_PREFIXES      15060
#define IDS_MUI_STATUSBAR_POSTFIXES     15061
#define IDS_MUI_RELOADSETTINGS          15062
#define IDS_MUI_RELOADCFGSEX            15063
#define IDS_MUI_OUT_OFF_OCCMRK          15064

#define IDR_MAINWND                     16000
#define IDR_MAINWNDTB                   16001
#define IDR_MAINWNDTBHOT                16002
#define IDR_MAINWNDTBDIS                16003
#define IDR_MAINWNDTB2                  16004
#define IDR_MAINWNDTB2HOT               16005
#define IDR_MAINWNDTB2DIS               16006

#define IDI_MUI_RUN                     16100
#define IDI_MUI_STYLES                  16101

#define IDB_OPEN                        16200
#define IDB_NEXT                        16201
#define IDB_PREV                        16202
#define IDB_PICK                        16203
#define IDB_ENCODING                    16204

#define IDC_COPY                        16300

#define IDC_FONT_FAMILY_NAMES           16400
#define IDC_FONT_FACE_NAMES             16401
#define IDC_FONT_SIZE                   16402
#define IDC_SAMPLE_BOX                  16403

#define IDD_MUI_ABOUT                   17001
#define IDD_MUI_RUN                     17002
#define IDD_MUI_FIND                    17003
#define IDD_MUI_REPLACE                 17004
#define IDD_MUI_OPENWITH                17005
#define IDD_MUI_DEFENCODING             17006
#define IDD_MUI_DEFEOLMODE              17007
#define IDD_MUI_WARNLINEENDS            17008
#define IDD_MUI_WARNINDENTATION         17009
#define IDD_MUI_LINENUM                 17010
#define IDD_MUI_FILEMRU                 17011
#define IDD_MUI_CHANGENOTIFY            17012
#define IDD_MUI_STYLESELECT             17013
#define IDD_MUI_STYLECONFIG             17014
#define IDD_MUI_TABSETTINGS             17015
#define IDD_MUI_LONGLINES               17016
#define IDD_MUI_WORDWRAP                17017
#define IDD_MUI_PAGESETUP               17018
#define IDD_MUI_FAVORITES               17019
#define IDD_MUI_ADDTOFAV                17020
#define IDD_MUI_PASSWORDS               17021
#define IDD_MUI_READPW                  17022
#define IDD_MUI_COLUMNWRAP              17023
#define IDD_MUI_MODIFYLINES             17024
#define IDD_MUI_INSERTTAG               17025
#define IDD_MUI_ENCLOSESELECTION        17026
#define IDD_MUI_INFOBOX                 17027
#define IDD_MUI_INFOBOX2                17028
#define IDD_MUI_INFOBOX3                17029
#define IDD_MUI_INFOBOX4                17030
#define IDD_MUI_INFOBOX5                17031
#define IDD_MUI_SORT                    17032
#define IDD_MUI_RECODE                  17033
#define IDD_MUI_ENCODING                17034
#define IDD_MUI_ALIGN                   17035
#define IDD_MUI_CMDLINEHELP             17037

#define IDC_COMMANDLINE                 18000
#define IDC_SEARCHEXE                   18001
#define IDC_FINDTEXT                    18002
#define IDC_REPLACETEXT                 18003
#define IDC_FINDCASE                    18004
#define IDC_FINDWORD                    18005
#define IDC_FINDSTART                   18006
#define IDC_FINDTRANSFORMBS             18007
#define IDC_FINDREGEXP                  18009
#define IDC_DOT_MATCH_ALL               18010
#define IDC_NOWRAP                      18011
#define IDC_FINDCLOSE                   18012
#define IDC_ALL_OCCURRENCES             18013
#define IDC_WILDCARDSEARCH              18014
#define IDC_FINDPREV                    18015
#define IDC_REPLACE                     18016
#define IDC_REPLACEINSEL                18017
#define IDC_REPLACEALL                  18018
#define IDC_SWAPSTRG                    18019
#define IDC_TOGGLEFINDREPLACE           18020
#define IDC_BACKSLASHHELP               18021
#define IDC_REGEXPHELP                  18022
#define IDC_WILDCARDHELP                18023
#define IDS_FR_STATUS_TEXT              18024
#define IDC_TOGGLE_VISIBILITY           18025
#define IDC_OPENWITHDIR                 18026
#define IDC_GETOPENWITHDIR              18027
#define IDC_OPENWITHDESCR               18028
#define IDC_RESIZEGRIP                  18029
#define IDC_ENCODINGLIST                18030
#define IDC_USEASREADINGFALLBACK        18031
#define IDC_NOANSICPDETECTION           18032
#define IDC_NOUNICODEDETECTION          18033
#define IDC_ASCIIASUTF8                 18034
#define IDC_NFOASOEM                    18035
#define IDC_ENCODINGFROMFILEVARS        18036
#define IDC_EOLMODELIST                 18037
#define IDC_WARN_INCONSISTENT_EOLS      18038
#define IDC_CONSISTENT_EOLS             18039
// keep order (CRLF(0),  CR(1),  LF(2))
#define IDC_EOL_SUM_CRLF                18040
#define IDC_EOL_SUM_CR                  18041
#define IDC_EOL_SUM_LF                  18042
#define IDC_AUTOSTRIPBLANKS             18043
#define IDC_LINENUM                     18044
#define IDC_COLNUM                      18045
#define IDC_FILEMRU                     18046
#define IDC_PRESERVECARET               18047
#define IDC_SAVEMRU                     18048
#define IDC_REMOVE                      18049
#define IDC_REMEMBERSEARCHPATTERN       18050
#define IDC_STYLELIST                   18051
#define IDC_DEFAULTSCHEME               18052
#define IDC_AUTOSELECT                  18053
#define IDC_STYLELABEL_ROOT             18054
#define IDC_STYLEEDIT_ROOT              18055
#define IDC_STYLELABEL                  18056
#define IDC_STYLEFORE                   18057
#define IDC_STYLEBACK                   18058
#define IDC_STYLEFONT                   18059
#define IDC_PREVIEW                     18060
#define IDC_STYLEDEFAULT                18061
#define IDC_PREVSTYLE                   18062
#define IDC_NEXTSTYLE                   18063
#define IDC_IMPORT                      18064
#define IDC_EXPORT                      18065
#define IDC_TITLE                       18066
#define IDC_STYLEEDIT                   18067
#define IDC_PRINTER                     18068
#define IDC_FAVORITESDIR                18069
#define IDC_GETFAVORITESDIR             18070
#define IDC_FAVORITESDESCR              18071
#define IDC_PWD_EDIT1                   18072
#define IDC_PWD_EDIT2                   18073
#define IDC_PWD_EDIT3                   18074
#define IDC_PWD_CHECK1                  18075
#define IDC_PWD_CHECK2                  18076
#define IDC_PWD_CHECK3                  18077
#define IDC_PWD_CHECK4                  18078
#define IDC_PWD_STATMPW                 18079
#define IDC_COLUMNWRAP                  18080
#define IDC_INFOBOXTEXT                 18081
#define IDC_INFOBOXCHECK                18082
#define IDC_INFOBOXICON                 18083
#define IDC_VERSION                     18084
#define IDC_SCI_VERSION                 18085
#define IDC_COMPILER                    18086
#define IDC_COPYRIGHT                   18087
#define IDC_WEBPAGE2                    18088
#define IDC_WEBPAGE                     18089
#define IDR_RIZBITMAP                   18090
#define IDC_RIZONEBMP                   18091
#define IDC_COPYVERSTRG                 18092
#define IDC_RICHEDITABOUT               18093
#define IDC_TRANSL_AUTH                 18094
#define IDC_TRANSPARENT                 18095
#define IDC_TAB_WIDTH                   18096
#define IDC_INDENT_DEPTH                18097
#define IDC_TAB_AS_SPC                  18098
#define IDC_TAB_INDENTS                 18099
#define IDC_BACKTAB_INDENTS             18100
#define IDC_WARN_INCONSISTENT_INDENTS   18101
#define IDC_AUTO_DETECT_INDENTS         18102
#define IDC_CMDLINEHELP                 18103
#define IDC_STYLEEDIT_HELP              18104
#define IDC_RELIABLE_DETECTION_RES      18105
#define IDC_LINE_TEXT                   18106
#define IDC_COLUMN_TEXT                 18107
#define IDC_INDENT_WIDTH_TAB            18108
#define IDC_INDENT_WIDTH_SPC            18109
#define IDC_INDENT_SUM_TAB              18110
#define IDC_INDENT_SUM_SPC              18111
#define IDC_INDENT_SUM_MIX              18112
#define IDC_INDENT_BY_TABS              18113
#define IDC_INDENT_BY_SPCS              18114
#define IDC_INDENT_TAB_MODX             18115
#define IDC_INDENT_SPC_MODX             18116
#define IDC_ADDFAV_FILES                18117
#define IDC_INFO_GROUPBOX               18118
#define IDC_FIND_OVERLAPPING            18119
#define IDC_MULTIEDGELINE               18120
#define IDC_SHOWEDGELINE                18121
#define IDC_BACKGRDCOLOR                18122
#define IDC_CLEAR_LIST                  18123
#define IDC_FINDESCCTRLCHR              18124
#define IDC_REPLESCCTRLCHR              18125

#define IDC_RADIO_BTN_A                 18200
#define IDC_RADIO_BTN_B                 18201
#define IDC_RADIO_BTN_C                 18202
#define IDC_RADIO_BTN_D                 18203
#define IDC_RADIO_BTN_E                 18204
#define IDC_CHECK_BOX_A                 18251
#define IDC_CHECK_BOX_B                 18252
#define IDC_CHECK_BOX_C                 18253

#define CMD_ESCAPE                      20000
#define CMD_SHIFTESC                    20001
#define CMD_SHIFTCTRLENTER              20002
#define CMD_SCROLLUP                    20003
#define CMD_SCROLLDOWN                  20004
#define CMD_CTRLLEFT                    20005
#define CMD_CTRLRIGHT                   20006
#define CMD_DELETEBACK                  20007
#define CMD_CTRLBACK                    20008
#define CMD_CLEAR                       20009
#define CMD_CTRLDEL                     20010
#define CMD_CTRLTAB                     20011
#define CMD_RECODEDEFAULT               20012
#define CMD_RECODEANSI                  20013
#define CMD_RECODEOEM                   20014
#define CMD_RECODEGB18030               20015
#define CMD_RELOADASCIIASUTF8           20016
#define CMD_RELOADFORCEDETECTION        20017
#define CMD_RELOADNOFILEVARS            20018
#define CMD_LEXDEFAULT                  20019
#define CMD_LEXHTML                     20020
#define CMD_LEXXML                      20021
#define CMD_INSERT_TIMESTAMP            20022
#define CMD_UPDATE_TIMESTAMPS           20023
#define CMD_WEBACTION1                  20024
#define CMD_WEBACTION2                  20025
#define CMD_FINDNEXTSEL                 20026
#define CMD_FINDPREVSEL                 20027
#define CMD_INCLINELIMIT                20028
#define CMD_DECLINELIMIT                20029
#define CMD_STRINGIFY                   20030
#define CMD_STRINGIFY2                  20031
#define CMD_EMBRACE                     20032
#define CMD_EMBRACE2                    20033
#define CMD_EMBRACE3                    20034
#define CMD_EMBRACE4                    20035
#define CMD_INCREASENUM                 20036
#define CMD_DECREASENUM                 20037
#define CMD_TOGGLETITLE                 20038
#define CMD_JUMP2SELSTART               20039
#define CMD_JUMP2SELEND                 20040
#define CMD_COPYPATHNAME                20041
#define CMD_COPYWINPOS                  20042
#define CMD_INITIALWINPOS               20043
#define CMD_OPENINIFILE                 20044
#define CMD_INSERTNEWLINE               20045
#define CMD_OPEN_HYPERLINK              20046
#define CMD_FOLDJUMPUP                  20047
#define CMD_FOLDJUMPDOWN                20048
#define CMD_FOLDCOLLAPSE                20049
#define CMD_FOLDEXPAND                  20050
#define CMD_TAB                         20051
#define CMD_BACKTAB                     20052
#define CMD_VK_INSERT                   20053
#define CMD_FULLSCRWINPOS               20054
#define CMD_DEFAULTWINPOS               20055
#define CMD_SAVEASDEFWINPOS             20056
#define CMD_CLEARSAVEDWINPOS            20057
#define CMD_CHECK_INDENTATION           20058
#define CMD_ARROW_UP                    20059
#define CMD_ARROW_DOWN                  20060
#define CMD_ENTER_RETURN                20061

#define IDS_MUI_MENU_LANGUAGE           34500
#define IDS_MUI_LANG_EN_US              34501
#define IDS_MUI_LANG_AF_ZA              34502
#define IDS_MUI_LANG_BE_BY              34503
#define IDS_MUI_LANG_DE_DE              34504
#define IDS_MUI_LANG_EL_GR              34505
#define IDS_MUI_LANG_EN_GB              34506
#define IDS_MUI_LANG_ES_419             34507
#define IDS_MUI_LANG_ES_ES              34508
#define IDS_MUI_LANG_FR_FR              34509
#define IDS_MUI_LANG_HI_IN              34510
#define IDS_MUI_LANG_HU_HU              34511
#define IDS_MUI_LANG_ID_ID              34512
#define IDS_MUI_LANG_IT_IT              34513
#define IDS_MUI_LANG_JP_JP              34514
#define IDS_MUI_LANG_KO_KR              34515
#define IDS_MUI_LANG_NL_NL              34516
#define IDS_MUI_LANG_PL_PL              34517
#define IDS_MUI_LANG_PT_BR              34518
#define IDS_MUI_LANG_PT_PT              34519
#define IDS_MUI_LANG_RU_RU              34520
#define IDS_MUI_LANG_SK_SK              34521
#define IDS_MUI_LANG_SV_SE              34522
#define IDS_MUI_LANG_TR_TR              34523
#define IDS_MUI_LANG_VI_VN              34524
#define IDS_MUI_LANG_ZH_CN              34525
#define IDS_MUI_LANG_ZH_TW              34526
#define IDS_USE_LOCALE_DATEFMT          34700

#define IDS_MUI_MENU_THEMES             37000
#define IDM_THEMES_DEFAULT              37001
#define IDM_THEMES_FILE_ITEM            37002
/// !!! dont use IDs until           ...37100

#define IDM_FILE_NEW                    40000
#define IDM_FILE_OPEN                   40001
#define IDM_FILE_REVERT                 40002
#define IDM_FILE_BROWSE                 40003
#define IDM_GREP_WIN_SEARCH             40004
#define IDM_FILE_SAVE                   40005
#define IDM_FILE_SAVEAS                 40006
#define IDM_FILE_SAVECOPY               40007
#define IDM_FILE_READONLY               40008
#define IDM_FILE_LAUNCH                 40009
#define IDM_FILE_LAUNCH_ELEVATED        40010
#define IDM_FILE_EXPLORE_DIR            40011
#define IDM_FILE_OPENWITH               40012
#define IDM_FILE_RUN                    40013
#define IDM_FILE_NEWWINDOW              40014
#define IDM_FILE_NEWWINDOW2             40015
#define IDM_FILE_PAGESETUP              40016
#define IDM_FILE_PRINT                  40017
#define IDM_FILE_PROPERTIES             40018
#define IDM_FILE_CREATELINK             40019
#define IDM_FILE_OPENFAV                40020
#define IDM_FILE_ADDTOFAV               40021
#define IDM_FILE_MANAGEFAV              40022
#define IDM_FILE_RECENT                 40023
#define IDM_FILE_EXIT                   40024
#define IDM_FILE_PRESERVE_FILEMODTIME   40025
#define IDM_FILE_LOCK_SHARE_READ        40026

#define IDM_ENCODING_ANSI               40100
#define IDM_ENCODING_UNICODE            40101
#define IDM_ENCODING_UNICODEREV         40102
#define IDM_ENCODING_UTF8               40103
#define IDM_ENCODING_UTF8SIGN           40104
#define IDM_ENCODING_SELECT             40105
#define IDM_ENCODING_RECODE             40106
#define IDM_ENCODING_SETDEFAULT         40107
#define IDM_LINEENDINGS_CRLF            40200
#define IDM_LINEENDINGS_CR              40201
#define IDM_LINEENDINGS_LF              40202
#define IDM_LINEENDINGS_SETDEFAULT      40203
#define IDM_EDIT_BOOKMARKTOGGLE         40250
#define IDM_EDIT_BOOKMARKNEXT           40251
#define IDM_EDIT_BOOKMARKCLEAR          40252
#define IDM_EDIT_BOOKMARKPREV           40253
#define BME_EDIT_BOOKMARKTOGGLE         40254
#define BME_EDIT_BOOKMARKNEXT           40255
#define BME_EDIT_BOOKMARKCLEAR          40256
#define BME_EDIT_BOOKMARKPREV           40257

#define IDM_EDIT_UNDO                   40300
#define IDM_EDIT_REDO                   40301
#define IDM_EDIT_CUT                    40302
#define IDM_EDIT_COPY                   40303
#define IDM_EDIT_COPYALL                40304
#define IDM_EDIT_COPYADD                40305
#define IDM_EDIT_PASTE                  40306
#define IDM_EDIT_SWAP                   40307
#define IDM_EDIT_CLEAR                  40308
#define IDM_EDIT_CLEARCLIPBOARD         40309
#define IDM_EDIT_SELECTALL              40310
#define IDM_EDIT_SELECTWORD             40311
#define IDM_EDIT_SELECTALLMATCHES       40312
#define IDM_EDIT_MOVELINEUP             40313
#define IDM_EDIT_MOVELINEDOWN           40314
#define IDM_EDIT_DUPLINEORSELECTION     40315
#define IDM_EDIT_LINETRANSPOSE          40316
#define IDM_EDIT_CUTLINE                40317
#define IDM_EDIT_COPYLINE               40318
#define IDM_EDIT_DELETELINE             40319
#define IDM_EDIT_DELETELINELEFT         40320
#define IDM_EDIT_DELETELINERIGHT        40321
#define IDM_EDIT_COLUMNWRAP             40322
#define IDM_EDIT_SPLITLINES             40323
#define IDM_EDIT_JOINLINES              40324
#define IDM_EDIT_JOINLINES_PARA         40325
#define IDM_EDIT_INDENT                 40326
#define IDM_EDIT_UNINDENT               40327
#define IDM_EDIT_ENCLOSESELECTION       40328
#define IDM_EDIT_PADWITHSPACES          40329
#define IDM_EDIT_STRIP1STCHAR           40330
#define IDM_EDIT_STRIPLASTCHAR          40331
#define IDM_EDIT_TRIMLINES              40332
#define IDM_EDIT_COMPRESS_BLANKS        40333
#define IDM_EDIT_MERGEBLANKLINES        40334
#define IDM_EDIT_REMOVEBLANKLINES       40335
#define IDM_EDIT_MODIFYLINES            40336
#define IDM_EDIT_SORTLINES              40337
#define IDM_EDIT_ALIGN                  40338
#define IDM_EDIT_CONVERTUPPERCASE       40339
#define IDM_EDIT_CONVERTLOWERCASE       40340
#define IDM_EDIT_INVERTCASE             40341
#define IDM_EDIT_TITLECASE              40342
#define IDM_EDIT_SENTENCECASE           40343
#define IDM_EDIT_CONVERTTABS            40344
#define IDM_EDIT_CONVERTSPACES          40345
#define IDM_EDIT_CONVERTTABS2           40346
#define IDM_EDIT_CONVERTSPACES2         40347
#define IDM_EDIT_INSERT_TAG             40348
#define IDM_EDIT_INSERT_ENCODING        40349
#define IDM_EDIT_INSERT_SHORTDATE       40350
#define IDM_EDIT_INSERT_LONGDATE        40351
#define IDM_EDIT_INSERT_FILENAME        40352
#define IDM_EDIT_INSERT_DIRNAME         40353
#define IDM_EDIT_INSERT_PATHNAME        40354
#define IDM_EDIT_LINECOMMENT            40355
#define IDM_EDIT_LINECOMMENT_BLOCKEDIT  40356
#define IDM_EDIT_STREAMCOMMENT          40357
#define IDM_EDIT_URLENCODE              40358
#define IDM_EDIT_URLDECODE              40359
#define IDM_EDIT_URL2PATH               40360
#define IDM_EDIT_PATH2URL               40361
#define IDM_EDIT_INVERTSLASH            40362
#define IDM_EDIT_INVERTBACKSLASH        40363
#define IDM_EDIT_ESCAPECCHARS           40364
#define IDM_EDIT_UNESCAPECCHARS         40365
#define IDM_EDIT_CHAR2HEX               40366
#define IDM_EDIT_HEX2CHAR               40367
#define IDM_EDIT_FINDMATCHINGBRACE      40368
#define IDM_EDIT_SELTOMATCHINGBRACE     40369
#define IDM_EDIT_FIND                   40370
#define IDM_EDIT_SAVEFIND               40371
#define IDM_EDIT_FINDNEXT               40372
#define IDM_EDIT_FINDPREV               40373
#define IDM_EDIT_REPLACE                40374
#define IDM_EDIT_REPLACENEXT            40375
#define IDM_EDIT_GOTOLINE               40376
#define IDM_EDIT_SELTONEXT              40377
#define IDM_EDIT_SELTOPREV              40378
#define IDM_EDIT_COMPLETEWORD           40379
#define IDM_EDIT_JOINLN_NOSP            40380
#define IDM_EDIT_REMOVEDUPLICATELINES   40381
#define IDM_EDIT_REMOVEEMPTYLINES       40382
#define IDM_EDIT_MERGEEMPTYLINES        40383
#define IDM_EDIT_CLEAR_MARKER           40384
#define IDM_EDIT_CUT_MARKED             40385
#define IDM_EDIT_COPY_MARKED            40386
#define IDM_EDIT_DELETE_MARKED          40387

#define IDM_VIEW_SCHEME                 40400
#define IDM_VIEW_USE2NDDEFAULT          40401
#define IDM_VIEW_SCHEMECONFIG           40402
#define IDM_VIEW_FONT                   40403
#define IDM_VIEW_WORDWRAP               40404
#define IDM_VIEW_LONGLINEMARKER         40405
#define IDM_VIEW_SHOWINDENTGUIDES       40406
#define IDM_VIEW_SHOWBLANKS             40407
#define IDM_VIEW_SHOWEOLS               40408
#define IDM_VIEW_WORDWRAPSYMBOLS        40409
#define IDM_VIEW_MATCHBRACES            40410
#define IDM_VIEW_TOGGLE_HILITCURLN      40411
#define IDM_VIEW_HILITCURLN_NONE        40412
#define IDM_VIEW_HILITCURLN_BACK        40413
#define IDM_VIEW_HILITCURLN_FRAME       40414
#define IDM_VIEW_LINENUMBERS            40415
#define IDM_VIEW_BOOKMARK_MARGIN        40416
#define IDM_VIEW_ZOOMIN                 40417
#define IDM_VIEW_ZOOMOUT                40418
#define IDM_VIEW_RESETZOOM              40419
#define IDM_VIEW_TABSASSPACES           40420
#define IDM_VIEW_TABSETTINGS            40421
#define IDM_VIEW_WORDWRAPSETTINGS       40422
#define IDM_VIEW_LONGLINESETTINGS       40423
#define IDM_VIEW_AUTOINDENTTEXT         40424
#define IDM_VIEW_AUTOCLOSETAGS          40425
#define IDM_VIEW_REUSEWINDOW            40426
#define IDM_VIEW_STICKYWINPOS           40427
#define IDM_VIEW_ALWAYSONTOP            40428
#define IDM_VIEW_MINTOTRAY              40429
#define IDM_VIEW_TRANSPARENT            40430
#define IDM_VIEW_SINGLEFILEINSTANCE     40431
#define IDM_VIEW_CHANGENOTIFY           40432
#define IDM_VIEW_SHOWFILENAMEONLY       40433
#define IDM_VIEW_SHOWFILENAMEFIRST      40434
#define IDM_VIEW_SHOWFULLPATH           40435
#define IDM_VIEW_SHOWEXCERPT            40436
#define IDM_VIEW_NOESCFUNC              40437
#define IDM_VIEW_ESCMINIMIZE            40438
#define IDM_VIEW_ESCEXIT                40439
#define IDM_VIEW_SAVEBEFORERUNNINGTOOLS 40440
#define IDM_VIEW_NOSAVERECENT           40441
#define IDM_VIEW_NOSAVEFINDREPL         40442
#define IDM_VIEW_MENUBAR                40443
#define IDM_VIEW_TOOLBAR                40444
#define IDM_VIEW_CUSTOMIZETB            40445
#define IDM_VIEW_LOADTHEMETB            40446
#define IDM_VIEW_DPISCALETB             40447
#define IDM_VIEW_STATUSBAR              40448
#define IDM_VIEW_SAVESETTINGS           40449
#define IDM_VIEW_SAVESETTINGSNOW        40450
#define IDM_VIEW_FOLDING                40451
#define IDM_VIEW_TOGGLEFOLDS            40452
#define IDM_VIEW_TOGGLE_CURRENT_FOLD    40453
#define IDM_VIEW_MARKOCCUR_ONOFF        40454
#define IDM_VIEW_MARKOCCUR_BOOKMARKS    40455
#define IDM_VIEW_MARKOCCUR_CASE         40456
#define IDM_VIEW_MARKOCCUR_WNONE        40457
#define IDM_VIEW_MARKOCCUR_WORD         40458
#define IDM_VIEW_MARKOCCUR_CURRENT      40459
#define IDM_VIEW_MARKOCCUR_VISIBLE      40460
#define IDM_VIEW_AUTOCOMPLETEWORDS      40461
#define IDM_VIEW_AUTOCLEXKEYWORDS       40462
#define IDM_VIEW_ACCELWORDNAV           40463
#define IDM_VIEW_NOPRESERVECARET        40464
#define IDM_VIEW_HYPERLINKHOTSPOTS      40465
#define IDM_VIEW_COLORDEFHOTSPOTS       40466
#define IDM_VIEW_COLOR_ARGB             40467
#define IDM_VIEW_COLOR_RGBA             40468
#define IDM_VIEW_COLOR_BGRA             40469
#define IDM_VIEW_CURRENTSCHEME          40470
#define IDM_VIEW_SCROLLPASTEOF          40471
#define IDM_VIEW_TOGGLE_VIEW            40472
#define IDM_VIEW_FV_FOLD                40473
#define IDM_VIEW_FV_BOOKMARK            40474
#define IDM_VIEW_FV_HIGHLIGHT           40475
#define IDM_VIEW_FV_BKMRKFOLD           40476
#define IDM_VIEW_FV_HIGHLGFOLD          40477
#define IDM_VIEW_CHASING_DOCTAIL        40478
#define IDM_VIEW_TOGGLETB               40479
#define IDM_VIEW_MUTE_MESSAGEBEEP       40480
#define IDM_VIEW_SHOW_HYPLNK_CALLTIP    40481
#define IDM_VIEW_SPLIT_UNDOTYPSEQ_LNBRK 40482
#define IDM_VIEW_EVALTINYEXPRONSEL      40483
#define IDM_VIEW_UNICODE_POINTS         40484
#define IDM_VIEW_WIN_DARK_MODE          40485

// keep Scintilla(SC) order
#define IDM_SET_RENDER_TECH_GDI         40500   // SC_TECHNOLOGY_DEFAULT(0)
#define IDM_SET_RENDER_TECH_D2D         40501   // SC_TECHNOLOGY_DIRECTWRITE(1)
#define IDM_SET_RENDER_TECH_D2DRETAIN   40502   // SC_TECHNOLOGY_DIRECTWRITERETAIN(2)
#define IDM_SET_RENDER_TECH_D2DDC       40503   // SC_TECHNOLOGY_DIRECTWRITEDC(3)
#define IDM_SET_RTL_LAYOUT_EDIT         40504
#define IDM_SET_RTL_LAYOUT_DLG          40505
// keep Scintilla(SC) order 
#define IDM_SET_BIDIRECTIONAL_NONE      40506   // SC_BIDIRECTIONAL_DISABLED(0)
#define IDM_SET_BIDIRECTIONAL_L2R       40507   // SC_BIDIRECTIONAL_L2R(1)
#define IDM_SET_BIDIRECTIONAL_R2L       40508   // SC_BIDIRECTIONAL_R2L(2)

#define IDM_HELP_ABOUT                  40600
#define IDM_HELP_CMD                    40601
#define IDM_HELP_ONLINEDOCUMENTATION    40602
#define IDM_HELP_ADMINEXE               40603
#define IDM_HELP_UPDATEWEBSITE          40604

#define IDM_TRAY_RESTORE                40700
#define IDM_TRAY_EXIT                   40701
#define IDM_SETPASS                     40702
#define IDM_EDIT_INSERT_GUID            40705


#define IDS_ENC_ANSI                    61000
#define IDS_ENC_OEM                     61001
#define IDS_ENC_UTF16LEBOM              61002
#define IDS_ENC_UTF16BEBOM              61003
#define IDS_ENC_UTF16LE                 61004
#define IDS_ENC_UTF16BE                 61005
#define IDS_ENC_UTF8                    61006
#define IDS_ENC_UTF8SIG                 61007
#define IDS_ENC_UTF7                    61008
#define IDS_ENC_DOS_720                 61009
#define IDS_ENC_ISO_8859_6              61010
#define IDS_ENC_MAC_ARABIC              61011
#define IDS_ENC_WIN_1256                61012
#define IDS_ENC_DOS_775                 61013
#define IDS_ENC_ISO_8859_4              61014
#define IDS_ENC_WIN_1257                61015
#define IDS_ENC_DOS_852                 61016
#define IDS_ENC_ISO_8859_2              61017
#define IDS_ENC_MAC_CENTRAL_EUROP       61018
#define IDS_ENC_WIN_1250                61019
#define IDS_ENC_GB18030                 61020
#define IDS_ENC_GBK_936                 61021
#define IDS_ENC_GB2312_80               61022
#define IDS_ENC_MAC_ZH_CN               61023
#define IDS_ENC_BIG5                    61024
#define IDS_ENC_MAC_ZH_TW               61025
#define IDS_ENC_MAC_CROATIAN            61026
#define IDS_ENC_DOS_866                 61027
#define IDS_ENC_ISO_8859_5              61028
#define IDS_ENC_KOI8_R                  61029
#define IDS_ENC_KOI8_U                  61030
#define IDS_ENC_MAC_CYRILLIC            61031
#define IDS_ENC_WIN_1251                61032
#define IDS_ENC_ISO_8859_13             61033
#define IDS_ENC_DOS_863                 61034
#define IDS_ENC_DOS_737                 61035
#define IDS_ENC_ISO_8859_7              61036
#define IDS_ENC_MAC_GREEK               61037
#define IDS_ENC_WIN_1253                61038
#define IDS_ENC_DOS_869                 61039
#define IDS_ENC_DOS_862                 61040
#define IDS_ENC_ISO_8859_8_I            61041
#define IDS_ENC_ISO_8859_8              61042
#define IDS_ENC_MAC_HEBREW              61043
#define IDS_ENC_WIN_1255                61044
#define IDS_ENC_DOS_861                 61045
#define IDS_ENC_MAC_ICELANDIC           61046
#define IDS_ENC_MAC_JAPANESE            61047
#define IDS_ENC_SHIFT_JIS               61048
#define IDS_ENC_MAC_KOREAN              61049
#define IDS_ENC_WIN_949                 61050
#define IDS_ENC_ISO_8859_3              61051
#define IDS_ENC_ISO_8859_15             61052
#define IDS_ENC_DOS_865                 61053
#define IDS_ENC_DOS_437                 61054
#define IDS_ENC_DOS_858                 61055
#define IDS_ENC_DOS_860                 61056
#define IDS_ENC_MAC_ROMANIAN            61057
#define IDS_ENC_MAC_THAI                61058
#define IDS_ENC_WIN_874                 61059
#define IDS_ENC_DOS_857                 61060
#define IDS_ENC_ISO_8859_9              61061
#define IDS_ENC_MAC_TURKISH             61062
#define IDS_ENC_WIN_1254                61063
#define IDS_ENC_MAC_UKRAINIAN           61064
#define IDS_ENC_WIN_1258                61065
#define IDS_ENC_DOS_850                 61066
#define IDS_ENC_ISO_8859_1              61067
#define IDS_ENC_MAC_WESTERN_EUROP       61068
#define IDS_ENC_WIN_1252                61069
#define IDS_ENC_IBM_EBCDIC_US           61070
#define IDS_ENC_IBM_EBCDIC_INT          61071
#define IDS_ENC_IBM_EBCDIC_GR           61072
#define IDS_ENC_IBM_EBCDIC_LAT_5        61073
#define IDS_ENC_EUC_JAPANESE            61074
#define IDS_ENC_EUC_KOREAN              61075
#define IDS_ENC_ISO_2022_CN             61076
#define IDS_ENC_HZ_GB2312               61077
#define IDS_ENC_ISO_2022_JP             61078
#define IDS_ENC_ISO_2022_KR             61079
#define IDS_ENC_X_CHINESE_CNS           61080
#define IDS_ENC_JOHAB                   61081
#define IDS_ENC_ISO_8859_10             61082
#define IDS_ENC_BIG5_HKSCS              61083

#define IDS_EOL_WIN                     62000
#define IDS_EOL_MAC                     62001
#define IDS_EOL_UNIX                    62002

#define IDS_LEX_DEF_TXT                 63000
#define IDS_LEX_WEB_SRC                 63001
#define IDS_LEX_XML_DOC                 63002
#define IDS_LEX_CSS_STYLE               63003
#define IDS_LEX_CPP_SRC                 63004
#define IDS_LEX_CSHARP_SRC              63005
#define IDS_LEX_RESOURCE_SCR            63006
#define IDS_LEX_MAKEFILES               63007
#define IDS_LEX_VB_SCR                  63008
#define IDS_LEX_VIS_BAS                 63009
#define IDS_LEX_J_SCR                   63010
#define IDS_LEX_JAVA_SRC                63011
#define IDS_LEX_PASCAL_SRC              63012
#define IDS_LEX_ASM_SCR                 63013
#define IDS_LEX_PERL_SCR                63014
#define IDS_LEX_CONF                    63015
#define IDS_LEX_BATCH                   63016
#define IDS_LEX_DIFF                    63017
#define IDS_LEX_SQL                     63018
#define IDS_LEX_PYTHON                  63019
#define IDS_LEX_APC_CFG                 63020
#define IDS_LEX_PWRSHELL                63021
#define IDS_LEX_D_SRC                   63022
#define IDS_LEX_GO_SRC                  63023
#define IDS_LEX_AWK_SCR                 63024
#define IDS_LEX_ANSI_ART                63025
#define IDS_LEX_SHELL_SCR               63026
#define IDS_LEX_REG_FILES               63027
#define IDS_LEX_VHDL                    63028
#define IDS_LEX_JSON                    63029
#define IDS_LEX_NSIS                    63030
#define IDS_LEX_INNO                    63031
#define IDS_LEX_RUBY                    63032
#define IDS_LEX_LUA                     63033
#define IDS_LEX_TCL                     63034
#define IDS_LEX_AUTOIT3                 63035
#define IDS_LEX_LATEX                   63036
#define IDS_LEX_AHK                     63037
#define IDS_LEX_CMAKE                   63038
#define IDS_LEX_AVI_SYNTH               63039
#define IDS_LEX_MARKDOWN                63040
#define IDS_LEX_YAML                    63041
#define IDS_LEX_COFFEE_SCR              63042
#define IDS_LEX_MATLAB                  63043
#define IDS_LEX_NIM_SRC                 63044
#define IDS_LEX_R_STAT                  63045
#define IDS_LEX_RUST_SRC                63046
#define IDS_LEX_AHKL                    63047
#define IDS_LEX_TEXT_FILES              63048
#define IDS_LEX_TOML_CFG                63049
#define IDS_LEX_PRISM_CSV               63050
#define IDS_LEX_DART_SRC                63051
#define IDS_LEX_KOTLIN_SRC              63052

#define IDS_LEX_STD_STYLE               63100
#define IDS_LEX_STD_MARGIN              63101
#define IDS_LEX_STD_BRACE               63102
#define IDS_LEX_STD_BRACE_FAIL          63103
#define IDS_LEX_STD_CTRL_CHAR           63104
#define IDS_LEX_STD_INDENT              63105
#define IDS_LEX_STD_SEL                 63106
#define IDS_LEX_STD_WSPC                63107
#define IDS_LEX_STD_LN_BACKGR           63108
#define IDS_LEX_STD_CARET               63109
#define IDS_LEX_STD_LONG_LN             63110
#define IDS_LEX_STD_X_SPC               63111
#define IDS_LEX_2ND_STYLE               63112
#define IDS_LEX_2ND_MARGIN              63113
#define IDS_LEX_2ND_BRACE               63114
#define IDS_LEX_2ND_BRACE_FAIL          63115
#define IDS_LEX_2ND_CTRL_CHAR           63116
#define IDS_LEX_2ND_INDENT              63117
#define IDS_LEX_2ND_SEL                 63118
#define IDS_LEX_2ND_WSPC                63119
#define IDS_LEX_2ND_LN_BACKGR           63120
#define IDS_LEX_2ND_CARET               63121
#define IDS_LEX_2ND_LONG_LN             63122
#define IDS_LEX_2ND_X_SPC               63123
#define IDS_LEX_STD_BKMRK               63124
#define IDS_LEX_2ND_BKMRK               63125

#define IDS_LEX_STR_63126               63126
#define IDS_LEX_STR_63127               63127
#define IDS_LEX_STR_63128               63128
#define IDS_LEX_STR_63129               63129
#define IDS_LEX_STR_63130               63130
#define IDS_LEX_STR_63131               63131
#define IDS_LEX_STR_63132               63132
#define IDS_LEX_STR_63133               63133
#define IDS_LEX_STR_63134               63134
#define IDS_LEX_STR_63135               63135
#define IDS_LEX_STR_63136               63136
#define IDS_LEX_STR_63137               63137
#define IDS_LEX_STR_63138               63138
#define IDS_LEX_STR_63139               63139
#define IDS_LEX_STR_63140               63140
#define IDS_LEX_STR_63141               63141
#define IDS_LEX_STR_63142               63142
#define IDS_LEX_STR_63143               63143
#define IDS_LEX_STR_63144               63144
#define IDS_LEX_STR_63145               63145
#define IDS_LEX_STR_63146               63146
#define IDS_LEX_STR_63147               63147
#define IDS_LEX_STR_63148               63148
#define IDS_LEX_STR_63149               63149
#define IDS_LEX_STR_63150               63150
#define IDS_LEX_STR_63151               63151
#define IDS_LEX_STR_63152               63152
#define IDS_LEX_STR_63153               63153
#define IDS_LEX_STR_63154               63154
#define IDS_LEX_STR_63155               63155
#define IDS_LEX_STR_63156               63156
#define IDS_LEX_STR_63157               63157
#define IDS_LEX_STR_63158               63158
#define IDS_LEX_STR_63159               63159
#define IDS_LEX_STR_63160               63160
#define IDS_LEX_STR_63161               63161
#define IDS_LEX_STR_63162               63162
#define IDS_LEX_STR_63163               63163
#define IDS_LEX_STR_63164               63164
#define IDS_LEX_STR_63165               63165
#define IDS_LEX_STR_63166               63166
#define IDS_LEX_STR_63167               63167
#define IDS_LEX_STR_63168               63168
#define IDS_LEX_STR_63169               63169
#define IDS_LEX_STR_63170               63170
#define IDS_LEX_STR_63171               63171
#define IDS_LEX_STR_63172               63172
#define IDS_LEX_STR_63173               63173
#define IDS_LEX_STR_63174               63174
#define IDS_LEX_STR_63175               63175
#define IDS_LEX_STR_63176               63176
#define IDS_LEX_STR_63177               63177
#define IDS_LEX_STR_63178               63178
#define IDS_LEX_STR_63179               63179
#define IDS_LEX_STR_63180               63180
#define IDS_LEX_STR_63181               63181
#define IDS_LEX_STR_63182               63182
#define IDS_LEX_STR_63183               63183
#define IDS_LEX_STR_63184               63184
#define IDS_LEX_STR_63185               63185
#define IDS_LEX_STR_63186               63186
#define IDS_LEX_STR_63187               63187
#define IDS_LEX_STR_63188               63188
#define IDS_LEX_STR_63189               63189
#define IDS_LEX_STR_63190               63190
#define IDS_LEX_STR_63191               63191
#define IDS_LEX_STR_63192               63192
#define IDS_LEX_STR_63193               63193
#define IDS_LEX_STR_63194               63194
#define IDS_LEX_STR_63195               63195
#define IDS_LEX_STR_63196               63196
#define IDS_LEX_STR_63197               63197
#define IDS_LEX_STR_63198               63198
#define IDS_LEX_STR_63199               63199
#define IDS_LEX_STR_63200               63200
#define IDS_LEX_STR_63201               63201
#define IDS_LEX_STR_63202               63202
#define IDS_LEX_STR_63203               63203
#define IDS_LEX_STR_63204               63204
#define IDS_LEX_STR_63205               63205
#define IDS_LEX_STR_63206               63206
#define IDS_LEX_STR_63207               63207
#define IDS_LEX_STR_63208               63208
#define IDS_LEX_STR_63209               63209
#define IDS_LEX_STR_63210               63210
#define IDS_LEX_STR_63211               63211
#define IDS_LEX_STR_63212               63212
#define IDS_LEX_STR_63213               63213
#define IDS_LEX_STR_63214               63214
#define IDS_LEX_STR_63215               63215
#define IDS_LEX_STR_63216               63216
#define IDS_LEX_STR_63217               63217
#define IDS_LEX_STR_63218               63218
#define IDS_LEX_STR_63219               63219
#define IDS_LEX_STR_63220               63220
#define IDS_LEX_STR_63221               63221
#define IDS_LEX_STR_63222               63222
#define IDS_LEX_STR_63223               63223
#define IDS_LEX_STR_63224               63224
#define IDS_LEX_STR_63225               63225
#define IDS_LEX_STR_63226               63226
#define IDS_LEX_STR_63227               63227
#define IDS_LEX_STR_63228               63228
#define IDS_LEX_STR_63229               63229
#define IDS_LEX_STR_63230               63230
#define IDS_LEX_STR_63231               63231
#define IDS_LEX_STR_63232               63232
#define IDS_LEX_STR_63233               63233
#define IDS_LEX_STR_63234               63234
#define IDS_LEX_STR_63235               63235
#define IDS_LEX_STR_63236               63236
#define IDS_LEX_STR_63237               63237
#define IDS_LEX_STR_63238               63238
#define IDS_LEX_STR_63239               63239
#define IDS_LEX_STR_63240               63240
#define IDS_LEX_STR_63241               63241
#define IDS_LEX_STR_63242               63242
#define IDS_LEX_STR_63243               63243
#define IDS_LEX_STR_63244               63244
#define IDS_LEX_STR_63245               63245
#define IDS_LEX_STR_63246               63246
#define IDS_LEX_STR_63247               63247
#define IDS_LEX_STR_63248               63248
#define IDS_LEX_STR_63249               63249
#define IDS_LEX_STR_63250               63250
#define IDS_LEX_STR_63251               63251
#define IDS_LEX_STR_63252               63252
#define IDS_LEX_STR_63253               63253
#define IDS_LEX_STR_63254               63254
#define IDS_LEX_STR_63255               63255
#define IDS_LEX_STR_63256               63256
#define IDS_LEX_STR_63257               63257
#define IDS_LEX_STR_63258               63258
#define IDS_LEX_STR_63259               63259
#define IDS_LEX_STR_63260               63260
#define IDS_LEX_STR_63261               63261
#define IDS_LEX_STR_63262               63262
#define IDS_LEX_STR_63263               63263
#define IDS_LEX_STR_63264               63264
#define IDS_LEX_STR_63265               63265
#define IDS_LEX_STR_63266               63266
#define IDS_LEX_STR_63267               63267
#define IDS_LEX_STR_63268               63268
#define IDS_LEX_STR_63269               63269
#define IDS_LEX_STR_63270               63270
#define IDS_LEX_STR_63271               63271
#define IDS_LEX_STR_63272               63272
#define IDS_LEX_STR_63273               63273
#define IDS_LEX_STR_63274               63274
#define IDS_LEX_STR_63275               63275
#define IDS_LEX_STR_63276               63276
#define IDS_LEX_STR_63277               63277
#define IDS_LEX_STR_63278               63278
#define IDS_LEX_STR_63279               63279
#define IDS_LEX_STR_63280               63280
#define IDS_LEX_STR_63281               63281
#define IDS_LEX_STR_63282               63282
#define IDS_LEX_STR_63283               63283
#define IDS_LEX_STR_63284               63284
#define IDS_LEX_STR_63285               63285
#define IDS_LEX_STR_63286               63286
#define IDS_LEX_STR_63287               63287
#define IDS_LEX_STR_63288               63288
#define IDS_LEX_STR_63289               63289
#define IDS_LEX_STR_63290               63290
#define IDS_LEX_STR_63291               63291
#define IDS_LEX_STR_63292               63292
#define IDS_LEX_STR_63293               63293
#define IDS_LEX_STR_63294               63294
#define IDS_LEX_STR_63295               63295
#define IDS_LEX_STR_63296               63296
#define IDS_LEX_STR_63297               63297
#define IDS_LEX_STR_63298               63298
#define IDS_LEX_STR_63299               63299
#define IDS_LEX_STR_63300               63300
#define IDS_LEX_STR_63301               63301
#define IDS_LEX_STR_63302               63302
#define IDS_LEX_STR_63303               63303
#define IDS_LEX_STR_63304               63304
#define IDS_LEX_STR_63305               63305
#define IDS_LEX_STR_63306               63306
#define IDS_LEX_STR_63307               63307
#define IDS_LEX_STR_63308               63308
#define IDS_LEX_STR_63309               63309
#define IDS_LEX_STR_63310               63310
#define IDS_LEX_STR_63311               63311
#define IDS_LEX_STR_63312               63312
#define IDS_LEX_STR_63313               63313
#define IDS_LEX_STR_63314               63314
#define IDS_LEX_STR_63315               63315
#define IDS_LEX_STR_63316               63316
#define IDS_LEX_STR_63317               63317
#define IDS_LEX_STR_63318               63318
#define IDS_LEX_STR_63319               63319
#define IDS_LEX_STR_63320               63320
#define IDS_LEX_STR_63321               63321
#define IDS_LEX_STR_63322               63322
#define IDS_LEX_STR_63323               63323
#define IDS_LEX_STR_63324               63324
#define IDS_LEX_STR_63325               63325
#define IDS_LEX_STR_63326               63326
#define IDS_LEX_STR_63327               63327
#define IDS_LEX_STR_63328               63328
#define IDS_LEX_STR_63329               63329
#define IDS_LEX_STR_63330               63330
#define IDS_LEX_STR_63331               63331
#define IDS_LEX_STR_63332               63332
#define IDS_LEX_STR_63333               63333
#define IDS_LEX_STR_63334               63334
#define IDS_LEX_STR_63335               63335
#define IDS_LEX_STR_63336               63336
#define IDS_LEX_STR_63337               63337
#define IDS_LEX_STR_63338               63338
#define IDS_LEX_STR_63339               63339
#define IDS_LEX_STR_63340               63340
#define IDS_LEX_STR_63341               63341
#define IDS_LEX_STR_63342               63342
#define IDS_LEX_STR_63343               63343
#define IDS_LEX_STR_63344               63344
#define IDS_LEX_STR_63345               63345
#define IDS_LEX_STR_63346               63346
#define IDS_LEX_STR_63347               63347
#define IDS_LEX_STR_63348               63348
#define IDS_LEX_STR_63349               63349
#define IDS_LEX_STR_63350               63350
#define IDS_LEX_STR_63351               63351
#define IDS_LEX_STR_63352               63352
#define IDS_LEX_STR_63353               63353
#define IDS_LEX_STR_63354               63354
#define IDS_LEX_STR_63355               63355
#define IDS_LEX_STR_63356               63356
#define IDS_LEX_STR_63357               63357
#define IDS_LEX_STR_63358               63358
#define IDS_LEX_STR_63359               63359
#define IDS_LEX_STR_63360               63360
#define IDS_LEX_STR_63361               63361
#define IDS_LEX_STR_63362               63362
#define IDS_LEX_STR_63363               63363
#define IDS_LEX_STR_63364               63364
#define IDS_LEX_STR_63365               63365
#define IDS_LEX_STR_63366               63366
#define IDS_LEX_STR_63367               63367
#define IDS_LEX_STR_63368               63368
#define IDS_LEX_STR_63369               63369
#define IDS_LEX_STR_63370               63370
#define IDS_LEX_STR_63371               63371
#define IDS_LEX_STR_63372               63372
#define IDS_LEX_STR_63373               63373
#define IDS_LEX_STR_63374               63374

#define IDS_LEX_CSV_COL_0               63400
#define IDS_LEX_CSV_COL_1               63401
#define IDS_LEX_CSV_COL_2               63402
#define IDS_LEX_CSV_COL_3               63403
#define IDS_LEX_CSV_COL_4               63404
#define IDS_LEX_CSV_COL_5               63405
#define IDS_LEX_CSV_COL_6               63406
#define IDS_LEX_CSV_COL_7               63407
#define IDS_LEX_CSV_COL_8               63408
#define IDS_LEX_CSV_COL_9               63409

#define RICHEDIT_CONTROL_VER            "RichEdit50W"  // RICHEDIT_CONTROL_VER

#ifndef ES_EX_ZOOMABLE
#define ES_EX_ZOOMABLE                  0x0010L
#endif

#ifndef RICHEDTCTRL_ADDSTYLE
#define RICHEDTCTRL_ADDSTYLE            0x29c4
#endif

//#ifndef 

#endif //_COMMON_RES_H_

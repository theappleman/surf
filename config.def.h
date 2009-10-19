/* modifier 0 means no modifier */
static gchar *progress       = "#FF0000";
static gchar *progress_trust = "#00FF00";
static gchar *stylefile      = ".surf/style.css";
static gchar *scriptfile     = ".surf/script.js";
static gchar *cookiefile     = ".surf/cookies.txt";
static gchar *dldir          = ".surf/dl";
static time_t sessiontime    = 31557600;

#define MODKEY GDK_CONTROL_MASK
static Key keys[] = {
    /* modifier             keyval      function    arg             Focus */
    { MODKEY|GDK_SHIFT_MASK,GDK_r,      reload,     { .b = TRUE },  Any },
    { MODKEY,               GDK_r,      reload,     { .b = FALSE }, Any },
    { MODKEY,               GDK_g,      showurl,    { 0 },          Any },
    { MODKEY,               GDK_slash,  showsearch, { 0 },          Any },
    { 0,                    GDK_Escape, hidesearch, { 0 },          Any },
    { 0,                    GDK_Escape, hideurl,    { 0 },          Any },
    { MODKEY|GDK_SHIFT_MASK,GDK_p,      print,      { 0 },          Any },
    { MODKEY,               GDK_c,      clipboard,  { .b = TRUE },  Browser },
    { MODKEY,               GDK_v,      clipboard,  { .b = FALSE }, Browser },
    { MODKEY,               GDK_minus,  zoom,       { .i = -1 },    Browser },
    { MODKEY|GDK_SHIFT_MASK,GDK_plus,   zoom,       { .i = +1 },    Browser },
    { MODKEY,               GDK_0,      zoom,       { .i = 0  },    Browser },
    { MODKEY,               GDK_Left,   navigate,   { .i = -1 },    Browser },
    { MODKEY,               GDK_Right,  navigate,   { .i = +1 },    Browser },
    { MODKEY,               GDK_Up,     scroll,     { .i = +1 },    Browser },
    { MODKEY,               GDK_Down,   scroll,     { .i = -1 },    Browser },
    { 0,                    GDK_Escape, stop,       { 0 },          Browser },
    { MODKEY,               GDK_o,      source,     { 0 },          Browser },
    { MODKEY,               GDK_n,      searchtext, { .b = TRUE },  Browser|SearchBar },
    { MODKEY|GDK_SHIFT_MASK,GDK_n,      searchtext, { .b = FALSE }, Browser|SearchBar },
    { 0,                    GDK_Return, searchtext, { .b = TRUE },  SearchBar },
    { GDK_SHIFT_MASK,       GDK_Return, searchtext, { .b = FALSE }, SearchBar },
    { 0,                    GDK_Return, loaduri,    { .v = NULL },  UrlBar },
    { 0,                    GDK_Return, hideurl,    { 0 },          UrlBar },
};


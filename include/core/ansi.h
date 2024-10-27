#ifndef CORE_ANSI_H_
#define CORE_ANSI_H_

// ANSI escape codes
#define ANSI_RESET "\x1b[0m"

#define ANSI_BOLD "\x1b[1m"
#define ANSI_DIM "\x1b[2m"
#define ANSI_ITALIC "\x1b[3m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_BLINK "\x1b[5m"
#define ANSI_REVERSE "\x1b[7m"
#define ANSI_HIDDEN "\x1b[8m"

#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"

#define ANSI_BG_COLOR_BLACK "\x1b[40m"
#define ANSI_BG_COLOR_RED "\x1b[41m"
#define ANSI_BG_COLOR_GREEN "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW "\x1b[43m"
#define ANSI_BG_COLOR_BLUE "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN "\x1b[46m"
#define ANSI_BG_COLOR_WHITE "\x1b[47m"

#define ANSI_COLOR_BRIGHT_BLACK "\x1b[90m"
#define ANSI_COLOR_BRIGHT_RED "\x1b[91m"
#define ANSI_COLOR_BRIGHT_GREEN "\x1b[92m"
#define ANSI_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN "\x1b[96m"
#define ANSI_COLOR_BRIGHT_WHITE "\x1b[97m"

#define ANSI_BG_COLOR_BRIGHT_BLACK "\x1b[100m"
#define ANSI_BG_COLOR_BRIGHT_RED "\x1b[101m"
#define ANSI_BG_COLOR_BRIGHT_GREEN "\x1b[102m"
#define ANSI_BG_COLOR_BRIGHT_YELLOW "\x1b[103m"
#define ANSI_BG_COLOR_BRIGHT_BLUE "\x1b[104m"
#define ANSI_BG_COLOR_BRIGHT_MAGENTA "\x1b[105m"
#define ANSI_BG_COLOR_BRIGHT_CYAN "\x1b[106m"
#define ANSI_BG_COLOR_BRIGHT_WHITE "\x1b[107m"

typedef char const* ansi_t;

char* ansi_formated(char const* str, ansi_t fmt);

#endif  // CORE_ANSI_H_

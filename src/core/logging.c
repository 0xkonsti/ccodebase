#include "core/logging.h"
#include <stdarg.h>
#include <stdio.h>
#include "core/ansi.h"
#include "core/defines.h"

i32 g_log_level = LOG_LEVEL_DEBUG;

static char const* dim_bright_black(char const* str) {
    return ansi_formated(ansi_formated(str, ANSI_COLOR_BRIGHT_BLACK), ANSI_DIM);
}

static void log_on(i32 const level, char const* lable, char const* fmt, va_list args) {
    if (g_log_level > level) {
        return;
    }
    printf("%s%s%s ~ ", dim_bright_black("["), ansi_formated(lable, ANSI_BOLD), dim_bright_black("]"));
    vprintf(fmt, args);
    printf("\n");
}

void set_log_level(i32 const level) {
    g_log_level = level;
}

void log_debug(char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_on(LOG_LEVEL_DEBUG, ansi_formated("DEBUG", ANSI_COLOR_BRIGHT_BLUE), fmt, args);
    va_end(args);
}

void log_info(char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_on(LOG_LEVEL_INFO, ansi_formated("INFO", ANSI_COLOR_BRIGHT_GREEN), fmt, args);
    va_end(args);
}

void log_warn(char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_on(LOG_LEVEL_WARN, ansi_formated("WARN", ANSI_COLOR_BRIGHT_YELLOW), fmt, args);
    va_end(args);
}

void log_error(char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_on(LOG_LEVEL_ERROR, ansi_formated("ERROR", ANSI_COLOR_BRIGHT_RED), fmt, args);
    va_end(args);
}

#ifndef CORE_LOGGING_H_
#define CORE_LOGGING_H_

#include "ccodebase/core/defines.h"
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_OFF 4

extern i32 g_log_level;

void set_log_level(i32 const level);
void log_debug(char const* fmt, ...);
void log_info(char const* fmt, ...);
void log_warn(char const* fmt, ...);
void log_error(char const* fmt, ...);

#endif  // CORE_LOGGING_H_

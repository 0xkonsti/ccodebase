#include "core.h"

int main(void) {
    set_log_level(LOG_LEVEL_DEBUG);

    log_debug("Hello, world!");
    log_info("Hello, world!");
    log_warn("Hello, world!");
    log_error("Hello, world!");

    return 0;
}

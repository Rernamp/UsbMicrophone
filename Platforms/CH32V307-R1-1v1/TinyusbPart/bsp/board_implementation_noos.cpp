#include <bsp/board_api.h>

#include <cstdint>
#include <numeric>

#include "Platform.h"

#include <ch32v30x.h>

uint32_t board_millis(void) {
    return Platform::SystemTimer::now_ms();
}
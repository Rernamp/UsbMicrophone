#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>
#include <system_ch32v30x.h>

extern uint32_t system_ticks;

namespace Platform {
    bool initOsSpecific() {
        SysTick_Config(SystemCoreClock / 1000);
        return true;
    }

    namespace SystemTimer {
        uint32_t now_ms() {
            return system_ticks;
        }
    } // namespace SystemTimer
} // namespace Platform

#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>
#include <system_ch32v30x.h>

namespace Platform {

    bool clockInit() {
        bool result{true};

        return result;
    }

    bool init() {
        bool result{true};

        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	    SystemCoreClockUpdate();

        return result;
    }

    bool initAfterConfigureTinyusbStack() {
        bool result{true};

        return result;
    }
} // namespace Platform

extern "C" void _fini() {}
extern "C" void _init() {}
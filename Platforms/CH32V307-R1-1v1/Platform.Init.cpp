#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>
#include <system_ch32v30x.h>

namespace Platform {

    bool clockInit() {
        bool result{true};

        RCC_USBCLK48MConfig(RCC_USBCLK48MCLKSource_USBPHY);
        RCC_USBHSPLLCLKConfig(RCC_HSBHSPLLCLKSource_HSE);
        RCC_USBHSConfig(RCC_USBPLL_Div2);
        RCC_USBHSPLLCKREFCLKConfig(RCC_USBHSPLLCKREFCLK_4M);
        RCC_USBHSPHYPLLALIVEcmd(ENABLE);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_USBHS, ENABLE);
        return result;
    }

    bool init() {
        bool result{true};
        // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
        SystemCoreClockUpdate();

        __disable_irq();
        
        result &= initOsSpecific();

        result &= clockInit();

        __enable_irq();


        return result;
    }

    bool initAfterConfigureTinyusbStack() {
        bool result{true};

        return result;
    }
} // namespace Platform

extern "C" void _fini() {}
extern "C" void _init() {}
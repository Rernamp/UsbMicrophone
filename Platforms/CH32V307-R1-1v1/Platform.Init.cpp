#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>
#include <system_ch32v30x.h>

namespace Platform {

    bool clockInit() {
        bool result{true};

#ifdef CH32V30x_D8C
        // v305/v307: Highspeed USB
        RCC_USBCLK48MConfig(RCC_USBCLK48MCLKSource_USBPHY);
        RCC_USBHSPLLCLKConfig(RCC_HSBHSPLLCLKSource_HSE);
        RCC_USBHSConfig(RCC_USBPLL_Div2);
        RCC_USBHSPLLCKREFCLKConfig(RCC_USBHSPLLCKREFCLK_4M);
        RCC_USBHSPHYPLLALIVEcmd(ENABLE);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_USBHS, ENABLE);
#endif

        // Fullspeed USB
        uint8_t otg_div;
        switch (SystemCoreClock) {
            case 48000000:
                otg_div = RCC_OTGFSCLKSource_PLLCLK_Div1;
                break;
            case 96000000:
                otg_div = RCC_OTGFSCLKSource_PLLCLK_Div2;
                break;
            case 144000000:
                otg_div = RCC_OTGFSCLKSource_PLLCLK_Div3;
                break;
            default:
                return false;
                break;
        }
        RCC_OTGFSCLKConfig(otg_div);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_OTG_FS, ENABLE);

        return result;
    }

    bool init() {
        bool result{true};
        __disable_irq();

        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
        SystemCoreClockUpdate();

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
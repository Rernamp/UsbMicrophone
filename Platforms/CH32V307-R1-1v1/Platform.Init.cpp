#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>

#include "common/tusb_common.h"

namespace Platform {

    bool clockInit() {
        bool result{true};

        return result;
    }

    static uint32_t SysTick_Config(uint32_t ticks) {
        NVIC_EnableIRQ(SysTicK_IRQn);
        SysTick->CTLR = 0;
        SysTick->SR = 0;
        SysTick->CNT = 0;
        SysTick->CMP = ticks - 1;
        SysTick->CTLR = 0xF;
        return 0;
    }

    bool init() {
        bool result{true};

        __disable_irq();

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
                TU_ASSERT(0, false);
                break;
        }
        RCC_OTGFSCLKConfig(otg_div);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_OTG_FS, ENABLE);

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
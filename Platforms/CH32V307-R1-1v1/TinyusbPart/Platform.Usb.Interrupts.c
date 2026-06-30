#include <common/tusb_common.h>
#include <device/usbd.h>

#include <tusb_option.h>

void USBHS_IRQHandler_impl();
void USBHS_IRQHandler(void) __attribute__((naked));
void USBHS_IRQHandler(void) {
    __asm volatile("call USBHS_IRQHandler_impl; mret");
}

void USBHS_IRQHandler_impl(void) {
  #if CFG_TUD_WCH_USBIP_USBHS
  tud_int_handler(0);
  #endif
}

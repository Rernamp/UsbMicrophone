#include <common/tusb_common.h>
#include <device/usbd.h>

#include <tusb_option.h>

extern "C" void USBHS_IRQHandler(void) {
  #if CFG_TUD_WCH_USBIP_USBHS
  tud_int_handler(0);
  #endif
}

extern "C" void OTG_FS_IRQHandler(void) {
  #if CFG_TUD_WCH_USBIP_USBFS
  tud_int_handler(0);
  #endif
}
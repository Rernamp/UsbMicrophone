

__attribute__((interrupt)) void USBHS_IRQHandler(void) {
  #if CFG_TUD_WCH_USBIP_USBHS
  tud_int_handler(0);
  #endif
}

__attribute__((interrupt)) void OTG_FS_IRQHandler(void) {
  #if CFG_TUD_WCH_USBIP_USBFS
  tud_int_handler(0);
  #endif
}
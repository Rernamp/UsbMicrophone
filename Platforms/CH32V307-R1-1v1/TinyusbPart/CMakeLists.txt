add_library(Platform_CH32V307_Tinyusb INTERFACE)
add_library(Platform_CH32V307::Tinyusb ALIAS Platform_CH32V307_Tinyusb)

tinyusb_sources_get(TINYUSB_SRC)


target_sources(Platform_CH32V307_Tinyusb INTERFACE
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/dcd_ch32_usbhs.c
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/dcd_ch32_usbfs.c
    ${TINYUSB_SRC}
)

target_include_directories(Platform_CH32V307_Tinyusb INTERFACE
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/hw
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(Platform_CH32V307_Tinyusb INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/board_implementation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Usb.Interrupts.cpp
)


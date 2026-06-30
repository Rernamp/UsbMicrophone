add_library(Platform_CH32V307_Tinyusb_Src INTERFACE)
add_library(Platform_CH32V307::Tinyusb::Src ALIAS Platform_CH32V307_Tinyusb_Src)

tinyusb_sources_get(TINYUSB_SRC)

target_sources(Platform_CH32V307_Tinyusb_Src INTERFACE
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/dcd_ch32_usbhs.c
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/dcd_ch32_usbfs.c
    ${TINYUSB_SRC}
)

target_include_directories(Platform_CH32V307_Tinyusb_Src INTERFACE
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/hw
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(Platform_CH32V307_Tinyusb_Src INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/board_implementation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Usb.Interrupts.c
)
target_compile_definitions(Platform_CH32V307_Tinyusb_Src INTERFACE
    CFG_TUSB_MCU=OPT_MCU_CH32V307
    CFG_TUD_WCH_USBIP_USBHS=1
)

add_library(Platform_CH32V307_Tinyusb_Noos INTERFACE)
add_library(Platform_CH32V307::Tinyusb::Noos ALIAS Platform_CH32V307_Tinyusb_Noos)

target_compile_definitions(Platform_CH32V307_Tinyusb_Noos INTERFACE
    CFG_TUSB_OS=OPT_OS_NONE
)

target_link_libraries(Platform_CH32V307_Tinyusb_Noos INTERFACE
    Platform_CH32V307::Tinyusb::Src
)

target_sources(Platform_CH32V307_Tinyusb_Noos INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/board_implementation_noos.cpp
)

add_library(Platform_CH32V307_Tinyusb_Freertos INTERFACE)
add_library(Platform_CH32V307::Tinyusb::Freertos ALIAS Platform_CH32V307_Tinyusb_Freertos)

target_compile_definitions(Platform_CH32V307_Tinyusb_Freertos INTERFACE
    CFG_TUSB_OS=OPT_OS_FREERTOS
)
target_link_libraries(Platform_CH32V307_Tinyusb_Freertos INTERFACE
    Platform_CH32V307::Tinyusb::Src
)

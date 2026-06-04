add_library(TestTinyusbUsbMicrophone4ElementsCode INTERFACE)
add_library(Test::TinyusbUsbMicrophone4Elements::Code ALIAS TestTinyusbUsbMicrophone4ElementsCode)

target_sources(TestTinyusbUsbMicrophone4ElementsCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tusb_config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/usb_descriptors.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/board_api.h
)

target_include_directories(TestTinyusbUsbMicrophone4ElementsCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
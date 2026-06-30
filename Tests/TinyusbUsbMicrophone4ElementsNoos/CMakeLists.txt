add_library(TestTinyusbUsbMicrophone4ElementsCodeNoos INTERFACE)
add_library(Test::TinyusbUsbMicrophone4Elements::Noos::Code ALIAS TestTinyusbUsbMicrophone4ElementsCodeNoos)

target_sources(TestTinyusbUsbMicrophone4ElementsCodeNoos INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tusb_config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/usb_descriptors.c
)

target_include_directories(TestTinyusbUsbMicrophone4ElementsCodeNoos INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
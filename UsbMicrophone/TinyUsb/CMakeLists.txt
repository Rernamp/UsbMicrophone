target_include_directories(CommonCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(CommonCode INTERFACE
    usb_descriptors.c
    usb_descriptors.h
)

target_include_directories(tinyusb_config INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
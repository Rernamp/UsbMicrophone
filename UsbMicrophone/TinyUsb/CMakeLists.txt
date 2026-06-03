target_include_directories(UsbMicrophoneCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(UsbMicrophoneCode INTERFACE
    usb_descriptors.c
    usb_descriptors.h
)

target_include_directories(tinyusb_config INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
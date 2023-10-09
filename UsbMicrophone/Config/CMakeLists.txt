
add_library(tinyusb_config INTERFACE)

target_include_directories(tinyusb_config INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(tinyusb_config INTERFACE
    tusb_config.h
)


target_include_directories(CommonCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(CommonCode INTERFACE
    FreeRTOSConfig.h
)

target_link_libraries(CommonCode INTERFACE
    tinyusb_config
)

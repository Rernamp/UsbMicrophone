add_library(PlatformCH32V307Startup INTERFACE)

add_library(Platform::CH32V307::Startup ALIAS PlatformCH32V307Startup)

target_sources(PlatformCH32V307Startup INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/startup_ch32v30x_D8C.S
)

target_include_directories(PlatformCH32V307Startup INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
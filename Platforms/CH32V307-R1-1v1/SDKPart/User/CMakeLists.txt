add_library(PlatformCH32V307User INTERFACE)

add_library(Platform::CH32V307::User ALIAS PlatformCH32V307User)

target_sources(PlatformCH32V307User INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/ch32v30x_conf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/system_ch32v30x.h
    ${CMAKE_CURRENT_SOURCE_DIR}/system_ch32v30x.c
    
)

target_include_directories(PlatformCH32V307User INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
add_library(PlatformCH32V307Debug INTERFACE)

add_library(Platform::CH32V307::Debug ALIAS PlatformCH32V307Debug)

target_sources(PlatformCH32V307Debug INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/debug.h
)

target_include_directories(PlatformCH32V307Debug INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
add_library(PlatformCH32V307Core INTERFACE)

add_library(Platform::CH32V307::Core ALIAS PlatformCH32V307Core)

target_sources(PlatformCH32V307Core INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/core_riscv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/core_riscv.h
)

target_include_directories(PlatformCH32V307Core INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
cmake_minimum_required(VERSION 3.16)

add_library(PlatformCH32V307 INTERFACE)

add_subdirectory(FreeRTOS)
add_subdirectory(Core)
add_subdirectory(Debug)
add_subdirectory(Peripheral)
add_subdirectory(Startup)
add_subdirectory(User)

target_link_libraries(PlatformCH32V307 INTERFACE
    Platform::CH32V307::Core
    # Platform::CH32V307::Debug
    Platform::CH32V307::Peripheral
    Platform::CH32V307::Startup
    Platform::CH32V307::User
)

gcc_add_linker_script(PlatformCH32V307 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Ld/Link.ld")
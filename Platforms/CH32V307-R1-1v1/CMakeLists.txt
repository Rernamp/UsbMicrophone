add_library(Platform_CH32V307-R1-1v1 INTERFACE)

add_library(Platform::CH32V307-R1-1v1 ALIAS Platform_CH32V307-R1-1v1)

add_subdirectory(SDKPart)

target_link_libraries(Platform_CH32V307-R1-1v1 INTERFACE
    CH32::V307
    GCC::Specs::NoSys
	GCC::Specs::Nano
    PlatformCH32V307
    # FreertosCH32V307
)

target_include_directories(Platform_CH32V307-R1-1v1 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Dependencies/tinyusb/src
)



target_sources(Platform_CH32V307-R1-1v1 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Init.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.SystemTimer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Interrupts.cpp
)

target_sources(PlatformCH32V307Freertos INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Init.Freertos.cpp
)

add_library(PlatformCH32V307Noos INTERFACE)
add_library(Platform::CH32V307::Noos ALIAS PlatformCH32V307Noos)

target_sources(PlatformCH32V307Noos INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Init.Noos.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Systimer.c
)


add_subdirectory(TinyusbPart)

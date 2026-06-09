add_library(Platform_CH32V307-R1-1v1 INTERFACE)

add_library(Platform::CH32V307-R1-1v1 ALIAS Platform_CH32V307-R1-1v1)


target_compile_definitions(Platform_CH32V307-R1-1v1 INTERFACE
    CFG_TUSB_MCU=OPT_MCU_CH32V307
    CFG_TUSB_OS=OPT_OS_NONE
)

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
)



target_sources(Platform_CH32V307-R1-1v1 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Init.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.SystemTimer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform.Interrupts.cpp
)


add_subdirectory(TinyusbPart)


target_link_libraries(Platform_CH32V307-R1-1v1 INTERFACE
    Platform_CH32V307::Tinyusb
)
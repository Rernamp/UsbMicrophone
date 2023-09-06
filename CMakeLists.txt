cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(Dependencies/pico-sdk/pico_sdk_init.cmake)

project(UsbMicrophone C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(Application)

add_library(CommonCode INTERFACE)


set(FREERTOS_PORT GCC_RP2040 CACHE STRING "")  



target_link_libraries(CommonCode INTERFACE
    pico_stdlib
    hardware_sync
    hardware_structs
)

add_library(freertos_config INTERFACE)

target_link_libraries(freertos_config INTERFACE
    CommonCode
)


add_subdirectory(UsbMicrophone)
add_subdirectory(Dependencies/FreeRTOS-Kernel)


target_link_libraries(Application PRIVATE
    CommonCode
    freertos_kernel
)


pico_add_extra_outputs(Application)
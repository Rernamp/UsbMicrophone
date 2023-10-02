cmake_minimum_required(VERSION 3.13)

project(UsbMicrophone C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(Application)

add_subdirectory(Dependencies/Mcu.Cmake)

add_library(CommonCode INTERFACE)


target_link_libraries(CommonCode INTERFACE
    
)

add_subdirectory(UsbMicrophone)


target_link_libraries(Application PRIVATE
    CommonCode
    freertos_kernel
)

cmake_minimum_required(VERSION 3.13)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(ToolchainFilePath "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Mcu.Cmake/riscv/riscv_gcc.cmake")
	if(EXISTS ${ToolchainFilePath})
		set(CMAKE_TOOLCHAIN_FILE "${ToolchainFilePath}" CACHE PATH "toolchain file" FORCE)
		message("Toolchain file found and set to ${ToolchainFilePath}")
	else()
		message(FATAL_ERROR "Unable to resolve '${ToolchainFilePath}' for setting toolchain file.")
	endif()
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Mcu.CMake")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

project(UsbMicrophone C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_library(UsbMicrophoneCode INTERFACE)

include(Dependencies/Mcu.CMake/riscv/CH32/V307.cmake)


add_subdirectory(Dependencies)
add_subdirectory(Platforms)
add_subdirectory(UsbMicrophone)


add_executable(UsbMicrophone)

tinyusb_target_add(UsbMicrophone)
target_link_libraries(UsbMicrophone PUBLIC
    UsbMicrophoneCode
    Platform_CH32V307-R1-1v1
)

add_subdirectory(Tests)

add_executable(TestTinyusbUsbMicrophone4Elements)

tinyusb_target_add(TestTinyusbUsbMicrophone4Elements)
target_link_libraries(TestTinyusbUsbMicrophone4Elements PUBLIC
    Test::TinyusbUsbMicrophone4Elements::Code
    Platform_CH32V307-R1-1v1
)

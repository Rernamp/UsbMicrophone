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

project(UsbMicrophone C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(Application)

add_library(CommonCode INTERFACE)

include(Dependencies/Mcu.CMake/riscv/CH32/V307.cmake)

add_subdirectory(UsbMicrophone)


add_library(tinyusb_ch32v307 INTERFACE)

target_sources(tinyusb_ch32v307 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/ch32v307/ch32_usbhs_reg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/src/portable/wch/ch32v307/dcd_usbhs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw/bsp/board_api.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw/bsp/ch32v307/boards/ch32v307v_r1_1v0/board.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw/bsp/ch32v307/boards/ch32v307v_r1_1v0/debug_uart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw/bsp/ch32v307/boards/ch32v307v_r1_1v0/debug_uart.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/src/portable/template/dcd_template.c 
    # ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/src/portable/template/hcd_template.c
)

target_include_directories(tinyusb_ch32v307 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyusb/hw/bsp/ch32v307/boards/ch32v307v_r1_1v0/
)
 
target_link_libraries(tinyusb_config INTERFACE 
    tinyusb_ch32v307
    ch32v307_tinyusb_platform
)
target_compile_definitions(tinyusb_config INTERFACE CFG_TUSB_MCU=OPT_MCU_CH32V307)

add_subdirectory(Dependencies/tinyusb/src)


target_link_libraries(CommonCode INTERFACE
    CH32::V307
    tinyusb    
)

if(NOT (TARGET GCC::Specs::NoSys))
    add_library(GCC::Specs::NoSys INTERFACE IMPORTED)
    target_link_options(GCC::Specs::NoSys INTERFACE 
        -specs=nosys.specs
    )
endif()

if(NOT (TARGET GCC::Specs::Nano))
    add_library(GCC::Specs::Nano INTERFACE IMPORTED)
    target_link_options(GCC::Specs::Nano INTERFACE 
        -specs=nano.specs
    )
endif()

target_link_libraries(Application PRIVATE
    CommonCode
    # FreertosCH32V307
    PlatformCH32V307
    GCC::Specs::NoSys
	GCC::Specs::Nano
)

function(gcc_add_linker_script TARGET VISIBILITY SCRIPT_PATH)
    message("Link: ${SCRIPT_PATH}")
    get_filename_component(SCRIPT_PATH "${SCRIPT_PATH}" ABSOLUTE)
    target_link_options(${TARGET} ${VISIBILITY} -T "${SCRIPT_PATH}")
endfunction()

gcc_add_linker_script(Application PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/UsbMicrophone/Platform/Ld/Link.ld")

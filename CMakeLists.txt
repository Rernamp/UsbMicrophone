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
    FreertosCH32V307
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

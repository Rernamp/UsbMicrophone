cmake_minimum_required(VERSION 3.13)

set(CMAKE_SYSTEM_NAME Generic)

include(${CMAKE_CURRENT_LIST_DIR}/Dependencies/Mcu.Cmake/riscv/riscv_gcc.cmake)

project(UsbMicrophone C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(Application)

add_library(CommonCode INTERFACE)


target_link_libraries(CommonCode INTERFACE
    
)

add_subdirectory(UsbMicrophone)

target_link_libraries(Application PRIVATE
    CommonCode
    FreertosCH32V307
    PlatformCH32V307
)

function(gcc_add_linker_script TARGET VISIBILITY SCRIPT_PATH)
    message("Link: ${SCRIPT_PATH}")
    get_filename_component(SCRIPT_PATH "${SCRIPT_PATH}" ABSOLUTE)
    target_link_options(${TARGET} ${VISIBILITY} -T "${SCRIPT_PATH}")
endfunction()

gcc_add_linker_script(Application PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/UsbMicrophone/Platform/Ld/Link.ld")




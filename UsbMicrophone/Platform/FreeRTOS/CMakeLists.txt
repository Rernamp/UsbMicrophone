cmake_minimum_required(VERSION 3.16)

add_library(FreertosCH32V307 INTERFACE)
target_include_directories(FreertosCH32V307 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(FreertosCH32V307 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V)
target_include_directories(FreertosCH32V307 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions)

target_sources(FreertosCH32V307 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/croutine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/portable
    ${CMAKE_CURRENT_SOURCE_DIR}/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stream_buffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/include/atomic.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/croutine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/deprecated_definitions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/event_groups.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeRTOS.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/message_buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mpu_prototypes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mpu_wrappers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/portable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/projdefs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/queue.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/semphr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/StackMacros.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/stack_macros.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/stream_buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/task.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/timers.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/portable/Common/mpu_wrappers.c    // Omg WCH disabled this file, lol
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/portASM.S
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/portmacro.h
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/readme.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions/freertos_risc_v_chip_specific_extensions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/portable/MemMang/heap_4.c
)
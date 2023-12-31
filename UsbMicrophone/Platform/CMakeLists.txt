cmake_minimum_required(VERSION 3.16)

add_library(PlatformCH32V307 INTERFACE)
target_include_directories(PlatformCH32V307 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug
    ${CMAKE_CURRENT_SOURCE_DIR}/User
)

target_sources(PlatformCH32V307 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/core_riscv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/core_riscv.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug/debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug/debug.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_adc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_bkp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_can.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_crc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_dac.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_dbgmcu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_dma.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_dvp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_eth.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_exti.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_flash.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_fsmc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_gpio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_i2c.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_iwdg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_misc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_opa.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_pwr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_rcc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_rng.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_rtc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_sdio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_spi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_tim.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_usart.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc/ch32v30x_wwdg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_bkp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_can.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_crc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_dac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_dbgmcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_dvp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_eth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_exti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_flash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_fsmc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_iwdg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_opa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_pwr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_rng.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_rtc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_sdio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_usart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_wwdg.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_ch32v30x_D8.S
    ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_ch32v30x_D8C.S
    ${CMAKE_CURRENT_SOURCE_DIR}/User/ch32v30x_conf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/User/ch32v30x_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/User/ch32v30x_it.h
    ${CMAKE_CURRENT_SOURCE_DIR}/User/system_ch32v30x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/User/system_ch32v30x.h
)

add_subdirectory(FreeRTOS)

add_library(ch32v307_tinyusb_platform INTERFACE)
target_sources(ch32v307_tinyusb_platform INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/core_riscv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/src/ch32v30x_usart.c
)

target_include_directories(ch32v307_tinyusb_platform INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Peripheral/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug
    ${CMAKE_CURRENT_SOURCE_DIR}/User
)

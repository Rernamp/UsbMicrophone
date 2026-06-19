add_library(TestFreeRtosBlinkCode INTERFACE)
add_library(Test::FreeRtosBlink::Code ALIAS TestFreeRtosBlinkCode)

target_sources(TestFreeRtosBlinkCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(TestFreeRtosBlinkCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
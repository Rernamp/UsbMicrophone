add_library(TestNoosBlinkCode INTERFACE)
add_library(Test::NoosBlink::Code ALIAS TestNoosBlinkCode)

target_sources(TestNoosBlinkCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(TestNoosBlinkCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
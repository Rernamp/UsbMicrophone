target_sources(CommonCode INTERFACE
    family.c
    main.cpp
)

add_subdirectory(Config)
add_subdirectory(Platform)
add_subdirectory(TinyUsb)

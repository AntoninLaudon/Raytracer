cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 20)

add_library(cylinder SHARED
    Cylinder.cpp
    )

add_compile_options(-Wall -Wextra -Wpedantic -Werror -fno-gnu-unique)

set_target_properties(cylinder PROPERTIES PREFIX "")

set_target_properties(cylinder PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../)

target_include_directories(cylinder PUBLIC
    ../../src/Elements/
    ../../src/PPM_generator/
    ../../src/
    /
)


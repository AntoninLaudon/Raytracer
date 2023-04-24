cmake_minimum_required(VERSION 3.0.0)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${PROJECT_SOURCE_DIR}/raytracer)

add_executable(raytracer
src/main.cpp
src/Factory.cpp
src/Elements/Camera.cpp
src/Elements/Primitive.cpp
src/math.cpp
)

target_link_libraries(raytracer PUBLIC dl)

target_include_directories(raytracer PUBLIC
    src/Core
    src/Elements
    src/Scene
    src)

add_custom_command(TARGET raytracer POST_BUILD
    COMMAND cp raytracer ${PROJECT_SOURCE_DIR})

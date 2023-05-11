cmake_minimum_required(VERSION 3.0.0)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Wpedantic -Werror -fno-gnu-unique)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    $(PROJECT_SOURCE_DIR)/raytracer)
    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(raytracer
    src/main.cpp
    src/Factory.cpp
    src/Math.cpp
    src/Observer.cpp
    src/File.cpp
    src/Core/Core.cpp
    src/Elements/Data.cpp
    src/Elements/Camera.cpp
    src/PPM_generator/Generation.cpp
    src/Scene/SceneManager.cpp)

find_library(LIBCONFIG config++)
find_library(LIBDL dl)
find_library(LIBSFML_GRAPHICS sfml-graphics)
find_library(LIBSFML_WINDOW sfml-window)
find_library(LIBSFML_SYSTEM sfml-system)

target_link_libraries(raytracer PUBLIC ${LIBCONFIG} ${LIBDL} ${LIBSFML_GRAPHICS} ${LIBSFML_WINDOW} ${LIBSFML_SYSTEM} -pthread)
    
target_include_directories(raytracer PUBLIC
    src/
    src/Core/
    src/Elements/
    src/PPM_generator/
    src/Scene/
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/sphere)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/plan)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/cylinder)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/triangle)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/cone)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/ambientlight)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/directionallight)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/spotlight)

add_dependencies(raytracer sphere plan cylinder cone triangle ambientlight directionallight spotlight)

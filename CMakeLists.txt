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
    
target_link_libraries(raytracer PUBLIC dl config++)
    
target_include_directories(raytracer PUBLIC
    src/
    src/Core/
    src/Elements/
    src/PPM_generator/
    src/Scene/
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/sphere)

add_dependencies(raytracer sphere)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins/plan)

add_dependencies(raytracer plan)

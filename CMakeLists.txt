cmake_minimum_required(VERSION 3.15)

project(array-macros VERSION 1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(array-macros INTERFACE)

target_include_directories(array-macros INTERFACE include)

option(BUILD_TESTS "Build the array-macros tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

project(ini)

cmake_minimum_required(VERSION 3.1)
include(CTest)

if(BUILD_TESTING)
find_package(Qt5 COMPONENTS Test REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif(BUILD_TESTING)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_PATH "${CMAKE_BINARY_DIR}/libs" CACHE STRING "Path where the libraries are deployed")
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")
add_subdirectory(apigear_game)
add_subdirectory(plugin_apigear_game)
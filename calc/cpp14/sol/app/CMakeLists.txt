cmake_minimum_required(VERSION 3.5)

project(calcdemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(calcdemo main.cpp)
target_link_libraries(calcdemo ${CONAN_LIBS})

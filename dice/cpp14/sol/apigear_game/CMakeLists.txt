cmake_minimum_required(VERSION 3.1)
project(apigear_game)

include(CTest)

set(CMAKE_CXX_STANDARD 14)

set (SOURCES
    apigear/tracer.cpp
    apig/apigear_game.apig.cpp
    apig/apigear_game.trace.cpp
    dice.cpp
    random.cpp
)
add_library(apigear_game SHARED ${SOURCES})
target_include_directories(apigear_game PRIVATE apigear)
target_link_libraries(apigear_game ${CONAN_LIBS})

# add test cases
if(BUILD_TESTING)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    apigear/tracer.test.cpp
    dice.test.cpp
    random.test.cpp
    apigear_game.test.cpp
)
add_executable(test_apigear_game EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_apigear_game apigear_game)

add_test(test_apigear_game "bin/test_apigear_game")
add_dependencies(check test_apigear_game)
endif(BUILD_TESTING)

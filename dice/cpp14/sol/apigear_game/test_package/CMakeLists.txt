project(Testapigear_game)
cmake_minimum_required(VERSION 3.1)
include(CTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)

# add test for apigear_game
set (SOURCES_TEST
    ../dice.test.cpp
    ../random.test.cpp
    ../apigear_game.test.cpp
)
add_executable(test_apigear_game #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_include_directories(test_apigear_game PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(test_apigear_game ${CONAN_LIBS})
add_test(test_apigear_game test_apigear_game)
add_dependencies(check test_apigear_game)

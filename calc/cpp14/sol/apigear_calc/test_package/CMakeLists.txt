project(Testapigear_calc)
cmake_minimum_required(VERSION 3.1)
include(CTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)

# add test for apigear_calc
set (SOURCES_TEST
    ../calculator.test.cpp
    ../apigear_calc.test.cpp
)
add_executable(test_apigear_calc #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_include_directories(test_apigear_calc PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(test_apigear_calc ${CONAN_LIBS})
add_test(test_apigear_calc test_apigear_calc)
add_dependencies(check test_apigear_calc)

cmake_minimum_required(VERSION 3.1)
project(apigear_calc)

include(CTest)

set(CMAKE_CXX_STANDARD 14)

set (SOURCES
    apigear/tracer.cpp
    apig/apigear_calc.apig.cpp
    apig/apigear_calc.trace.cpp
    calculator.cpp
)
add_library(apigear_calc SHARED ${SOURCES})
target_include_directories(apigear_calc PRIVATE apigear)
target_link_libraries(apigear_calc ${CONAN_LIBS})

# add test cases
if(BUILD_TESTING)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    apigear/tracer.test.cpp
    calculator.test.cpp
    apigear_calc.test.cpp
)
add_executable(test_apigear_calc EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_apigear_calc apigear_calc)

add_test(test_apigear_calc "bin/test_apigear_calc")
add_dependencies(check test_apigear_calc)
endif(BUILD_TESTING)

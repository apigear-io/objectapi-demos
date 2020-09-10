find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (APIGEAR_CALC_SOURCES
    api.cpp
    tracer.cpp
    factory.cpp
    ../shared/traceclient.cpp
    calculator.cpp
    qmlcalculator.cpp
)

# dynamic library

add_library(apigear_calc SHARED ${APIGEAR_CALC_SOURCES})

# set_target_properties(apigear_calc PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
#     RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
# )

target_link_libraries(apigear_calc PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets)

# static library
add_library(apigear_calc_static STATIC ${APIGEAR_CALC_SOURCES})

# set_target_properties(apigear_calc_static PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
#     RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
# )

target_link_libraries(apigear_calc_static PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets)

# add test cases
if(BUILD_TESTING)

add_executable(test_apigear_calc_calculator EXCLUDE_FROM_ALL
    tst_calculator.cpp
)

target_link_libraries(test_apigear_calc_calculator PRIVATE Qt5::Test apigear_calc)

add_test(test_apigear_calc_calculator test_apigear_calc_calculator)
add_dependencies(check test_apigear_calc_calculator)

endif(BUILD_TESTING)


find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_APIGEAR_CALC_SOURCES
    plugin.cpp
)

add_library(plugin_apigear_calc SHARED ${PLUGIN_APIGEAR_CALC_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/apigear/calc)

set_target_properties(plugin_apigear_calc PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_apigear_calc PRIVATE Qt5::Core Qt5::Qml apigear_calc_static)
target_include_directories(plugin_apigear_calc PRIVATE ../shared)
target_include_directories(plugin_apigear_calc PRIVATE ../apigear_calc)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
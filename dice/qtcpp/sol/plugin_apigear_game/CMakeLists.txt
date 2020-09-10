find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_APIGEAR_GAME_SOURCES
    plugin.cpp
)

add_library(plugin_apigear_game SHARED ${PLUGIN_APIGEAR_GAME_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/apigear/game)

set_target_properties(plugin_apigear_game PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_apigear_game PRIVATE Qt5::Core Qt5::Qml apigear_game_static)
target_include_directories(plugin_apigear_game PRIVATE ../shared)
target_include_directories(plugin_apigear_game PRIVATE ../apigear_game)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
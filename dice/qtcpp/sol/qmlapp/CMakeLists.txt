find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(qmlapp main.cpp qml.qrc)

target_link_libraries(qmlapp PRIVATE Qt5::Core Qt5::Quick apigear_game_static)
target_include_directories(qmlapp PRIVATE ../apigear_game)

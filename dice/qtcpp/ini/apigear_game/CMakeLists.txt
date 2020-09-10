find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (APIGEAR_GAME_SOURCES
    api.cpp
    tracer.cpp
    factory.cpp
    ../shared/traceclient.cpp
    dice.cpp
    qmldice.cpp
    random.cpp
    qmlrandom.cpp
)

# dynamic library

add_library(apigear_game SHARED ${APIGEAR_GAME_SOURCES})

target_link_libraries(apigear_game PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets)

# static library
add_library(apigear_game_static STATIC ${APIGEAR_GAME_SOURCES})

target_link_libraries(apigear_game_static PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets)

# add test cases
if(BUILD_TESTING)

add_executable(test_apigear_game_dice EXCLUDE_FROM_ALL
    tst_dice.cpp
)

target_link_libraries(test_apigear_game_dice PRIVATE Qt5::Test apigear_game)

add_test(test_apigear_game_dice test_apigear_game_dice)
add_dependencies(check test_apigear_game_dice)

add_executable(test_apigear_game_random EXCLUDE_FROM_ALL
    tst_random.cpp
)

target_link_libraries(test_apigear_game_random PRIVATE Qt5::Test apigear_game)

add_test(test_apigear_game_random test_apigear_game_random)
add_dependencies(check test_apigear_game_random)

endif(BUILD_TESTING)


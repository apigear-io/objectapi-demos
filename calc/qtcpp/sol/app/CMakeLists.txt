find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (APP_SOURCES
    main.cpp
    console.cpp
)

add_executable(app ${APP_SOURCES})

target_link_libraries(app PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets apigear_calc_static)
target_include_directories(app PRIVATE ../shared)
target_include_directories(app PRIVATE ../apigear_calc)


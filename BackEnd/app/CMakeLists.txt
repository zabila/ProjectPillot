cmake_minimum_required (VERSION ${CMAKE_VERSION})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${SOURCE_DIR})

find_package(Qt5 COMPONENTS Core Gui Qml Quick REQUIRED)

add_executable( ${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
    server
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    )

cmake_minimum_required(VERSION 3.10.2)
Project(ProjectPillot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Add QT5
find_package( Qt5 COMPONENTS Core Network Gui Widgets Qml Quick REQUIRED)

find_package(easyloggingpp)

set(COMMON_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_DIR_BACK_END ${CMAKE_SOURCE_DIR}/BackEnd)

set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(BackEnd)
add_subdirectory(Common)
add_subdirectory(ClientTank)

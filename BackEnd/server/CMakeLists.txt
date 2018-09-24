cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(server)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)
find_package(Qt5Network)

file( GLOB HEADERS
    server.h
    impl/serverImpl.h
    impl/qtServer.h)

file( GLOB SOURCES
    server.cpp
    impl/serverImpl.cpp
    impl/qtServer.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC common Qt5::Core Qt5::Network)

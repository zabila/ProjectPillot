cmake_minimum_required (VERSION 3.5.1)
Project(common)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_BINARY_DIR       ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib)

find_package(Qt5Core)
find_package(Qt5Network)

file( GLOB HEADERS
    network/enums.h
    network/type.h
    network/serDesHelper.h
)

file( GLOB SOURCES
    network/enums.cpp
    network/type.cpp
    network/serDesHelper.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Network)

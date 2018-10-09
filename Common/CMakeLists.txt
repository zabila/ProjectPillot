cmake_minimum_required (VERSION 3.5.1)
Project(CommonLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIBRARY_OUTPUT_PATH    ${CMAKE_SOURCE_DIR}/build/lib)

file( GLOB HEADERS
    network/Enums.h
    network/Types.h
)

file( GLOB SOURCES
    network/Enums.cpp
    network/Types.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME})

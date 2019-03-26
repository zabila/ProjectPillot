cmake_minimum_required (VERSION 3.5.1)
Project(CommonLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIBRARY_OUTPUT_PATH    ${CMAKE_SOURCE_DIR}/build/lib)

file( GLOB HEADERS
    macro.h
    network/Enums.h
    network/Types.h
    network/Converter.h
    logger/logger.h
    logger/src/easylogging++.h
)

file( GLOB SOURCES
    network/Enums.cpp
    network/Types.cpp
    network/Converter.cpp
    logger/src/easylogging++.cc
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME})

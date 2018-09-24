cmake_minimum_required(VERSION 3.5)
Project(BackEnd)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${PROJECT_DIR_BACK_END})
include_directories(${COMMON_SOURCE_DIR})

set(CMAKE_BINARY_DIR       ${CMAKE_SOURCE_DIR}/build-BackEnd)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(app)
add_subdirectory(controller)
add_subdirectory(server)

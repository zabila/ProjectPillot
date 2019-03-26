cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(ServerCtrl)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(USED_LIBS CommonLib ServerLib ui)

file( GLOB HEADERS
    ServerController.h)

file( GLOB SOURCES
    ServerController.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

target_link_libraries(${PROJECT_NAME} PUBLIC ${USED_LIBS})

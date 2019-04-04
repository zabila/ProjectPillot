cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(CtrlLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(USED_LIBS CommonLib ServerLib UILib)

file( GLOB HEADERS
    Controller.h
    impl/ControllerImpl.h)

file( GLOB SOURCES
    Controller.cpp
    impl/ControllerImpl.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

target_link_libraries(${PROJECT_NAME} PUBLIC ${USED_LIBS})

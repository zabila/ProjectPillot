cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(UILib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SRCS impl/resource/*.cpp)
file(GLOB_RECURSE HDRS impl/resource/*.h)
file(GLOB_RECURSE SRUI impl/resource/*.ui)

set(USED_LIBS
    CommonLib
    CtrlLib
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)

file( GLOB HEADERS
    ${HDRS}
    View.h
    impl/ViewImpl.h)

file( GLOB SOURCES
    ${SRCS}
    View.cpp
    impl/ViewImpl.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${SRUI})

target_link_libraries(${PROJECT_NAME} ${USED_LIBS})

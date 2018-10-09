cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(ServerLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost 1.65.1 REQUIRED system )

include_directories(${Boost_INCLUDE_DIRS})

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} CommonLib)

file( GLOB HEADERS
    Server.h
    impl/ServerImpl.h
    impl/Session.h)

file( GLOB SOURCES
    Server.cpp
    impl/ServerImpl.cpp
    impl/Session.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

target_link_libraries(${PROJECT_NAME} PUBLIC ${USED_LIBS} )

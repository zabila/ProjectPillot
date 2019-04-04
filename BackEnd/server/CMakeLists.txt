cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(ServerLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(USED_LIBS CommonLib CtrlLib)

file( GLOB HEADERS
    Server.h
    impl/ServerImpl.h
    impl/TcpServer.h)

file( GLOB SOURCES
    Server.cpp
    impl/ServerImpl.cpp
    impl/TcpServer.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS}  )

target_link_libraries(${PROJECT_NAME} PUBLIC ${USED_LIBS} Qt5::Core Qt5::Network)

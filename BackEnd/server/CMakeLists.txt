cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(ServerLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(USED_LIBS CommonLib)

file( GLOB HEADERS
    Server.h
    impl/ServerImpl.h
    impl/TcpServer.h
    impl/TcpClient.h)

file( GLOB SOURCES
    Server.cpp
    impl/ServerImpl.cpp
    impl/TcpServer.cpp
    impl/TcpClient.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS}  )

target_link_libraries(${PROJECT_NAME} PUBLIC ${USED_LIBS} Qt5::Core Qt5::Network)

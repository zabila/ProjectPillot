cmake_minimum_required (VERSION 3.5.1)
Project(common)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file( GLOB HEADERS
    server/serverEnums.h
)

file( GLOB SOURCES
    server/serverEnums.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

#target_link_libraries(${PROJECT_NAME} PUBLIC
#    ${Boost_SYSTEM_LIBRARY}
#    ${Boost_LOG_LIBRARY}
#        Qt5::Core
#    -pthread )

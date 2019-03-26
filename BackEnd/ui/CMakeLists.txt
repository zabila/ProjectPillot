cmake_minimum_required (VERSION ${CMAKE_VERSION})
Project(ui)

qt5_add_resources(QT_RESOURCES impl/qml/qml.qrc)

file( GLOB HEADERS
    ServerSettingsCard.h
    ViewModel.h
    impl/ServerSettingsUI.h)

file( GLOB SOURCES
    ServerSettingsCard.cpp
    ViewModel.cpp
    impl/ServerSettingsUI.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${QT_RESOURCES})

target_link_libraries(${PROJECT_NAME}
    CommonLib
    ServerCtrl
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    )

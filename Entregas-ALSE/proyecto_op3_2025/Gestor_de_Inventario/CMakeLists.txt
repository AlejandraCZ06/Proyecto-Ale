cmake_minimum_required(VERSION 3.5)

project(Gestor_de_Inventario VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        component.h
        component.cpp
        databasemanager.h
        databasemanager.cpp
        inventorymanager.h
        inventorymanager.cpp
        reportgenerator.h
        reportgenerator.cpp
)
configure_file(${CMAKE_SOURCE_DIR}/db/inventario.sql
               ${CMAKE_BINARY_DIR}/db/inventario.sql COPYONLY)

set(SQL_FILES
    db/inventario.sql
    db/inventario.db
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Gestor_de_Inventario
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${SQL_FILES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Gestor_de_Inventario APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Gestor_de_Inventario SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Gestor_de_Inventario
            ${PROJECT_SOURCES}
            ${SQL_FILES}
        )
    endif()
endif()

target_link_libraries(Gestor_de_Inventario PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt5::Sql)

set_target_properties(Gestor_de_Inventario PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Gestor_de_Inventario
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Gestor_de_Inventario)
endif()

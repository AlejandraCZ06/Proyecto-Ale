cmake_minimum_required(VERSION 3.5)

project(Gestor_de_Inventario VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

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

# Asegura que el archivo SQL esté en el build dir
configure_file(${CMAKE_SOURCE_DIR}/db/inventario.sql
               ${CMAKE_BINARY_DIR}/db/inventario.sql COPYONLY)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Gestor_de_Inventario
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Gestor_de_Inventario SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Gestor_de_Inventario
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Gestor_de_Inventario PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(Gestor_de_Inventario PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Asegura copiar el SQL al instalar, pero NO la base .db (que se crea dinámica)
install(FILES db/inventario.sql DESTINATION db)

install(TARGETS Gestor_de_Inventario
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Gestor_de_Inventario)
endif()

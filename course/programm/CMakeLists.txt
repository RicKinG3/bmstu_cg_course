cmake_minimum_required(VERSION 3.5)

project(programm VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)

set(PROJECT_SOURCES
        additivemathelements.cpp
        illuminantplacechooser.cpp
        main.cpp
        mainwindow.cpp
        movechooser.cpp
        objectchanger.cpp
        objecthangman.cpp
        objects.cpp
        placechooser.cpp
        sizechooser.cpp
        specialgraphicsview.cpp
        usagefacade.cpp
)

set(PROJECT_HEADERS
        additivemathelements.hpp
        config.hpp
        illuminantplacechooser.hpp
        mainwindow.h
        movechooser.hpp
        objectchanger.hpp
        objecthangman.hpp
        objects.hpp
        placechooser.h
        sizechooser.hpp
        specialgraphicsview.hpp
        usagefacade.hpp
)

set(PROJECT_FORMS
        illuminantplacechooser.ui
        mainwindow.ui
        movechooser.ui
        objectchanger.ui
        objecthangman.ui
        placecarсhooser.ui
        placehousechooser.ui
        placeroadсhooser.ui
        placetreechooser.ui
        sizechooser.ui
)
# Поиск OpenMP
find_package(OpenMP)



add_executable(programm
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_FORMS}
)

target_link_libraries(programm PRIVATE Qt5::Gui Qt5::Widgets)

set_target_properties(programm PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

install(TARGETS programm
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

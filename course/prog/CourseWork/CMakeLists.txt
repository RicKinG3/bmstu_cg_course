cmake_minimum_required(VERSION 3.5)

project(CourseWork VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        ./drawer/abstract_drawer_factory.h
        ./drawer/qt_drawer_factory.h
        ./drawer/base_drawer.h
        ./drawer/qt_drawer.h
        ./visitor/draw_visitor.h
        ./visitor/visitor.h
        ./visitor/transform_visitor.h
        ./builder/camera/camera_builder.h
        ./builder/camera/base_camera_builder.h
        ./builder/model/base_model_builder.h
        ./builder/model/model_builder.h
        ./builder/base_builder.h
        ./config/base_config.h
        ./config/config_solution.h
        ./config/config.h
        ./ui_mainwindow.h
        ./transformer/base_transformer.h
        ./transformer/transformer.h
        ./transformer/transformer_factory.h
        ./transformer/base_transformer_factory.h
        ./transformer/matrix.h
        ./MainWindow.h
        ./scene/scene.h
        ./loader/camera/file_camera_loader.h
        ./loader/camera/camera_loader.h
        ./loader/loader_solution.h
        ./loader/base_loader.h
        ./loader/model/file_model_loader.h
        ./loader/model/model_loader.h
        ./exceptions/manager_exceptions.h
        ./exceptions/loader_exceptions.h
        ./exceptions/director_exceptions.h
        ./exceptions/base_exceptions.h
        ./exceptions/gui_exceptions.h
        ./exceptions/config_exceptions.h
        ./exceptions/builder_exceptions.h
        ./director/camera/camera_director.h
        ./director/base_load_director.h
        ./director/director_solution.h
        ./director/model/model_director.h
        ./managers/load/load_manager.h
        ./managers/draw/draw_manager.h
        ./managers/scene/scene_manager.h
        ./managers/transform/transform_manager.h
        ./managers/base_manager.h
        ./facade/facade.h
        ./objects/camera/camera.h
        ./objects/camera/base_camera.h
        ./objects/camera/camera_structure.h
        ./objects/object.h
        ./objects/composite/composite.h
        ./objects/primitives/point.h
        ./objects/primitives/edge.h
        ./objects/model/model.h
        ./objects/model/model_structure.h
        ./objects/model/frame_model.h
        ./commands/camera/camera_commands.h
        ./commands/scene/scene_commands.h
        ./commands/base_command.h
        ./commands/model/model_commands.h


        ./mainwindow.cpp
        ./drawer/qt_drawer.cpp
        ./drawer/qt_drawer_factory.cpp
        ./visitor/draw_visitor.cpp
        ./visitor/transform_visitor.cpp
        ./builder/camera/camera_builder.cpp
        ./builder/model/model_builder.cpp
        ./config/config.cpp
        ./config/config_solution.cpp
        ./transformer/matrix.cpp
        ./transformer/transformer_factory.cpp
        ./transformer/transformer.cpp
        ./scene/scene.cpp
        ./loader/camera/file_camera_loader.cpp
        ./loader/model/file_model_loader.cpp
        ./loader/loader_solution.cpp
        ./director/camera/camera_director.cpp
        ./director/director_solution.cpp
        ./director/model/model_director.cpp
        ./managers/load/load_manager.cpp
        ./managers/draw/draw_manager.cpp
        ./managers/scene/scene_manager.cpp
        ./managers/transform/transform_manager.cpp
        ./facade/facade.cpp
        ./objects/camera/camera_structure.cpp
        ./objects/camera/camera.cpp
        ./objects/composite/composite.cpp
        ./objects/primitives/edge.cpp
        ./objects/primitives/point.cpp
        ./objects/model/model_structure.cpp
        ./objects/model/frame_model.cpp
        ./main.cpp

        ./mainwindow.ui
        objects/primitives/face.cpp
        objects/primitives/face.h

)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CourseWork
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CourseWork1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CourseWork SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CourseWork
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CourseWork PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(CourseWork PRIVATE
        drawer
        facade
        managers
        managers/draw
        objects
        objects/primitives
)

set_target_properties(CourseWork PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CourseWork
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CourseWork)
endif()

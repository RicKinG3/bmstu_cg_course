# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.5)

# Устанавливаем имя проекта и его версию
project(src VERSION 0.1 LANGUAGES CXX)

# Включаем автоматическую генерацию файлов для ui, moc и rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Устанавливаем стандарт языка C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Устанавливаем директорию для сгенерированных ui_*.h файлов
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ui/header)
# Ищем компоненты Qt (Gui и Widgets)
find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)

# Список исходных файлов проекта
set(PROJECT_SOURCES
        main.cpp
        ui/mainwindow.cpp
        obj/objects.cpp
        graphics/specialgraphicsview.cpp
        facade/usagefacade.cpp
        obj/primitives/Polygon.cpp
        obj/primitives/Polygon.h
        obj/primitives/Vertex.cpp
        obj/primitives/Vertex.h
        obj/primitives/Point.cpp
        obj/primitives/Point.h
        obj/model/Model.cpp
        obj/model/Model.h
        obj/light/Light.cpp
        obj/light/Light.h

)

# Список заголовочных файлов проекта
set(PROJECT_HEADERS
        config/config.hpp
        ui/header/mainwindow.h
        obj/objects.hpp
        graphics/specialgraphicsview.hpp
        facade/usagefacade.hpp
        obj/primitives/Polygon.cpp
        obj/primitives/Polygon.h
        obj/primitives/Vertex.cpp
        obj/primitives/Vertex.h
        obj/primitives/Point.cpp
        obj/primitives/Point.h
        obj/model/Model.cpp
        obj/model/Model.h
        obj/light/Light.cpp
        obj/light/Light.h

)

# Список файлов формы проекта
set(PROJECT_FORMS
        ui/mainwindow.ui
)

# Генерация заголовочных файлов ui_*.h
qt5_wrap_ui(PROJECT_FORMS_HEADERS ${PROJECT_FORMS})

# Создание исполняемого файла
add_executable(src
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_FORMS}
        ${PROJECT_FORMS_HEADERS}  # Включаем сгенерированные ui_*.h файлы
)

target_include_directories(src PRIVATE
        ui/header
        graphics
        facade
        config
        obj
        obj/primitives
        obj/model
        obj/light
)

# Добавьте флаг OpenMP для компилятора
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
endif()

# Линковка с библиотеками Qt
target_link_libraries(src PRIVATE Qt5::Gui Qt5::Widgets)

# Установка свойств исполняемого файла
set_target_properties(src PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

# Установка файлов форм в директорию установки
install(FILES ${PROJECT_FORMS} DESTINATION ${CMAKE_INSTALL_PREFIX}/forms)

# Установка исполняемого файла
install(TARGETS src
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

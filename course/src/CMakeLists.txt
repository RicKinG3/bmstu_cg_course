# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.5)

# Устанавливаем имя проекта и его версию
project(programm VERSION 0.1 LANGUAGES CXX)

# Включаем автоматическую генерацию файлов для ui, moc и rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Устанавливаем стандарт языка C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Устанавливаем директорию для сгенерированных ui_*.h файлов
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Ищем компоненты Qt (Gui и Widgets)
find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)

# Список исходных файлов проекта
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

# Список заголовочных файлов проекта
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

# Список файлов формы проекта
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

# Поиск OpenMP (не используется в текущем коде)
find_package(OpenMP)

# Генерация заголовочных файлов ui_*.h
qt5_wrap_ui(PROJECT_FORMS_HEADERS ${PROJECT_FORMS})

# Создание исполняемого файла
add_executable(programm
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_FORMS}
        ${PROJECT_FORMS_HEADERS}  # Включаем сгенерированные ui_*.h файлы
)

# Линковка с библиотеками Qt
target_link_libraries(programm PRIVATE Qt5::Gui Qt5::Widgets)

# Установка свойств исполняемого файла
set_target_properties(programm PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

# Установка файлов форм в директорию установки
install(FILES ${PROJECT_FORMS} DESTINATION ${CMAKE_INSTALL_PREFIX}/forms)

# Установка исполняемого файла
install(TARGETS programm
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

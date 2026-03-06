cmake_minimum_required(VERSION 3.16)

project(fazbearclient VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt automático
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Buscar Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui)

# Ejecutable
add_executable(fazbearclient
    main.cpp
    resources.qrc

    # UI
    src/ui/mainwindow.cpp
    src/ui/mainwindow.h
    src/ui/mainwindow.ui

    # Pages
    src/ui/pages/homepage.cpp
    src/ui/pages/homepage.h
    src/ui/pages/homepage.ui

    src/ui/pages/gamespage.cpp
    src/ui/pages/gamespage.h
    src/ui/pages/gamespage.ui

    src/ui/pages/wikipage.cpp
    src/ui/pages/wikipage.h
    src/ui/pages/wikipage.ui

    src/ui/pages/settingspage.cpp
    src/ui/pages/settingspage.h
    src/ui/pages/settingspage.ui

    # Core
src/core/gamemanager.cpp
src/core/gamemanager.h

src/core/appmanager.cpp
src/core/appmanager.h

src/core/configmanager.cpp
src/core/configmanager.h

    # Utils
    src/utils/jsonutils.cpp
    src/utils/jsonutils.h
)

# Incluir carpeta src como raíz lógica
target_include_directories(fazbearclient PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link con Qt
target_link_libraries(fazbearclient
    PRIVATE Qt6::Widgets
    Qt6::Gui
)
cmake_minimum_required(VERSION 3.10)

project(LvlUpCLI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir todos los headers y fuentes desde src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.hpp")

add_executable(lvlup ${SOURCES} ${HEADERS})

# Buscar ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Enlazar ncurses al ejecutable
target_link_libraries(lvlup ${CURSES_LIBRARIES})
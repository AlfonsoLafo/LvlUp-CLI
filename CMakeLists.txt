cmake_minimum_required(VERSION 3.10)

project(LvlUpCLI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir todos los headers y fuentes desde src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/**/*.h")

# Crear el ejecutable
add_executable(lvlup ${SOURCES} ${HEADERS})

# Incluir directorio de headers personalizados
target_include_directories(lvlup PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Buscar ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Enlazar ncurses
target_link_libraries(lvlup ${CURSES_LIBRARIES})

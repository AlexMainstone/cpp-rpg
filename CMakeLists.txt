cmake_minimum_required(VERSION 3.0)
project(cpp-rpg)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)

# Statically Link SMFL
#add_compile_definitions(SFML_STATIC)

# Source
set(SRC
    src/Main.cpp
    
    # Scenes
    src/Scenes/Scene.hpp
    src/Scenes/Game.hpp
    src/Scenes/Game.cpp

    # Resources
    src/Resources/SpriteSheet.hpp
    src/Resources/SpriteSheet.cpp

    # World
    src/World/TileMap.hpp
    src/World/TileMap.cpp
)

# Directories
set(SFML_DIR "lib/SFML-2.5.1/build")

# Executable
add_executable(cpp-rpg ${SRC})

# SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Include & Link
target_link_libraries(cpp-rpg sfml-graphics sfml-audio)
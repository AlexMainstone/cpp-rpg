cmake_minimum_required(VERSION 3.0)
project(cpp-rpg)

set (CMAKE_CXX_STANDARD 11)

# Header files
list(APPEND HEADERS
    "${CMAKE_SOURCE_DIR}/include/Scenes/Scene.hpp"
    "${CMAKE_SOURCE_DIR}/include/Scenes/Game.hpp"
    
    "${CMAKE_SOURCE_DIR}/include/Resources/SpriteSheet.hpp"
    
    "${CMAKE_SOURCE_DIR}/include/World/TileMap.hpp"
    
    "${CMAKE_SOURCE_DIR}/include/Interface/Camera.hpp"
    "${CMAKE_SOURCE_DIR}/include/Interface/Console.hpp"
    "${CMAKE_SOURCE_DIR}/include/Interface/Party.hpp"

    "${CMAKE_SOURCE_DIR}/include/Entities/Entity.hpp"
    "${CMAKE_SOURCE_DIR}/include/Entities/Characters/PlayerCharacter.hpp"

    "${CMAKE_SOURCE_DIR}/include/System/Navigation.hpp"

    "${CMAKE_SOURCE_DIR}/include/Components/AnimatedSprite.hpp")

# Source Files
list(APPEND SOURCES
    "${CMAKE_SOURCE_DIR}/src/Main.cpp"
    
    "${CMAKE_SOURCE_DIR}/src/Scenes/Game.cpp"
    
    "${CMAKE_SOURCE_DIR}/src/Resources/SpriteSheet.cpp"
    
    "${CMAKE_SOURCE_DIR}/src/World/TileMap.cpp"
    
    "${CMAKE_SOURCE_DIR}/src/Interface/Camera.cpp"
    "${CMAKE_SOURCE_DIR}/src/Interface/Console.cpp"
    "${CMAKE_SOURCE_DIR}/src/Interface/Party.cpp"

    "${CMAKE_SOURCE_DIR}/src/Entities/Characters/PlayerCharacter.cpp"

    "${CMAKE_SOURCE_DIR}/src/Components/AnimatedSprite.cpp")

# Include Directories
list(APPEND INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/lib/imgui"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/lib/imgui-sfml")

source_group("Headers" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})

if (WIN32)
    #set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML-2.5.1/build")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics network audio REQUIRED)

add_executable(cpp-rpg ${SOURCES} ${HEADERS})

if(MSVC)
    target_compile_options(cpp-rpg PRIVATE /W4)
else()
    target_compile_options(cpp-rpg PRIVATE
            -Wall
            -Wextra # reasonable and standard
            -Wshadow # warn the user if a variable declaration shadows one from a parent context
            -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
            -Wold-style-cast # warn for c-style casts
            -Wcast-align # warn for potential performance problem casts
            -Wunused # warn on anything being unused
            -Woverloaded-virtual # warn if you overload (not override) a virtual function
            -Wpedantic # warn if non-standard C++ is used
            -Wconversion # warn on type conversions that may lose data
            -Wsign-conversion # warn on sign conversions
            -Wmisleading-indentation # warn if identation implies blocks where blocks do not exist
            -Wduplicated-cond # warn if if / else chain has duplicated conditions
            -Wduplicated-branches # warn if if / else branches have duplicated code
            -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
            -Wnull-dereference # warn if a null dereference is detected
            -Wuseless-cast # warn if you perform a cast to the same type
            -Wdouble-promotion # warn if float is implicit promoted to double
            -Wformat=2 # warn on security issues around functions that format output (ie printf)
            -std=c++17
            "$<$<CONFIG:DEBUG>:-DDEBUG>")
endif()

target_include_directories(cpp-rpg PRIVATE ${INCLUDE_DIRS})
target_link_libraries(cpp-rpg PRIVATE sfml-graphics sfml-audio sfml-network)
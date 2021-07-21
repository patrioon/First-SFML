cmake_minimum_required(VERSION 3.5)

project(Projekt_001 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# check for SFML dir
if(EXISTS "C:/SFML-2.5.1")
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
    link_directories("C:/SFML-2.5.1/lib")
    include_directories("C:/SFML-2.5.1/include")
endif()

# search for libraries
find_package(SFML COMPONENTS audio graphics system window REQUIRED)

# binaries po spacji dodwać
add_executable(Projekt_001 main.cpp Buttom.cpp Buttom.h)

# linking
target_link_libraries(Projekt_001 sfml-audio sfml-graphics sfml-system sfml-window)
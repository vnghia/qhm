# Project information
cmake_minimum_required(VERSION 3.16)
project(qhm LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Binary dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/bin)

# Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS DataVisualization)

# Add library
add_subdirectory(source)

# Add demo
add_subdirectory(demo)

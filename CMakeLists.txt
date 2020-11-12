cmake_minimum_required(VERSION 3.10)

project(tbsd_roguelike VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(CMakeConfig.h.in CMakeConfig.h)

add_subdirectory(lib/entityx)
include("cmake/CppServer.cmake")
# set(JSON_BuildTests OFF CACHE INTERNAL "")
# include("lib/json/CMakeLists.txt")
add_subdirectory(lib/json)

file(GLOB PROJECT_SOURCES 
  src/*.cpp src/*/*.cpp src/core/IO.cpp
  )
add_executable(tbsd_roguelike ${PROJECT_SOURCES})
target_link_libraries(tbsd_roguelike entityx)
target_link_libraries(tbsd_roguelike cppserver)
# add_library(tbsd_roguelike INTERFACE)
target_link_libraries(tbsd_roguelike nlohmann_json::nlohmann_json)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O1 -ggdb -Wno-unused-parameter")

target_include_directories(tbsd_roguelike PUBLIC
  "${PROJECT_BINARY_DIR}"
)

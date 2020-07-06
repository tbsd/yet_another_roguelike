cmake_minimum_required(VERSION 3.10)

project(rogues_party VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(CMakeConfig.h.in CMakeConfig.h)

add_subdirectory(lib/entityx)
include("cmake/CppServer.cmake")
# set(JSON_BuildTests OFF CACHE INTERNAL "")
# include("lib/json/CMakeLists.txt")
add_subdirectory(lib/json)

file(GLOB PROJECT_SOURCES 
  src/*.cpp src/*/*.cpp
  )
add_executable(rogues_party ${PROJECT_SOURCES})
target_link_libraries(rogues_party entityx)
target_link_libraries(rogues_party cppserver)
# add_library(rogues_party INTERFACE)
target_link_libraries(rogues_party nlohmann_json::nlohmann_json)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O1 -ggdb")

target_include_directories(rogues_party PUBLIC
  "${PROJECT_BINARY_DIR}"
)

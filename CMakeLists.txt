cmake_minimum_required(VERSION 3.10)

project(tbsd_roguelike VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(CMakeConfig.h.in CMakeConfig.h)

add_subdirectory(lib/entityx)
include("cmake/CppServer.cmake")
add_subdirectory(lib/json)

file(GLOB PROJECT_SOURCES 
  src/*.cpp src/*/*.cpp src/core/IO.cpp
  )
add_executable(tbsd_roguelike ${PROJECT_SOURCES} src/core/Tile.h src/core/BaseMap.cpp src/core/BaseMap.h src/core/Chunk.cpp src/core/Chunk.h src/core/ID.h src/component/Health.h src/core/Unit.h src/component/StatusEffects.h src/core/Action.h)
target_link_libraries(tbsd_roguelike entityx)
target_link_libraries(tbsd_roguelike cppserver)
target_link_libraries(tbsd_roguelike nlohmann_json::nlohmann_json)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O1 -ggdb -Wno-unused-parameter")

target_include_directories(tbsd_roguelike PUBLIC
  "${PROJECT_BINARY_DIR}"
)

set(FLATBUFFERS_SRC_DIR "lib/flatbuffers")
add_subdirectory(${FLATBUFFERS_SRC_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build
        EXCLUDE_FROM_ALL)
target_link_libraries(tbsd_roguelike flatbuffers)

set(FBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/core)
file(GLOB FBS_FILES "${FBS_PATH}/*.fbs")
set(FLATC "${CMAKE_CURRENT_SOURCE_DIR}/lib/flatbuffers/flatc")
# It seems like HEADERS_FROM_FBS cannot be to "" which is more sensible
# because then it won't run
set(HEADERS_FROM_FBS "workaround")
foreach(_fbs_file ${FBS_FILES})
    get_filename_component(_filename ${_fbs_file} NAME_WE)
    get_filename_component(_dir ${_fbs_file} DIRECTORY)
    list(APPEND GENERATD_HEADERS "${_dir}/${_filename}_generated.h")
endforeach()
message(STATUS ${HEADERS_FROM_FBS})
add_custom_command(OUTPUT ${HEADERS_FROM_FBS}
        COMMAND ${FLATC} --cpp --gen-object-api --gen-mutable --cpp-std c++17 ${FBS_FILES}
        WORKING_DIRECTORY "${FBS_PATH}"
        DEPENDS ${FLATC} ${FBS_FILES}
        COMMENT "Generating headers from .fbs files"
        VERBATIM
)
add_custom_target(generate_flatbuffers DEPENDS ${HEADERS_FROM_FBS})
add_dependencies(tbsd_roguelike generate_flatbuffers)

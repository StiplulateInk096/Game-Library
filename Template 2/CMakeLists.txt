cmake_minimum_required(VERSION 3.12)

project(Game)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ./engine/engine.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ./include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# The modern way, using cmake config files
#find_package(SDL2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

# The trusty old way, using pkg-config
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

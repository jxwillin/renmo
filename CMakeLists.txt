cmake_minimum_required(VERSION 3.16.3)

find_package(glfw3 3.3 REQUIRED)
add_subdirectory(3rd_party)

set(glad_include_dir "")
get_property(glad_include_dir GLOBAL PROPERTY GLAD_INCLUDE_DIR)
include_directories(${glad_include_dir})

project(renmo)
add_executable(renmo src/main.cpp src/context.cpp src/window.cpp)
target_include_directories(renmo PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(renmo 3rd_party::glad glfw3 X11)
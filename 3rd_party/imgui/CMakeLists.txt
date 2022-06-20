cmake_minimum_required(VERSION 3.16.3)

set_property(GLOBAL PROPERTY IMGUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends)

project(lib_imgui)
include_directories(imgui imgui/backends)
add_library(${PROJECT_NAME} imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp)
add_library(3rd_party::imgui ALIAS ${PROJECT_NAME})

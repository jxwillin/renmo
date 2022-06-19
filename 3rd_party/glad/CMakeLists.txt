cmake_minimum_required(VERSION 3.16.3)

set_property(GLOBAL PROPERTY GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

project(lib_glad)
include_directories(include)
add_library(${PROJECT_NAME} src/glad.c)
add_library(3rd_party::glad ALIAS ${PROJECT_NAME})
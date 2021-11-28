cmake_minimum_required(VERSION 3.20)
project(RexEngine)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(third_party/glfw)

if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(third_party/glfw/include)
include_directories(third_party/glm)
include_directories(third_party/glad/include)

set(GLAD_SOURCES third_party/glad/src/glad.c)
add_library(glad ${GLAD_SOURCES})

add_subdirectory(src)
cmake_minimum_required(VERSION 3.20)
project(RexEngine)

set(CMAKE_CXX_STANDARD 20)

include_directories(../third_party/glfw/include)
include_directories(../third_party/glad/include)
include_directories(../third_party/glm)

file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c??)
file(GLOB_RECURSE HEADER_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h??)

add_executable(engine ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(engine glad glfw)
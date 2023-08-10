cmake_minimum_required(VERSION 3.27.1)
project(perspective)
include_directories(../otherlib/)
include_directories(../otherlib/glad/)
include_directories(../otherlib/stb/)
include_directories(../otherlib/glm/)
add_executable(perspective perspective.cpp ../otherlib/src/glad.c stb_image.cpp)

target_link_libraries(perspective SDL2 dl)


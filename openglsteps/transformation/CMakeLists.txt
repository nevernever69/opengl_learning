cmake_minimum_required(VERSION 3.27.1)
project(rotatetex)
include_directories(../otherlib/)
include_directories(../otherlib/glad/)
include_directories(../otherlib/stb/)
include_directories(../otherlib/glm/)
add_executable(rotatetex rotatetex.cpp ../otherlib/src/glad.c stb_image.cpp)

target_link_libraries(rotatetex SDL2 dl)

project(movetex)
add_executable(movetex movetex.cpp ../otherlib/src/glad.c stb_image.cpp)

target_link_libraries(movetex SDL2 dl)


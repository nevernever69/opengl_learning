cmake_minimum_required(VERSION 3.27.1)
project(texture1)
include_directories(../otherlib/)
include_directories(../otherlib/glad/)
include_directories(../otherlib/stb/)
add_executable(texture1 texture1.cpp ../otherlib/src/glad.c stb_image.cpp)
target_link_libraries(texture1 SDL2 dl)

project(texture2)
add_executable(texture2 texture2.cpp ../otherlib/src/glad.c stb_image.cpp)
target_link_libraries(texture2 SDL2 dl)


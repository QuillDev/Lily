#CMakeLists.txt
cmake_minimum_required(VERSION 3.6)

#Make executable
project(Lily++)

#Link sleepy-discord
add_subdirectory(external/sleepy-discord)

add_executable(Lily++ Lily.cpp)

#Link sleepy-discord
target_link_libraries(Lily++ sleepy-discord)

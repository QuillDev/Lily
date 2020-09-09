#CMakeLists.txt
cmake_minimum_required(VERSION 3.6)

#Make executable
project(Lily++)

#Link sleepy-discord
add_subdirectory(external/sleepy-discord)

#
include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#Add the Lily++ executable
add_executable(Lily++ Lily.cpp)


#Link libraries
target_link_libraries(Lily++ PRIVATE sleepy-discord) #Link sleepy-discord
target_link_libraries(Lily++ PRIVATE nlohmann_json::nlohmann_json) #Link nlohmann_json
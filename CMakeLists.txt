cmake_minimum_required(VERSION 3.19)

include_directories(
    include
)
add_executable(
    winTool
    src/main.cpp
    src/WinUtils.cpp
    src/Wetchat.cpp
)
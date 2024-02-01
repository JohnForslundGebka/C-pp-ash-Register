cmake_minimum_required(VERSION 3.10)
project(C-pp-ash-Register VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(C-pp-ash-Register src/main.cpp)

target_include_directories(C-pp-ash-Register PUBLIC "${PROJECT_BINARY_DIR}" "include")


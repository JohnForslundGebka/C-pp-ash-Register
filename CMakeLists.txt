cmake_minimum_required(VERSION 3.10)
project(C-pp-ash-Register VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(C-pp-ash-Register src/main.cpp
        src/article.cpp
        src/menu.cpp
        src/databaseQueries.cpp
)

target_include_directories(C-pp-ash-Register PUBLIC "${PROJECT_BINARY_DIR}" "include")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/SQLiteCpp)

target_link_libraries(C-pp-ash-Register
        SQLiteCpp
        sqlite3
)


cmake_minimum_required(VERSION 3.10)
project(C-pp-ash-Register VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(C-pp-ash-Register src/main.cpp
        src/article.cpp
        src/menu.cpp
        src/databaseQueries.cpp
        src/clothing.cpp
        src/books.cpp
        src/laptops.cpp
        src/menuFunction.cpp
)

target_include_directories(C-pp-ash-Register PUBLIC "${PROJECT_BINARY_DIR}" "include")

#prompts the user to add the git submodule
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/lib/SQLiteCpp/.git")
    message(FATAL_ERROR "SQLiteCpp submodule does not exist. You must run 'git submodule update --init --recursive' to initialize it.")
else()
    message("-- SQLiteCpp submodule found.")
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/SQLiteCpp)

target_link_libraries(C-pp-ash-Register
        SQLiteCpp
        sqlite3
)

# Post-build command to copy database to the same directory as the executable
add_custom_command(TARGET C-pp-ash-Register POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/db/CashRegisterDB.db
        $<TARGET_FILE_DIR:C-pp-ash-Register>/CashRegisterDB.db)
cmake_minimum_required(VERSION 3.16.3)
project(minishell C)

set(CMAKE_C_STANDARD 99)

file(GLOB
        FC "src/*.c")

include_directories(./include)

link_directories(${CMAKE_SOURCE_DIR}/libmini)

link_directories(/Users/${USER}/.brew/Cellar/readline/8.1/lib/)

add_executable(minishell ${FC})

target_link_libraries(${PROJECT_NAME} mini readline)
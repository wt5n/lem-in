cmake_minimum_required(VERSION 3.17)
project(lem_in)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

set(SRC_OPERATIONS main.c)


add_executable(lem_in
        lem_in.h
        ${SRC_OPERATIONS})

add_subdirectory(libft)
target_link_libraries(lem_in libft)
cmake_minimum_required(VERSION 3.14)

project(push_swap)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SRC_OPERATIONS main.c queue.c)


add_executable(lem-in lem_in.h ${SRC_OPERATIONS})
add_executable(test test.c)

add_subdirectory(libft)
target_link_libraries(lem-in libft)
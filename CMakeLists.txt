cmake_minimum_required(VERSION 3.17)
project(lem_in)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SRC_OPERATIONS
        queue.c
        functions.c
        rooms.c
        links.c
        validation.c
        )

add_executable(lem_in
        lem_in.h
        main.c
        ${SRC_OPERATIONS})

add_executable(test
        test.c
        ${SRC_OPERATIONS})

add_executable(bfs
        bfs.c
        rooms.c
        links.c
        master_loop.c
        paths.c
        map.c
        ${SRC_OPERATIONS})


add_subdirectory(libft)
target_link_libraries(lem_in libft)
target_link_libraries(test libft)
target_link_libraries(bfs libft)
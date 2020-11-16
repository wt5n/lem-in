cmake_minimum_required(VERSION 3.17)
project(lem_in)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SRC
        queue.c
        functions.c
        rooms.c
        links.c
        validation.c
        validation_add.c
        ants.c
        lem_in.c
        rooms.c
        links.c
        paths.c
        map.c
        collisions.c
        frees.c
        bonus.c
        main.c)

add_executable(lem-in
        ${SRC} )


add_subdirectory(libft)
target_link_libraries(lem-in libft)
cmake_minimum_required(VERSION 3.17)
project(lem_in)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SRC
        src/queue.c
        src/functions.c
        src/rooms.c
        src/links.c
        src/validation.c
        src/validation_add.c
        src/ants.c
        src/lem_in.c
        src/rooms.c
        src/links.c
        src/paths.c
        src/map.c
        src/collisions.c
        src/frees.c
        src/bonus.c
        src/main.c)

add_executable(lem-in
        ${SRC} )


add_subdirectory(libft)
target_link_libraries(lem-in libft)
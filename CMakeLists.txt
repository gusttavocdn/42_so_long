cmake_minimum_required(VERSION 3.25)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(app/so_long.c include/so_long.h include/so_long.h app/so_long.c src/handle_key_events.c)

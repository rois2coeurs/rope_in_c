cmake_minimum_required(VERSION 3.26)
project(rope_in_c_tests C)

set(CMAKE_C_STANDARD 11)

add_executable(rope_in_c_tests
        rope.c
        rope.h
        ../tests/rope_tests.c
)

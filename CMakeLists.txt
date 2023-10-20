cmake_minimum_required(VERSION 3.10)
project(rope_in_c C)

# Crée l'éxécutable pour le bench
add_executable(bench
        src/rope.c
        src/rope.h
        app/bench.c)

# Crée l'éxécutable pour les tests
add_executable(tests
        src/rope.c
        src/rope.h
        test/rope_tests.c
        test/Unity/unity.c
        test/Unity/unity.h
        test/Unity/unity_internals.h)
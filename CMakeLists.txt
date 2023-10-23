cmake_minimum_required(VERSION 3.10)
project(rope_in_c C)

# Crée l'éxécutable pour le bench
add_executable(bench
        app/bench.c
        src/rope.c
        src/rope.h
        src/perso_string.c
        src/perso_string.h)

# Crée l'éxécutable pour les tests
add_executable(tests
        test/rope_tests.c
        test/Unity/unity.c
        test/Unity/unity.h
        test/Unity/unity_internals.h
        src/rope.c
        src/rope.h
        src/perso_string.c
        src/perso_string.h
        test/perso_string_tests.c
        test/tests_master.c
        test/rope_tests.h
        test/perso_string_tests.h)
cmake_minimum_required(VERSION 3.26)
project(Calculator C)

set(CMAKE_C_STANDARD 99)
add_executable(Calculator main.c
        CalcHeader.h
        StackCreating.c
        CalcAlgorithm.c
        Errors.c)

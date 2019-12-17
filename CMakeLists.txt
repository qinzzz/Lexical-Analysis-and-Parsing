cmake_minimum_required(VERSION 3.12)
project(2_parsing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2_parsing
        pl0.c
        pl0.h
        set.c
        set.h
        test.txt)

cmake_minimum_required(VERSION 3.24)
project(roman_numeral_v2 C)

set(CMAKE_C_STANDARD 99)

add_executable(roman_numeral_v2 main.c roman_numeral.c roman_numeral.h)

cmake_minimum_required(VERSION 3.26)
project(gate)

set(CMAKE_C_STANDARD 99)

set(SOURCE
  src/main.c)

add_executable(gate ${SOURCE})

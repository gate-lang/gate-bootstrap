cmake_minimum_required(VERSION 3.26)
project(gate)

set(CMAKE_C_STANDARD 99)

set(SOURCE
  vendor/log.c/src/log.h
  vendor/log.c/src/log.c

  src/util/args.h
  src/util/args.c
  
  src/main.c)

if (CMAKE_DEBUG)
  add_compile_options(
    "-DLOG_USE_COLOR"
    "-g"
  )
endif ()
add_executable(gate ${SOURCE})

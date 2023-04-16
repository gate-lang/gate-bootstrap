cmake_minimum_required(VERSION 3.26)
project(gate)

set(CMAKE_C_STANDARD 99)

add_library("log.c"
  vendor/log.c/src/log.h
  vendor/log.c/src/log.c)

add_library(gate_ui
  src/ui/args.h
  src/ui/args.c)
target_link_libraries(gate_ui PUBLIC "log.c")

add_library(gate_common
  src/common/linked_list.h
  src/common/linked_list.c
  src/common/list_tree.h
  src/common/list_tree.c)
target_link_libraries(gate_common PUBLIC "log.c")

if (CMAKE_DEBUG)
  add_compile_options(
    "-DLOG_USE_COLOR"
    "-g")

  enable_testing()
endif ()

add_executable(gate ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_link_libraries(gate PRIVATE "log.c" gate_ui gate_common)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/)

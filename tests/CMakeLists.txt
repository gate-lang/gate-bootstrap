add_executable(test_common_linked_list
  ${CMAKE_CURRENT_SOURCE_DIR}/base.h
  ${CMAKE_CURRENT_SOURCE_DIR}/common/linked_list.test.c)
target_link_libraries(test_common_linked_list PRIVATE gate_common)

add_executable(test_common_list_tree
  ${CMAKE_CURRENT_SOURCE_DIR}/base.h
  ${CMAKE_CURRENT_SOURCE_DIR}/common/list_tree.test.c)
target_link_libraries(test_common_linked_list PRIVATE gate_common)

add_test(NAME test_common_linked_list
  COMMAND $<TARGET_FILE:test_common_linked_list>)
add_test(NAME test_common_list_tree
  COMMAND $<TARGET_FILE:test_common_list_tree>)

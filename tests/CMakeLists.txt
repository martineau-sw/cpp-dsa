add_executable(llist_tests llist_tests.cc)
add_executable(dlist_tests dlist_tests.cc)
add_executable(stack_tests stack_tests.cc)
add_executable(queue_tests queue_tests.cc)

target_include_directories(llist_tests 
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/linked_list/
)

target_include_directories(dlist_tests 
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/doubly_linked_list/
)

target_include_directories(stack_tests
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/stack/
)

target_include_directories(queue_tests
  PRIVATE 
  ${PROJECT_SOURCE_DIR}/src/queue/
)

target_link_libraries(llist_tests PUBLIC 
  gtest_main
)

target_link_libraries(dlist_tests PUBLIC 
  gtest_main
)

target_link_libraries(stack_tests PUBLIC
  gtest_main
)

target_link_libraries(queue_tests PUBLIC
  gtest_main
)

target_set_warnings(
  TARGET llist_tests
  ENABLE ON 
  AS_ERRORS OFF
)

target_set_warnings(
  TARGET dlist_tests
  ENABLE ON
  AS_ERRORS OFF
)

target_set_warnings(
  TARGET stack_tests
  ENABLE ON
  AS_ERRORS OFF
)

target_set_warnings(
  TARGET queue_tests
  ENABLE ON
  AS_ERRORS OFF
)

add_test(
  NAME llist_tests
  COMMAND llist_tests
)

add_test(
  NAME dlist_tests
  COMMAND dlist_tests
)

add_test(
  NAME stack_tests
  COMMAND stack_tests
)

add_test(
  NAME queue_tests
  COMMAND queue_tests
)
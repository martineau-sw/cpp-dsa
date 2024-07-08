add_executable(list_tests test.cc)

target_include_directories(list_tests 
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/linked_list/
  ${PROJECT_SOURCE_DIR}/src/doubly_linked_list/
  )

include(Echos)
echo()

target_link_libraries(list_tests PUBLIC 
  gtest_main
)


target_set_warnings(
  TARGET list_tests
  ENABLE ON 
  AS_ERRORS OFF
)

add_test(
  NAME list_tests
  COMMAND list_tests
)
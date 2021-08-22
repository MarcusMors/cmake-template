find_package(Catch2 3 REQUIRED)

enable_testing()

project(tests)

add_executable(${PROJECT_NAME} tests.cpp)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC LIB_hello_world
  PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
#
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

include(CTest)
# catch_discover_tests(tests TEST_SPEC "Hello World!")

function(run_tests name executable)
  set(_test_state "${PROJECT_BINARY_DIR}/run_tests/${executable}.passed")
  add_custom_command(
    OUTPUT ${_test_state}
    COMMAND $<TARGET_FILE:${executable}>
    COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/run_tests"
    COMMAND ${CMAKE_COMMAND} -E touch ${_test_state}
    DEPENDS ${executable}
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
  add_custom_target(${name} ALL DEPENDS ${_test_state})
endfunction()

run_tests(run_hello_test ${PROJECT_NAME})
# [==[ source
# https://programmingrecluse.wordpress.com/2020/02/06/run-tests-when-building-with-cmake/
# ]==]

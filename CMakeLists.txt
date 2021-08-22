cmake_minimum_required(VERSION 3.12)

project(cmake_hello_world_lib VERSION 1.0.0)

option(BUILD_DOC "Build Documentation" ON)

macro(SUBDIRLIST result current_dir)
  file(
    GLOB children
    RELATIVE ${current_dir}
    ${current_dir}/*)
  set(dir_list "")
  foreach(child ${children})
    if(IS_DIRECTORY ${current_dir}/${child})
      list(APPEND dir_list ${child})
    endif()
  endforeach()
  set(${result} ${dir_list})
endmacro()

set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")

set(SUBDIRS)
subdirlist(PUBLIC_LIBS ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_INCLUDE_DIR})

message(STATUS "SUBDIRS : ${SUBDIRS}")

set(LIBS::DIRS hello_world)

add_subdirectory(${PROJECT_SOURCE_DIR})

add_subdirectory(${PROJECT_INCLUDE_DIR})

add_subdirectory(bin)

add_subdirectory(tests)

if(BUILD_DOC)
  add_subdirectory(docs-building/docs-doxygen)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#[============================================================================[
Resources:
- https://medium.com/practical-coding/c-documentation-with-doxygen-cmake-sphinx-breathe-for-those-of-use-who-are-totally-lost-7d555386fe13
- https://medium.com/practical-coding/c-documentation-with-doxygen-cmake-sphinx-breathe-for-those-of-use-who-are-totally-lost-part-2-21f4fb1abd9f
- https://uva-cs.github.io/pdr/tutorials/11-doxygen/index.html

#]============================================================================]

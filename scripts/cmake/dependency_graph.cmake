# Copyright (C) 2021 José Enrique Vilca Campana
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU Affero General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
# details.
#
# You should have received a copy of the GNU Affero General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.

find_program(DOT_EXE "dot")
mark_as_advanced(FORCE DOT_EXE)
if(DOT_EXE)
  message(STATUS "dot found: ${DOT_EXE}")
else()
  message(STATUS "dot not found!")
endif()

if(NOT DOT_EXE)
  option(
    BUILD_DEP_GRAPH
    "Builds a visual representation of the dependencies of that included targets"
    OFF)
else()
  option(
    BUILD_DEP_GRAPH
    "Builds a visual representation of the dependencies of that included targets"
    ON)
endif()

# Builds a dependency graph of the active code targets using the `dot`
# application
#
# This can only be used once per project, as each target generated is as
# `doc-${PROJECT_NAME}` unless TARGET_NAME is specified.
# ~~~
# Required Arguments:
# OUTPUT_TYPE
#   This is the output type, which doubles as the output file type, such as pdf, png.
#   This can be whatever the `dot` application allows.
#
# Options Arguments:
# ADD_TO_DEP_GRAPH
#   If specified, add this generated target to be a dependency of the more general
#   `dep-graph` target.
#
# TARGET_NAME <str>
#   The name to give the doc target. (Default: dep-graph-${PROJECT_NAME})
#
# OUTPUT_DIR <str>
#   The directory to place the generated output
# ~~~
function(gen_dep_graph OUTPUT_TYPE)
  set(OPTIONS ADD_TO_DEP_GRAPH)
  set(SINGLE_VALUE_KEYWORDS TARGET_NAME OUTPUT_DIR)
  set(MULTI_VALUE_KEYWORDS)
  cmake_parse_arguments(gen_dep_graph "${OPTIONS}" "${SINGLE_VALUE_KEYWORDS}"
                        "${MULTI_VALUE_KEYWORDS}" ${ARGN})

  if(BUILD_DEP_GRAPH)
    if(NOT DOT_EXE)
      message(FATAL_ERROR "`dot` is needed to build the dependency graph.")
    endif()

    if(gen_dep_graph_TARGET_NAME)
      set(TARGET_NAME ${gen_dep_graph_TARGET_NAME})
    else()
      set(TARGET_NAME dep-graph-${PROJECT_NAME})
    endif()

    if(gen_dep_graph_OUTPUT_DIR)
      set(OUT_DIR ${gen_dep_graph_OUTPUT_DIR})
    else()
      set(OUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
    endif()

    add_custom_target(
      ${TARGET_NAME}
      COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
              --graphviz=${CMAKE_CURRENT_BINARY_DIR}/graphviz/${TARGET_NAME}.dot
      COMMAND
        ${DOT_EXE} -T${OUTPUT_TYPE}
        ${CMAKE_CURRENT_BINARY_DIR}/graphviz/${TARGET_NAME}.dot -o
        ${OUT_DIR}/${TARGET_NAME}.${OUTPUT_TYPE})

    add_custom_command(
      TARGET ${TARGET_NAME}
      POST_BUILD
      COMMAND ;
      COMMENT
        "Dependency graph for ${TARGET_NAME} generated and located at ${OUT_DIR}/${TARGET_NAME}.${OUTPUT_TYPE}"
    )

    if(gen_dep_graph_ADD_TO_DEP_GRAPH)
      if(NOT TARGET dep-graph)
        add_custom_target(dep-graph)
      endif()

      add_dependencies(dep-graph ${TARGET_NAME})
    endif()
  endif()
endfunction()

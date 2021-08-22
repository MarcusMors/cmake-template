add_library(LIB_hello_world hello-world/hello_world.hpp
                            ../src/hello-world/hello_world.cpp)

target_include_directories(LIB_hello_world PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

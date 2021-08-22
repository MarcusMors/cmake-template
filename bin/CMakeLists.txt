add_executable(${CMAKE_PROJECT_NAME} ../src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC LIB_hello_world)

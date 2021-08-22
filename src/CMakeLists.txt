add_executable(main main.cpp)

# foreach(public_lib IN LIST PUBLIC_LIBS) foreach(file
# ${public_lib}/${SRC_FILES}) # find_file() if() list(APPEND SOURCE_FILES
# ${public_lib}/${file}.cpp ../${PROJECT_INCLUDE_DIR}/${public_lib}/${file}.hpp)

# endif() endforeach()

# endforeach()

# Create SOURCE_FILES foreach(file ${SRC_FILES}) list(APPEND SOURCE_FILES
# hello_world/${file}.cpp ../${PROJECT_INCLUDE_DIR}/hello_world/${file}.hpp)
# endforeach()

# Set up such that your IDE organizes the files correctly source_group(TREE
# ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

target_link_libraries(main PUBLIC LIB_hello_world)

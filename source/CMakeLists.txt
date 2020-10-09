aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/sorting SORTING_PATH)
add_executable(sorting ${SORTING_PATH})


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/vector VECTOR_PATH)
add_executable(vector ${VECTOR_PATH})

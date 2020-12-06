aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/sorting SORTING_PATH)
add_executable(sorting ${SORTING_PATH})


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/vector VECTOR_PATH)
add_executable(vector ${VECTOR_PATH})


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/list LIST_PATH)
add_executable(list ${LIST_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/stack STACK_PATH)
add_executable(stack  ${STACK_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/queue QUEUE_PATH)
add_executable(queue  ${QUEUE_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/tree TREE_PATH)
add_executable(tree  ${TREE_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/graph GRAPH_PATH)
add_executable(graph  ${GRAPH_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/binheap BINHEAP_PATH)
add_executable(binheap  ${BINHEAP_PATH})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
message("include path" ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/cut_rod CUT_ROD_PATH)
add_executable(cut_rod  ${CUT_ROD_PATH})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/matrix_chain_multiplication MTX_CHAIN_MULTI_PATH)
add_executable(matrix_chain_multiplication  ${MTX_CHAIN_MULTI_PATH})
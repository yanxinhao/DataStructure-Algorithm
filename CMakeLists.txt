cmake_minimum_required(VERSION 3.0.0)
project(DSA VERSION 0.1.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
message("include path" ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source)

# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

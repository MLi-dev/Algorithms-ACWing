cmake_minimum_required(VERSION 3.21)
project(Algorithms_ACWing)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("${PROJECT_SOURCE_DIR}/aw785_quicksort" "${PROJECT_SOURCE_DIR}/aw785_quicksort/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw786_quicksortfindk" "${PROJECT_SOURCE_DIR}/aw786_quicksortfindk/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw787_mergesort" "${PROJECT_SOURCE_DIR}/aw787_mergesort/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw788_inversepair" "${PROJECT_SOURCE_DIR}/aw788_inversepair/output" )
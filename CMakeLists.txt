cmake_minimum_required(VERSION 3.21)
project(Algorithms_ACWing)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("${PROJECT_SOURCE_DIR}/aw785_quicksort" "${PROJECT_SOURCE_DIR}/aw785_quicksort/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw786_quicksortfindk" "${PROJECT_SOURCE_DIR}/aw786_quicksortfindk/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw787_mergesort" "${PROJECT_SOURCE_DIR}/aw787_mergesort/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw788_inversepair" "${PROJECT_SOURCE_DIR}/aw788_inversepair/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw789_bs_range" "${PROJECT_SOURCE_DIR}/aw789_bs_range/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw790_bs_root_cubed" "${PROJECT_SOURCE_DIR}/aw790_bs_root_cubed/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw1097_flood_fill_lakes" "${PROJECT_SOURCE_DIR}/aw1097_flood_fill_lakes/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw1098_castle_rooms" "${PROJECT_SOURCE_DIR}/aw1098_castle_rooms/output" )
add_subdirectory("${PROJECT_SOURCE_DIR}/aw1106_peak_bfs" "${PROJECT_SOURCE_DIR}/aw1106_peak_bfs/output" )
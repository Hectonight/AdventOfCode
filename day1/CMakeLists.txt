cmake_minimum_required(VERSION 3.23)


project(Day1
        LANGUAGES CXX
)

add_executable(day1_part1 part1.cpp)
add_executable(day1_part2 part2.cpp)

add_custom_target(run_day1_part1
    COMMAND day1_part1 < ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    DEPENDS day1_part1
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(run_day1_part2
    COMMAND day1_part2 < ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    DEPENDS day1_part2
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


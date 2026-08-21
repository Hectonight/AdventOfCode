cmake_minimum_required(VERSION 3.23)


project(Day1
        LANGUAGES C
)

add_executable(day1_part1 part1.c)
add_executable(day1_part2 part2.c)

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


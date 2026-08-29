cmake_minimum_required(VERSION 3.23)


project(Day2
        LANGUAGES CXX
)

add_executable(day3_part1 part1.cpp)

add_custom_target(run_day3_part1
    COMMAND day3_part1 < ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    DEPENDS day3_part1
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(day3_part2 part2.cpp)

add_custom_target(run_day3_part2
        COMMAND day3_part2 < ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DEPENDS day3_part2
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

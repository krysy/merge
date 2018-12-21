cmake_minimum_required(VERSION 3.0)

project(merge LANGUAGES C)

add_executable(merge src/main.c src/list.c)
target_link_libraries(merge m)


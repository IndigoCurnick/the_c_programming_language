cmake_minimum_required(VERSION 3.30)

project(c_prog_lang)

include_directories(include)

add_subdirectory(src/chapter1)
add_subdirectory(src/chapter2)
add_subdirectory(src/chapter3)
add_subdirectory(src/chapter4)
add_subdirectory(src/chapter5)
add_subdirectory(src/chapter6)
add_subdirectory(src/chapter7)

add_executable(c_prog_lang src/main.c)

target_link_libraries(
    c_prog_lang 
    chapter1
    chapter2
    chapter3
    chapter4
    chapter5
    chapter6
    chapter7
)
target_link_libraries(c_prog_lang m)
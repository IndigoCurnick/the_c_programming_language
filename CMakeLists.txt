cmake_minimum_required(VERSION 3.30)

project(c_prog_lang)

include_directories(include)

add_subdirectory(src/chapter1)
add_subdirectory(src/chapter2)

add_executable(c_prog_lang src/main.c)

target_link_libraries(
    c_prog_lang 
    chapter1
    chapter2
)
target_link_libraries(c_prog_lang m)
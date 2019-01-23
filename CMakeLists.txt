cmake_minimum_required(VERSION 3.9)
project(discovering_modern_cpp_peter_gottschling_exercises)

set(CMAKE_CXX_STANDARD 14)

# Add each program seperatly here. First parm is name, second is path

add_executable(discovering_modern_cpp_peter_gottschling_exercises main.cpp)
add_executable(ch1_ex_1_age chapter_1/ex1_age/age.cpp)

add_executable(ch1_ex_2_1_declarations chapter_1/ex2_arrays_and_pointers/1_declarations.cpp)
add_executable(ch1_ex_2_2_stack chapter_1/ex2_arrays_and_pointers/2_stack.cpp)


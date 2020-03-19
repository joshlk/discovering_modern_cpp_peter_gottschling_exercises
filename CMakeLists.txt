cmake_minimum_required(VERSION 3.9)
project(discovering_modern_cpp_peter_gottschling_exercises)
set(CMAKE_CXX_STANDARD 14)

# Executable name then path to CPP file
add_executable(ex_1_age chapter_1/ex_1_age.cpp)
add_executable(exp_1.1 chapter_1/exp_1_1.cpp)
add_executable(ex_2_1_arrays_and_pointers_declarations chapter_1/ex_2_1_arrays_and_pointers_declarations.cpp)
add_executable(ex_2_2_arrays_and_pointers_stack chapter_1/ex_2_2_arrays_and_pointers_stack.cpp)

add_executable(ex_1_polynomial chapter_2/ex_1_polynomial.cpp)
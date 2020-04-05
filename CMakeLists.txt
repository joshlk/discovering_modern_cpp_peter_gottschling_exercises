cmake_minimum_required(VERSION 3.9)
project(discovering_modern_cpp_peter_gottschling_exercises)
set(CMAKE_CXX_STANDARD 14)

# Executable name then path to CPP file
add_executable(ex_1_age chapter_1_cpp_basics/ex_1_age.cpp)
add_executable(exp_1.1 chapter_1_cpp_basics/exp_1_1.cpp)
add_executable(ex_2_1_arrays_and_pointers_declarations chapter_1_cpp_basics/ex_2_1_arrays_and_pointers_declarations.cpp)
add_executable(ex_2_2_arrays_and_pointers_stack chapter_1_cpp_basics/ex_2_2_arrays_and_pointers_stack.cpp)

add_executable(ex_1_polynomial chapter_2_classes/ex_1_polynomial.cpp)
add_executable(sandbox chapter_3_generic_programming/sandbox.cpp)
add_executable(ex_1_string_representation chapter_3_generic_programming/ex_1_string_representation.cpp)
add_executable(ex_2_string_representation_of_tuples chapter_3_generic_programming/ex_2_string_representation_of_tuples.cpp)
add_executable(ex_3_generic_stack chapter_3_generic_programming/ex_3_generic_stack.cpp)
add_executable(iterator_of_a_vector chapter_3_generic_programming/ex_4_iterator_of_a_vector.cpp)
add_executable(ex_5_odd_iterator chapter_3_generic_programming/ex_5_and_6_odd_iterator.cpp)
add_executable(ex_9_deducing_non_type_template_arguments chapter_3_generic_programming/ex_9_deducing_non_type_template_arguments.cpp)
add_executable(ex_11_12_functor_lambda chapter_3_generic_programming/ex_11_12_functor_lambda.cpp)
add_executable(ex_1_sorting_by_magnitude chapter_4_libraries/ex_1_sorting_by_magnitude.cpp)
add_executable(ex_2_stl_container chapter_4_libraries/ex_2_stl_container.cpp)
add_executable(ex_1_type_traits.cpp chapter_5_meta_programming/ex_1_type_traits.cpp)

##### BEGIN: For chapter_4_libraries/mandelbrot.cpp you need to include SDL v1.2 for visualisation.
# First `brew install sdl` on MacOS
# Then added `FindSDL.cmake` file to cmake dir
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")
find_package (SDL REQUIRED)
include_directories (${SDL_INCLUDE_DIR}) # SDL v1.2 (not SDL v2)

add_executable(mandelbrot chapter_4_libraries/mandelbrot.cpp)
target_link_libraries(mandelbrot ${SDL_LIBRARY})
##### END
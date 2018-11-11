set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.0)
project(creditCardValidator)
add_subdirectory(src)
set_target_properties(
    creditCardValidator
    testTrie
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ..
)
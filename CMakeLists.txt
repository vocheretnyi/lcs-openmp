cmake_minimum_required(VERSION 3.13)
project(lcs_openmp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(lcs_openmp main.cpp timer.h)

target_compile_options(lcs_openmp PRIVATE -Wall -Wextra -std=c++17 -fopenmp)
target_link_options(lcs_openmp PRIVATE -fopenmp)
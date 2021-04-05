cmake_minimum_required(VERSION 3.17)
project(Diffraction)

set(CMAKE_CXX_STANDARD 11)

add_executable(Diffraction main.cpp function2d.cpp function2d.h Real.cpp Real.h Imaginary.cpp Imaginary.h)
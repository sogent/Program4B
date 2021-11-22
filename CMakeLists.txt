cmake_minimum_required(VERSION 3.20)
project(Program4B)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program4B main.cpp Media.cpp Media.h MediaLibrary.cpp MediaLibrary.h Book.cpp Book.h Movie.cpp Movie.h Song.cpp Song.h)

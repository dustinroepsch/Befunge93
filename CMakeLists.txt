cmake_minimum_required(VERSION 3.12)
project(Funge93)

set(CMAKE_CXX_STANDARD 14)

add_executable(Funge93 main.cpp src/FungeStack.cpp src/FungeStack.h src/FungeSpace.cpp src/FungeSpace.h src/FungeCoordinate.cpp src/FungeCoordinate.h)
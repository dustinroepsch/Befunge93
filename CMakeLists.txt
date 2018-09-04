cmake_minimum_required(VERSION 3.12)
project(Funge93)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Funge93 main.cpp src/FungeStack.cpp src/FungeStack.h src/FungeSpace.cpp src/FungeSpace.h src/FungeCoordinate.cpp src/FungeCoordinate.h src/FungeInterpreter.cpp src/FungeInterpreter.h)

target_link_libraries(Funge93 Boost::program_options)
cmake_minimum_required(VERSION 3.3)
project(mon)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    include)

add_executable(
    mon
    include/mon/test_case.hpp
    include/mon/test_failure.hpp
    include/mon/test_runner.hpp
    src/main.cpp
    src/mon.test_case.cpp
    src/mon.test_failure.cpp
    src/mon.test_runner.cpp)

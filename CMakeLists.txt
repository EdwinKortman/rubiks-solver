cmake_minimum_required(VERSION 2.6)
project(rubiks-solver)

find_package(Boost 1.59.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(rubiks-solver main.cpp)

install(TARGETS rubiks-solver RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.13)
project(distributed-agv)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${PROJECT_SOURCE_DIR}/hiredis/)

if(APPLE)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif(APPLE)

add_library(guidepy SHARED guidepy.cc guide.cc Astar.cc)

set_property(TARGET guidepy PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(guidepy PROPERTIES PREFIX "")

target_link_libraries(guidepy hiredis Python)


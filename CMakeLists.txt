cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp src/entity/entity.h src/position/position.h src/position/position.cpp src/entity/entity.cpp src/entity/fixed/fixed.h src/entity/fixed/piege/piege.h src/entity/moovable/moovable.cpp src/entity/moovable/moovable.h src/entity/moovable/fauve/lion/lion.h src/entity/moovable/fauve/lion/lion.cpp src/entity/moovable/fauve/tigre/tigre.h src/entity/moovable/fauve/tigre/tigre.cpp)

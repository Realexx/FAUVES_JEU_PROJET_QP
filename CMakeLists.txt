cmake_minimum_required(VERSION 3.24)
project(FAUVES_JEU_PROJET_QP)

set(CMAKE_CXX_STANDARD 17)

add_executable(FAUVES_JEU_PROJET_QP src/fauve.h src/lion.cpp src/lion.h src/tigre.cpp src/tigre.h src/position.cpp src/position.h src/JEU.h src/piege.cpp src/piege.h src/terrain.cpp src/terrain.h src/partie.cpp src/partie.h src/main.cpp src/application.cpp src/application.h)

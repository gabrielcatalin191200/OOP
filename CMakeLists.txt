cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP
        main.cpp src/Carte.cpp headers/Carte.h src/Autor.cpp headers/Autor.h src/Cititor.cpp headers/Cititor.h)

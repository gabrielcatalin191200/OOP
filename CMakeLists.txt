cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()

add_executable(OOP main.cpp src/Carte.cpp headers/Carte.h src/Autor.cpp headers/Autor.h src/Cititor.cpp headers/Cititor.h)

install(TARGETS OOP DESTINATION bin)

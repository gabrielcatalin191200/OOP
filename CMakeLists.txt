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

find_package(Threads REQUIRED)

add_executable(OOP main.cpp src/Carte.cpp headers/Carte.h src/Autor.cpp headers/Autor.h src/Cititor.cpp headers/Cititor.h src/Poezie.cpp headers/Poezie.h src/VolumPoezii.cpp headers/VolumPoezii.h src/Roman.cpp headers/Roman.h src/Nuvela.cpp headers/Nuvela.h src/PiesaDeTeatru.cpp headers/PiesaDeTeatru.h src/EroareCarte.cpp headers/EroareCarte.h src/CarteIndexata.cpp headers/CarteIndexata.h src/Filtru.cpp headers/Filtru.h src/EroareFiltru.cpp headers/EroareFiltru.h headers/csv.hpp src/SearchStrategy.cpp headers/SearchStrategy.h)

target_link_libraries(OOP PRIVATE Threads::Threads)

install(TARGETS OOP DESTINATION bin)
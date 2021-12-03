#include <iostream>

#include "../headers/Autor.h"

Autor::Autor(const std::string & numeAutor) {
    this->numeAutor = numeAutor;
}

Autor::Autor(const std::string & numeAutor, const std::vector<std::shared_ptr<Carte>> & opere) : numeAutor(numeAutor), opere(opere){}

Autor::Autor(const Autor & copie) : numeAutor(copie.numeAutor){
    for(const auto &carte: copie.opere)
        opere.push_back(carte->clone());
}

Autor &Autor::operator=(const Autor &copie) {
    if(this != &copie) {
        numeAutor = copie.numeAutor;
        auto opereAux = std::vector <std::shared_ptr <Carte>>();
        for(const auto &cantec: copie.opere) {
            opereAux.push_back(cantec->clone());
        }
        opere = opereAux;
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Autor & autor){
    os << "Nume autor: " << autor.numeAutor << "\n   Opere:\n";
    for(const auto & opera : autor.opere)
        os << '\t' << *opera;
    return os;
}

void Autor::adaugaCarte(const Carte& carte) {
    opere.push_back(carte.clone());
}
#include <iostream>

#include "../headers/Autor.h"

Autor::Autor(const std::string & _numeAutor, const std::vector<Carte> & _opere) {
    this->numeAutor = _numeAutor;
    this->opere = _opere;
}

Autor::Autor(const Autor & copie) {
    this->numeAutor = copie.numeAutor;
    this->opere = copie.opere;
}

Autor& Autor::operator=(const Autor & copie) {
    this->numeAutor = copie.numeAutor;
    this->opere = copie.opere;
    return *this;
}

std::ostream & operator<<(std::ostream & out, const Autor & autor){
    out << "Nume autor: " << autor.numeAutor << "\n   Opere:\n";
    for(const auto & opera : autor.opere)
        out << '\t' << opera;
    return out;
}

void Autor::adaugaCarte(const Carte& carte) {
    opere.push_back(carte);
}
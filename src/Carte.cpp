#include <iostream>

#include "../headers/Carte.h"

Carte::Carte(const std::string & _numeCarte, const std::string & _gen, int _anAparitie) {
    this->numeCarte = _numeCarte;
    this->gen = _gen;
    this->anAparitie = _anAparitie;
}

std::ostream & operator<<(std::ostream & os, const Carte & carte) {
    os << "Nume carte: " << carte.numeCarte << "\tGen: " << carte.gen << "\tAn aparitie: " << carte.anAparitie << "\n";
    return os;
}

bool Carte::get_disponibilitate() const {
    return disponibilitate;
}

void Carte::set_disponibilitate(bool _disponibilitate) {
    Carte::disponibilitate = _disponibilitate;
}

std::string Carte::get_numeCarte() const {
    return numeCarte;
}
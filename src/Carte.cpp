#include "../headers/Carte.h"

Carte::Carte(const std::string & numeCarte, const std::string & gen, int anAparitie) {
    this->numeCarte = numeCarte;
    this->gen = gen;
    this->anAparitie = anAparitie;
}

Carte::Carte(const Carte &copie) {
    this->numeCarte = copie.numeCarte;
    this->gen = copie.gen;
    this->anAparitie = copie.anAparitie;
    this->disponibilitate = copie.disponibilitate;
}

Carte& Carte::operator=(const Carte & copie) {
    this->numeCarte = copie.numeCarte;
    this->gen = copie.gen;
    this->anAparitie = copie.anAparitie;
    this->disponibilitate = copie.disponibilitate;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Carte & carte) {
    carte.afis(os);
    os << '\n';
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

Carte::~Carte() {
//    std::cout << "Destructor carte\n";
}

void Carte::afis(std::ostream &os) const {
    const auto &carte = *this;
    os << "Cartea se numeste " << carte.numeCarte << " apartine genului " << carte.gen << " si a aparut in anul " << carte.anAparitie;
}

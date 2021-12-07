#include "../headers/Carte.h"

Carte::Carte(const std::string & numeCarte, const std::string & gen, int anAparitie) : numeCarte(numeCarte), gen(gen), anAparitie(anAparitie) {
    if(anAparitie > 2021)
        throw AnGresit();
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

std::string Carte::get_gen() const {
    return gen;
}

int Carte::get_anAparitie() const {
    return anAparitie;
}

Carte::~Carte() {
//    std::cout << "Destructor carte\n";
}

void Carte::afis(std::ostream &os) const {
    const auto &carte = *this;
    os << "Cartea se numeste \"" << carte.numeCarte << "\", apartine genului " << carte.gen << " si a aparut in anul " << carte.anAparitie;
}

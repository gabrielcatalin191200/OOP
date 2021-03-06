#include "../headers/CarteIndexata.h"

CarteIndexata::CarteIndexata(const std::string &numeCarteI, const std::string &numeAutorI, const std::string &genI, const std::string &anAparitieI) : numeCarteI(numeCarteI), numeAutorI(numeAutorI), genI(genI), anAparitieI(anAparitieI) {}

const std::string &CarteIndexata::getNumeCarteI() const {
    return numeCarteI;
}

const std::string &CarteIndexata::getNumeAutorI() const {
    return numeAutorI;
}

const std::string &CarteIndexata::getGenI() const {
    return genI;
}

const std::string &CarteIndexata::getAnAparitieI() const {
    return anAparitieI;
}

std::ostream &operator<<(std::ostream &os, const CarteIndexata &carte) {
    os << "Cartea " << carte.getNumeCarteI() << " scrisa de " << carte.getNumeAutorI() << " apartinand genului " << carte.getGenI() << " aparuta in anul " << carte.getAnAparitieI() << ".\n";
    return os;
}

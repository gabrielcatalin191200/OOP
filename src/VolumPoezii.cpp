#include "../headers/VolumPoezii.h"

VolumPoezii::VolumPoezii(const std::string &numeCarte, const std::string &gen, int anAparitie) : Carte(numeCarte, gen, anAparitie) {}

VolumPoezii::VolumPoezii(const std::string &numeCarte, const std::string &gen, int anAparitie, const std::vector<Poezie> &poezii) : Carte(numeCarte, gen, anAparitie), poezii(poezii) {}

VolumPoezii::~VolumPoezii() {
//    std::cout << "Destructor VolumPoezii";
}

std::ostream &operator<<(std::ostream& os, const VolumPoezii& volum) {
    os << "Nume carte: " << volum.numeCarte << "\tGen: " << volum.gen << "\tAn aparitie: " << volum.anAparitie << " si contine:\n";
    for(const auto & poezie : volum.poezii)
        os << '\t' << poezie;
    return os;
}

void VolumPoezii::adaugaPoezie(const Poezie &poezie) {
    poezii.push_back(poezie);
}

std::shared_ptr<Carte> VolumPoezii::clone() const {
    return std::make_shared<VolumPoezii>(*this);
}


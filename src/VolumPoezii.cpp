#include "../headers/VolumPoezii.h"

VolumPoezii::VolumPoezii(const std::string &numeCarte, const std::string &gen, int anAparitie) : Carte(numeCarte, gen, anAparitie) {
    if(gen != "liric")
        throw GenGresit();
}

VolumPoezii::VolumPoezii(const std::string &numeCarte, const std::string &gen, int anAparitie, const std::vector<Poezie> &poezii) : Carte(numeCarte, gen, anAparitie), poezii(poezii) {
    if(gen != "liric")
        throw GenGresit();
}

VolumPoezii::~VolumPoezii() {
//    std::cout << "Destructor VolumPoezii";
}

//std::ostream &operator<<(std::ostream& os, const VolumPoezii& volum) {
//    volum.afis(os);
//    return os;
//}

void VolumPoezii::adaugaPoezie(const Poezie &poezie) {
    poezii.push_back(poezie);
}

std::shared_ptr<Carte> VolumPoezii::clone() const {
    return std::make_shared<VolumPoezii>(*this);
}

void VolumPoezii::afis(std::ostream &os) const {
    const auto &volum = *this;
    Carte::afis(os);
    os << ". Contine " << volum.poezii.size() << " poezii:\n";
    for(const auto & poezie : volum.poezii)
        os << "\t\t" << poezie;
}


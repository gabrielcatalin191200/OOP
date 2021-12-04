#include "../headers/Roman.h"

Roman::Roman(const std::string &numeRoman, const std::string &gen, int anAparitie, int numarCapitole) : Carte(numeRoman, gen, anAparitie), numarCapitole(numarCapitole) {}

Roman::~Roman() {
//    std::cout << "Destructor Roman";
}

std::shared_ptr<Carte> Roman::clone() const {
    return std::make_shared<Roman>(*this);
}

void Roman::afis(std::ostream &os) const {
    const auto &roman = *this;
    Carte::afis(os);
    os << ". Este alcatuita din " << roman.numarCapitole << " capitole.";
}
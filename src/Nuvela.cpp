#include "../headers/Nuvela.h"

Nuvela::Nuvela(const std::string &numeNuvela, const std::string &gen, int anAparitie, int numarPagini) : Carte(numeNuvela, gen, anAparitie), numarPagini(numarPagini) {
    if(gen != "epic")
        throw GenGresit();
}

Nuvela::~Nuvela() {
//    std::cout << "Destructor Nuvela";
}

std::shared_ptr<Carte> Nuvela::clone() const {
    return std::make_shared<Nuvela>(*this);
}

void Nuvela::afis(std::ostream &os) const {
    const auto &nuvela = *this;
    Carte::afis(os);
    os << ". Are " << nuvela.numarPagini << " pagini.";
}

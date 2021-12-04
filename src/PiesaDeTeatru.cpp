#include "../headers/PiesaDeTeatru.h"

PiesaDeTeatru::PiesaDeTeatru(const std::string &numePiesa, const std::string &gen, int anAparitie, int numarActe) : Carte(numePiesa, gen, anAparitie), numarActe(numarActe) {}

PiesaDeTeatru::~PiesaDeTeatru() {
//    std::cout << "Destructor PiesaDeTeatru";
}

std::shared_ptr<Carte> PiesaDeTeatru::clone() const {
    return std::make_shared<PiesaDeTeatru>(*this);
}

void PiesaDeTeatru::afis(std::ostream &os) const {
    const auto &piesa = *this;
    Carte::afis(os);
    os << ". Este alcatuita din " << piesa.numarActe << " acte.";
}
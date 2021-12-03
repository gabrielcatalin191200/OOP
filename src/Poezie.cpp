#include "../headers/Poezie.h"

Poezie::Poezie(const std::string &numePoezie, int anulAparitiei, int numarVersuri) : numePoezie(numePoezie), anulAparitiei(anulAparitiei), numarVersuri(numarVersuri) {}

std::ostream &operator<<(std::ostream &os, const Poezie &poezie) {
    os << "Poezia \"" << poezie.numePoezie << "\" care a aparut in anul " << poezie.anulAparitiei << " si are " << poezie.numarVersuri << " versuri.\n";
    return os;
}
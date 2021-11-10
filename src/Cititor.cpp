#include <iostream>

#include "../headers/Cititor.h"

Cititor::Cititor(const std::string & _nume, const std::string & _prenume) {
    this->nume = _nume;
    this->prenume = _prenume;
}

std::ostream & operator<<(std::ostream & os, const Cititor & cititor) {
    if (cititor.cartiImprumutate.empty()){
        os << "Cititorul " << cititor.nume << " " << cititor.prenume << " nu a imprumutat nicio carte!" << '\n';
    } else if (cititor.cartiImprumutate.size() == 1) {
        os << "Cititorul " << cititor.nume << " " << cititor.prenume << " a imprumutat o carte:\n";
        os << "\t-" << cititor.cartiImprumutate[0].get_numeCarte() << '\n';
    } else {
        os << "Cititorul " << cititor.nume << " " << cititor.prenume << " a imprumutat " << cititor.cartiImprumutate.size() << " carti:\n";
        for (int i=0; i<cititor.cartiImprumutate.size(); i++)
            os << "\t-" << cititor.cartiImprumutate[i].get_numeCarte() << '\n';
    }
    return os;
}

void Cititor::imprumuta(Carte & carte) {
    if(carte.get_disponibilitate()) {
        cartiImprumutate.push_back(carte);
        carte.set_disponibilitate(false);
    }
    else
        std::cout << "Cartea \"" << carte.get_numeCarte() << "\" nu este disponibila.\n";
}

void Cititor::returneaza(Carte & carte) {
    for(int i=0; i < this->cartiImprumutate.size(); i++) {
        if (this->cartiImprumutate[i].get_numeCarte() == carte.get_numeCarte()) {
            carte.set_disponibilitate(true);
            cartiImprumutate.erase(cartiImprumutate.begin() + i);
        }
    }
}
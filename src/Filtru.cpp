#include "../headers/Filtru.h"

Filtru::Filtru(const std::string &tipCautare, const std::string &keyWord) : tipCautare(tipCautare), keyWord(keyWord) {}

void Filtru::aplica(std::vector<CarteIndexata> &rezultat){
    std::cout << "..................................................\n\n\n";
    std::cout << rezultat.size();
    if(this->tipCautare == "Nume Autor")
        for(int i=0; i<(int)rezultat.size(); i++) {
            if(rezultat[i].getNumeAutorI() != this->keyWord)
                rezultat.erase(rezultat.begin() + i);
        }
    std::cout << "\n.........................................\n";
    std::cout << rezultat.size();
}
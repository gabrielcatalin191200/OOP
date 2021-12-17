#include "../headers/Filtru.h"

Filtru::Filtru(const std::string &tipCautare, const std::string &keyWord) : tipCautare(tipCautare), keyWord(keyWord) {}

std::vector<CarteIndexata> Filtru::aplica(std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;

    if(this->tipCautare == "Nume autor") {
        for(auto & i : rezultat) {
            if(i.getNumeAutorI() == this->keyWord)
                temp.push_back(i);
        }
    } else if(this->tipCautare == "Nume carte") {
        for(auto & i : rezultat) {
            if(i.getNumeCarteI() == this->keyWord)
                temp.push_back(i);
        }
    } else if(this->tipCautare == "An aparitie") {
        for(auto & i : rezultat) {
            if(i.getAnAparitieI() == this->keyWord)
                temp.push_back(i);
        }
    } else if(this->tipCautare == "Gen") {
        for(auto & i : rezultat) {
            if(i.getGenI() == this->keyWord)
                temp.push_back(i);
        }
    } else {
        throw FiltruInvalid();
    }

    return temp;
}
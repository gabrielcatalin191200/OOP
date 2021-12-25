#include "../headers/SearchStrategy.h"

std::vector<CarteIndexata> CautareNumeAutor::Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;

    for(auto & i : rezultat) {
        if(i.getNumeAutorI() == keyWord)
            temp.push_back(i);
    }

    return temp;
}

std::vector<CarteIndexata> CautareNumeCarte::Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;

    for(auto & i : rezultat) {
        if(i.getNumeCarteI() == keyWord)
            temp.push_back(i);
    }

    return temp;
}

std::vector<CarteIndexata> CautareAnAparitie::Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;

    for(auto & i : rezultat) {
        if(i.getAnAparitieI() == keyWord)
            temp.push_back(i);
    }

    return temp;
}

std::vector<CarteIndexata> CautareGen::Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;

    for(auto & i : rezultat) {
        if(i.getGenI() == keyWord)
            temp.push_back(i);
    }

    return temp;
}

SearchStrategy::~SearchStrategy() {

}

#include "../headers/SearchStrategy.h"

bool CautareNumeCarte::match(const CarteIndexata& carte, const std::string& keyword) {
    return carte.getNumeCarteI() == keyword;
}

bool CautareNumeAutor::match(const CarteIndexata& carte, const std::string& keyword) {
    return carte.getNumeAutorI() == keyword;
}

bool CautareAnAparitie::match(const CarteIndexata& carte, const std::string& keyword) {
    return carte.getAnAparitieI() == keyword;
}

bool CautareGen::match(const CarteIndexata& carte, const std::string& keyword) {
    return carte.getGenI() == keyword;
}

std::vector<CarteIndexata> SearchStrategy::Cautare(const std::string& keyWord, std::vector<CarteIndexata> &rezultat) {
    std::vector<CarteIndexata> temp;
    for(const auto& i:rezultat) {
        if(match(i, keyWord))
            temp.push_back(i);
    }
    return temp;
}

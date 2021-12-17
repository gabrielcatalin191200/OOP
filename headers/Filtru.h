#ifndef OOP_FILTRU_H
#define OOP_FILTRU_H

#include <vector>
#include <memory>
#include "CarteIndexata.h"
#include "EroareFiltru.h"

class Filtru {
private:
    std::string tipCautare;
    std::string keyWord;
public:
    Filtru(const std::string &tipCautare, const std::string &keyWord);
    std::vector<CarteIndexata> aplica(std::vector<CarteIndexata> &rezultat);
};

#endif //OOP_FILTRU_H

#ifndef OOP_SEARCHSTRATEGY_H
#define OOP_SEARCHSTRATEGY_H

#include <vector>
#include "CarteIndexata.h"
#include "Filtru.h"

class SearchStrategy {
public:
    virtual ~SearchStrategy();
    virtual std::vector<CarteIndexata> Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) = 0;
};

class CautareNumeCarte : public SearchStrategy {
public:
    std::vector<CarteIndexata> Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) override;
};

class CautareNumeAutor : public SearchStrategy {
public:
    std::vector<CarteIndexata> Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) override;
};

class CautareAnAparitie : public SearchStrategy {
public:
    std::vector<CarteIndexata> Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) override;
};

class CautareGen : public SearchStrategy {
public:
    std::vector<CarteIndexata> Cautare(std::string keyWord, std::vector<CarteIndexata> &rezultat) override;
};

#endif //OOP_SEARCHSTRATEGY_H

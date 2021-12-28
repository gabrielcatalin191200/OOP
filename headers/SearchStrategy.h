#ifndef OOP_SEARCHSTRATEGY_H
#define OOP_SEARCHSTRATEGY_H

#include <vector>
#include "CarteIndexata.h"
#include "Filtru.h"

class SearchStrategy {
private:
    virtual bool match(const CarteIndexata& carte, const std::string& keyword) = 0;
public:
    virtual ~SearchStrategy() = default;
    virtual std::vector<CarteIndexata> Cautare(const std::string& keyWord, std::vector<CarteIndexata> &rezultat);
};

class CautareNumeCarte : public SearchStrategy {
private:
    bool match(const CarteIndexata& carte, const std::string& keyword) override;
};

class CautareNumeAutor : public SearchStrategy {
private:
    bool match(const CarteIndexata& carte, const std::string& keyword) override;
};

class CautareAnAparitie : public SearchStrategy {
private:
    bool match(const CarteIndexata& carte, const std::string& keyword) override;
};

class CautareGen : public SearchStrategy {
private:
    bool match(const CarteIndexata& carte, const std::string& keyword) override;
};

#endif //OOP_SEARCHSTRATEGY_H

#ifndef OOP_CARTEINDEXATA_H
#define OOP_CARTEINDEXATA_H

#include <iostream>
#include <string>
#include <vector>

class CarteIndexata {
private:
    std::string numeCarteI;
    std::string numeAutorI;
    std::string genI;
    std::string anAparitieI;
public:
    CarteIndexata(const std::string &numeCarteI, const std::string &numeAutorI, const std::string &genI, const std::string &anAparitieI);

    const std::string &getNumeCarteI() const;
    const std::string &getNumeAutorI() const;
    const std::string &getGenI() const;
    const std::string &getAnAparitieI() const;
};

#endif //OOP_CARTEINDEXATA_H

#ifndef OOP_CITITOR_H
#define OOP_CITITOR_H

#include <string>
#include <vector>

#include "./Carte.h"

class Cititor {
private:
    std::string nume;
    std::string prenume;
    std::vector<Carte> cartiImprumutate;
public:
    Cititor(const std::string & nume, const std::string & prenume);

    ~Cititor() = default;

    friend std::ostream & operator<<(std::ostream & os, const Cititor & cititor);

    void imprumuta(Carte & carte);

    void returneaza(Carte & carte);
};

#endif //OOP_CITITOR_H

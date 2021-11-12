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
    std::vector<Carte> cartiCitite;
public:
    Cititor() = default;

    Cititor(const std::string & nume, const std::string & prenume);

    ~Cititor() = default;

    friend std::ostream & operator<<(std::ostream & os, const Cititor & cititor);

    void imprumuta(Carte & carte);

    void returneaza(Carte & carte);

    void rezerva(Carte & carte);

    bool verificaRezervare(const Carte & carte);
};

#endif //OOP_CITITOR_H
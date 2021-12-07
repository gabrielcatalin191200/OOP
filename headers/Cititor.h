#ifndef OOP_CITITOR_H
#define OOP_CITITOR_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

#include "./Carte.h"
#include "./Cautare.h"

class Cititor {
private:
    const int id;
    static int id_max;
    std::string nume;
    std::string prenume;
    std::vector<std::shared_ptr<Carte>> cartiImprumutate;
    std::vector<std::shared_ptr<Carte>> cartiCitite;
public:
    Cititor(const std::string & nume, const std::string & prenume);
    ~Cititor() = default;

    friend std::ostream & operator<<(std::ostream & os, const Cititor & cititor);

    void imprumuta(Carte & carte);
    void returneaza(Carte & carte);
    void rezerva(Carte & carte);
    bool verificaRezervare(const Carte & carte);

    static int getIdMax();

    void cautaCarte(const std::string &cuvantCheie, const std::string &filtru);
};

#endif //OOP_CITITOR_H
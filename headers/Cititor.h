#ifndef OOP_CITITOR_H
#define OOP_CITITOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "Carte.h"
#include "csv.hpp"
#include "CarteIndexata.h"
#include "Filtru.h"
#include "SearchStrategy.h"
#include "EroareFiltru.h"

class Cititor {
private:
    const int id;
    static int id_max;
    std::string nume;
    std::string prenume;
    int varsta;
    std::string strada;
    std::vector<std::shared_ptr<Carte>> cartiImprumutate;
    std::vector<std::shared_ptr<Carte>> cartiCitite;
public:
    Cititor(const std::string& nume, const std::string& prenume, int varsta, const std::string& strada);

    friend std::ostream & operator<<(std::ostream & os, const Cititor & cititor);

    void setNume(const std::string &nume);
    const std::string &getNume() const;

    void setPrenume(const std::string &prenume);
    const std::string &getPrenume() const;

    void setVarsta(int varsta);
    int getVarsta() const;

    void setStrada(const std::string &strada);
    const std::string &getStrada() const;

    void imprumuta(Carte & carte);
    void returneaza(Carte & carte);
    void rezerva(Carte & carte);
    bool verificaRezervare(const Carte & carte);

    std::vector<CarteIndexata> cauta(std::vector<Filtru> filtre);
};

#endif //OOP_CITITOR_H

#ifndef OOP_CITITORBUILDER_H
#define OOP_CITITORBUILDER_H

#include <string>
#include "Cititor.h"

class CititorBuilder {
private:
    std::string nume;
    std::string prenume;
    int varsta;
    std::string strada;
public:
    CititorBuilder();
    CititorBuilder& adaugaNume(const std::string& nume);
    CititorBuilder& adaugaPrenume(const std::string& prenume);
    CititorBuilder& adaugaVarsta(int varsta);
    CititorBuilder& adaugaStrada(const std::string& strada);
    Cititor build();

};

#endif //OOP_CITITORBUILDER_H

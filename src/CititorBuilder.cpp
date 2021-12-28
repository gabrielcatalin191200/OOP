#include "../headers/CititorBuilder.h"

CititorBuilder::CititorBuilder() {}

CititorBuilder& CititorBuilder::adaugaNume(const std::string &nume) {
    this->nume = nume;
    return *this;
}

CititorBuilder& CititorBuilder::adaugaPrenume(const std::string &prenume) {
    this->prenume = prenume;
    return *this;
}

CititorBuilder& CititorBuilder::adaugaVarsta(int varsta) {
    this->varsta = varsta;
    return *this;
}

CititorBuilder& CititorBuilder::adaugaStrada(const std::string &strada) {
    this->strada = strada;
    return *this;
}

Cititor CititorBuilder::build() {
    return Cititor(nume, prenume, varsta, strada);
}


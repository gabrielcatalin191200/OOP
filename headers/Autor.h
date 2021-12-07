#ifndef OOP_AUTOR_H
#define OOP_AUTOR_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

#include "Carte.h"

class Autor {
private:
    std::string numeAutor;
    std::vector<std::shared_ptr<Carte>> opere;
public:
    Autor(const std::string & numeAutor);
    Autor(const std::string & numeAutor, const std::vector<std::shared_ptr<Carte>> & opere);
    Autor(const Autor & copie);
    Autor & operator=(const Autor & copie);
    ~Autor() = default;

    friend std::ostream & operator<<(std::ostream & os, const Autor & autor);

    void adaugaCarte(const Carte& carte);
};

#endif //OOP_AUTOR_H
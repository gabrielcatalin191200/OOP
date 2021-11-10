#ifndef OOP_AUTOR_H
#define OOP_AUTOR_H

#include <string>
#include <vector>

#include "Carte.h"

class Autor {
private:
    std::string numeAutor;
    std::vector<Carte> opere;
public:
    Autor(const std::string & numeAutor, const std::vector<Carte> & opere);

    Autor(const Autor & copie);

    Autor & operator=(const Autor & copie);

    ~Autor() = default;

    friend std::ostream & operator<<(std::ostream & out, const Autor & autor);

    void adaugaCarte(const Carte& carte);
};

#endif //OOP_AUTOR_H

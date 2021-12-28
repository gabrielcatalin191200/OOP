#ifndef OOP_AUTOR_H
#define OOP_AUTOR_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

#include "Carte.h"

template<typename T> class Autor;
template<typename T> std::ostream& operator<<(std::ostream& os, const Autor<T>& autor);

template<typename T>
class Autor {
private:
    T numeAutor;
    std::vector<std::shared_ptr<Carte>> opere;
public:
    Autor(const T & numeAutor);
    Autor(const T & numeAutor, const std::vector<std::shared_ptr<Carte>> & opere);
    Autor(const Autor<T> & copie);
    Autor & operator=(const Autor<T> & copie);
    ~Autor() = default;

    friend std::ostream & operator<< <>(std::ostream & os, const Autor<T>& autor);

    void adaugaCarte(const Carte& carte);
};

#endif //OOP_AUTOR_H
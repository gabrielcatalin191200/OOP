#ifndef OOP_CARTE_H
#define OOP_CARTE_H

#include <iostream>
#include <string>
#include <memory>

#include "EroareCarte.h"

class Carte {
protected:
    std::string numeCarte;
    std::string gen;
    int anAparitie;
    bool disponibilitate = true;
public:
    Carte() = default;

    Carte(const std::string & numeCarte, const std::string & gen, int anAparitie);
    Carte(const Carte & copie);
    Carte & operator=(const Carte & copie);
    virtual ~Carte() = 0;

    friend std::ostream & operator<<(std::ostream & os, const Carte & carte);

    bool get_disponibilitate() const;
    void set_disponibilitate(bool disponibilitate);

    std::string get_numeCarte() const;

    virtual std::shared_ptr<Carte> clone() const = 0;
    virtual void afis(std::ostream &os) const;
};

#endif //OOP_CARTE_H
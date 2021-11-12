#ifndef OOP_CARTE_H
#define OOP_CARTE_H

#include <string>

class Carte {
private:
    std::string numeCarte;
    std::string gen;
    int anAparitie;
    bool disponibilitate = true;
public:
    Carte() = default;

    Carte(const std::string & numeCarte, const std::string & gen, int anAparitie);

    Carte(const Carte & copie);

    Carte & operator=(const Carte & copie);

    ~Carte() = default;

    friend std::ostream & operator<<(std::ostream & os, const Carte & carte);

    bool get_disponibilitate() const;

    void set_disponibilitate(bool disponibilitate);

    std::string get_numeCarte() const;
};

#endif //OOP_CARTE_H

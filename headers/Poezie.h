#ifndef OOP_POEZIE_H
#define OOP_POEZIE_H

#include <iostream>
#include <string>

class Poezie {
private:
    std::string numePoezie;
    int anulAparitiei;
    int numarVersuri;
public:
    Poezie(const std::string& numePoezie, int anulAparitiei, int numarVersuri);

    friend std::ostream &operator<<(std::ostream & os, const Poezie& poezie);
};

#endif //OOP_POEZIE_H

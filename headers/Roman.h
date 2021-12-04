#ifndef OOP_ROMAN_H
#define OOP_ROMAN_H

#include "Carte.h"

class Roman : public Carte {
private:
    int numarCapitole;
public:
    Roman(const std::string &numeRoman, const std::string &gen, int anAparitie, int numarCapitole);
    ~Roman();

    std::shared_ptr<Carte> clone() const override;
    void afis(std::ostream &os) const override;
};

#endif //OOP_ROMAN_H

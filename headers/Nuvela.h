#ifndef OOP_NUVELA_H
#define OOP_NUVELA_H

#include "Carte.h"

class Nuvela : public Carte {
private:
    int numarPagini;
public:
    Nuvela(const std::string &numeNuvela, const std::string &gen, int anAparitie, int numarPagini);
    ~Nuvela();

    std::shared_ptr<Carte> clone() const override;
    void afis(std::ostream &os) const override;
};

#endif //OOP_NUVELA_H

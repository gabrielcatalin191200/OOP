#ifndef OOP_PIESADETEATRU_H
#define OOP_PIESADETEATRU_H

#include "Carte.h"

class PiesaDeTeatru : public Carte {
private:
    int numarActe;
public:
    PiesaDeTeatru(const std::string &numePiesa, const std::string &gen, int anAparitie, int numarActe);
    ~PiesaDeTeatru();

    std::shared_ptr<Carte> clone() const override;
    void afis(std::ostream &os) const override;
};

#endif //OOP_PIESADETEATRU_H

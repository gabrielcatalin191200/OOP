#ifndef OOP_VOLUMPOEZII_H
#define OOP_VOLUMPOEZII_H

#include <vector>
#include <memory>

#include "Carte.h"
#include "Poezie.h"

class VolumPoezii : public Carte {
private:
    std::vector<Poezie> poezii;
public:
    VolumPoezii(const std::string &numeVolum, const std::string &gen, int anAparitie);
    VolumPoezii(const std::string &numeCarte, const std::string &gen, int anAparitie, const std::vector<Poezie> &poezii);
    ~VolumPoezii() override;

    friend std::ostream &operator<<(std::ostream& os, const VolumPoezii& volum);

    void adaugaPoezie(const Poezie &poezie);

    std::shared_ptr<Carte> clone() const override;
    void afis(std::ostream &os) const override;
};

#endif //OOP_VOLUMPOEZII_H

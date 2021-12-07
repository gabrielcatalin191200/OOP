#ifndef OOP_EROARECARTE_H
#define OOP_EROARECARTE_H

#include <stdexcept>

class EroareCarte : public std::runtime_error {
public:
    EroareCarte(const std::string &arg);
};

class AnGresit : public EroareCarte {
public:
    AnGresit();
};

class GenGresit : public EroareCarte {
public:
    GenGresit();
};

class CarteLipsa : public EroareCarte {
public:
    CarteLipsa();
};

#endif //OOP_EROARECARTE_H

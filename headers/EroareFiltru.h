#ifndef OOP_EROAREFILTRU_H
#define OOP_EROAREFILTRU_H

#include <stdexcept>
#include <string>

class EroareFiltru : public std::runtime_error {
public:
    EroareFiltru(const std::string &arg);
};

class FiltruInvalid : public EroareFiltru {
public:
    FiltruInvalid();
};

#endif //OOP_EROAREFILTRU_H

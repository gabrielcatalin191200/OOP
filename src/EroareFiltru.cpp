#include "../headers/EroareFiltru.h"

EroareFiltru::EroareFiltru(const std::string &arg) : runtime_error("Eroare filtru cautare: " + arg) {}

FiltruInvalid::FiltruInvalid() : EroareFiltru("Filtrul aplicat nu este valid") {}
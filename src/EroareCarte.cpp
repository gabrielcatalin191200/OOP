#include "../headers/EroareCarte.h"

EroareCarte::EroareCarte(const std::string &arg) : runtime_error("Eroare carte: " + arg) {}

AnGresit::AnGresit() : EroareCarte("Anul cartii nu este valid") {}

GenGresit::GenGresit() : EroareCarte("Genul cartii nu este potrivit") {}

CarteLipsa::CarteLipsa() : EroareCarte("Cartea nu a fost gasita") {}
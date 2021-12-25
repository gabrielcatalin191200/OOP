#include "../headers/Filtru.h"

Filtru::Filtru(const std::string &tipCautare, const std::string &keyWord) : tipCautare(tipCautare), keyWord(keyWord) {}

const std::string &Filtru::getTipCautare() const {
    return tipCautare;
}

const std::string &Filtru::getKeyWord() const {
    return keyWord;
}

#include "../headers/Autor.h"

template<typename T>
Autor<T>::Autor(const T& numeAutor) {
    this->numeAutor = numeAutor;
}

template<typename T>
Autor<T>::Autor(const T & numeAutor, const std::vector<std::shared_ptr<Carte>> & opere) : numeAutor(numeAutor), opere(opere) {
    std::ofstream out;
    out.open("../txt_files/ArhivaCarti.csv", std::fstream::app);

    if(out.is_open()) {
        for (const auto &carte : opere)
            out << carte->get_numeCarte() << ',' << numeAutor << ',' << carte->get_gen() << ',' << carte->get_anAparitie() << '\n';
    } else {
        std::cerr << "ERROR!";
    }
    out.close();
}

template<typename T>
Autor<T>::Autor(const Autor<T> & copie) : numeAutor(copie.numeAutor){
    for(const auto &carte: copie.opere)
        opere.push_back(carte->clone());
}

template<typename T>
Autor<T> &Autor<T>::operator=(const Autor<T> &copie) {
    if(this != &copie) {
        numeAutor = copie.numeAutor;
        auto opereAux = std::vector <std::shared_ptr <Carte>>();
        for(const auto &cantec: copie.opere) {
            opereAux.push_back(cantec->clone());
        }
        opere = opereAux;
    }
    return *this;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Autor<T>& autor){
    os << "Nume autor: " << autor.numeAutor << "\n   Opere:\n";
    for(const auto & opera : autor.opere)
        os << '\t' << *opera;
    return os;
}

template<typename T>
void Autor<T>::adaugaCarte(const Carte& carte) {
    opere.push_back(carte.clone());

    std::ofstream out;
    out.open("../txt_files/ArhivaCarti.csv", std::fstream::app);

    if(out.is_open()) {
        out << carte.get_numeCarte() << ',' << numeAutor << ',' << carte.get_gen() << ',' << carte.get_anAparitie() << '\n';
    } else {
        std::cerr << "ERROR!";
    }

    out.close();
}

template std::ostream &operator<< <>(std::ostream& os, const Autor<std::string>& autor);
template class Autor<std::string>;

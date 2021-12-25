#include "../headers/Cititor.h"

int Cititor::id_max = 1;

Cititor::Cititor(const std::string & nume, const std::string & prenume) : id(id_max), nume(nume), prenume(prenume) {
    id_max++;
}

std::ostream & operator<<(std::ostream & os, const Cititor & cititor) {
    if (cititor.cartiImprumutate.empty()){
        os << "Cititorul " << cititor.id << ":" << cititor.nume << " " << cititor.prenume << " nu a imprumutat nicio carte!" << '\n';
    } else if (cititor.cartiImprumutate.size() == 1) {
        os << "Cititorul " << cititor.id << ":" << cititor.nume << " " << cititor.prenume << " a imprumutat o carte:\n";
        os << "\t-" << cititor.cartiImprumutate[0]->get_numeCarte() << '\n';
    } else {
        os << "Cititorul " << cititor.id << ":" << cititor.nume << " " << cititor.prenume << " a imprumutat " << cititor.cartiImprumutate.size() << " carti:\n";
        for(int i=0; i<(int)cititor.cartiImprumutate.size(); i++)
            os << "\t-" << cititor.cartiImprumutate[i]->get_numeCarte() << '\n';
    }
    return os;
}

void Cititor::imprumuta(Carte & carte) {
    if(carte.get_disponibilitate()) { //daca nu este rezervata de altcineva sau nu se afla in posesia altcuiva
        cartiImprumutate.push_back(carte.clone());;
        cartiCitite.push_back(carte.clone());;
        carte.set_disponibilitate(false);
    } else if (verificaRezervare(carte)) { //se verifica daca exista o rezervare pe numele solicitantului si acesta indeplineste conditiile de imprumuta cartea in ordinea prioritatii
        cartiImprumutate.push_back(carte.clone());;
        cartiCitite.push_back(carte.clone());;
    } else {
        std::cout << "Cartea \"" << carte.get_numeCarte() << "\" nu este disponibila.\n";
    }
}

void Cititor::returneaza(Carte & carte) {
    for(int i=0; i < (int)this->cartiImprumutate.size(); i++) {
        if (this->cartiImprumutate[i]->get_numeCarte() == carte.get_numeCarte()) {
            carte.set_disponibilitate(true);
            cartiImprumutate.erase(cartiImprumutate.begin() + i);
            return; //in cazul in care a fost gasita cartea pe care vrem sa o returnam, nu mai continuam prin lista de carti imprumutate
        }
    }
    throw CarteLipsa(); //daca am ajuns pana aici, inseamna ca nu exista cartea in lista cititorului
}

void Cititor::rezerva(Carte & carte) {
    carte.set_disponibilitate(false);

    bool prioritate = true; // 0-prioritate scazuta, 1-prioritate mai mare(nu a citit cartea)

    for (auto & i : this->cartiCitite) {
        if (i->get_numeCarte() == carte.get_numeCarte()) {
            prioritate = false;
        }
    }

    std::ofstream out;
    out.open("../txt_files/Rezervari.csv", std::fstream::app);

    if (out.is_open()) {
        out << this->nume << ',' << this->prenume << ',' << carte.get_numeCarte() << ',' << prioritate << '\n';
    } else {
        std::cerr << "ERROR!";
    }

    out.close();
}

bool Cititor::verificaRezervare(const Carte &carte) {
    bool rezervatDeAltcineva = false;
    bool rezervatFaraPrioritate = false;

    csv::CSVReader reader("../txt_files/Rezervari.csv");

    for(csv::CSVRow &row : reader) {
        if (row["numeCarte"].get<>() == carte.get_numeCarte()) {
            if (row["nume"].get<>() == this->nume && row["prenume"].get<>() == this->prenume && row["prioritate"].get<>() == "1") {
                return true;
            }
        }
        if(row["prioritate"].get<>() == "1")
            rezervatDeAltcineva = true;
        if (row["nume"].get<>() == this->nume && row["prenume"].get<>() == this->prenume)
            rezervatFaraPrioritate = true;
    }

    return !rezervatDeAltcineva && rezervatFaraPrioritate;
}

int Cititor::getIdMax() {
    return id_max;
}

std::vector<CarteIndexata> Cititor::cauta(std::vector<Filtru> filtre) {
    std::vector<CarteIndexata> rezultat;

    csv::CSVReader reader1("../txt_files/ArhivaCarti.csv");

    for (csv::CSVRow &row : reader1) {
        rezultat.emplace_back(row["numeCarte"].get<>(), row["numeAutor"].get<>(), row["gen"].get<>(), row["anAparitie"].get<>());
    }

    SearchStrategy* SearchObject = nullptr;

    do {
        if(filtre[0].getTipCautare() == "Nume carte")
            SearchObject = new CautareNumeCarte;
        else if (filtre[0].getTipCautare() == "Nume autor")
            SearchObject = new CautareNumeAutor;
        else if (filtre[0].getTipCautare() == "An aparitie")
            SearchObject = new CautareAnAparitie;
        else if (filtre[0].getTipCautare() == "Gen")
            SearchObject = new CautareGen;
        else
            throw FiltruInvalid();

        if(SearchObject != nullptr) {
            rezultat = SearchObject->Cautare(filtre[0].getKeyWord(), rezultat);
            filtre.erase(filtre.begin());
            delete SearchObject;
            SearchObject = nullptr;
        }
    } while(!filtre.empty());

        if(rezultat.empty())
            std::cout << "Obiectul cautat nu exista";

    return rezultat;
}
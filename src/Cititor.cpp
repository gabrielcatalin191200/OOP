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
    out.open("../txt_files/Rezervari.txt", std::fstream::app);

    if (out.is_open()) {
        out << this->nume << ';' << this->prenume << ';' << carte.get_numeCarte() << ';' << prioritate << '\n';
    } else {
        std::cerr << "ERROR!";
    }

    out.close();
}

bool Cititor::verificaRezervare(const Carte &carte) {
    std::fstream check;
    check.open("../txt_files/Rezervari.txt", std::fstream::in);
    std::string line;

    bool rezervatDeAltcineva = false;
    bool rezervatFaraPrioritate = false;
    std::string tempNume, tempPrenume, tempNumeCarte, tempPrioritate;

    while(std::getline(check, line)) {
        std::istringstream iss(line);
        std::string temp;

        std::getline(iss, temp, ';');
        tempNume = temp;

        std::getline(iss, temp, ';');
        tempPrenume = temp;

        std::getline(iss, temp, ';');
        tempNumeCarte = temp;

        std::getline(iss, temp, '\n');
        tempPrioritate = temp;

        if(tempNumeCarte == carte.get_numeCarte()) {
            if(tempNume == this->nume && tempPrenume == this->prenume && tempPrioritate == "1") {
                check.close(); //daca persoana care solicita imprumutul are si prioritate, se returneaza true
                return true;
            }
            if(tempPrioritate == "1")
                rezervatDeAltcineva = true;
            if(tempNume == this->nume && tempPrenume == this->prenume)
                rezervatFaraPrioritate = true;
        }
    }
    check.close();
    return !rezervatDeAltcineva && rezervatFaraPrioritate;
}

int Cititor::getIdMax() {
    return id_max;
}

void Cititor::cautaCarte(const std::string &cuvantCheie, const std::string &filtru) {
    if(filtru == "nume carte") {
        cautaNumeCarte(cuvantCheie);
    } else if (filtru == "nume autor") {
        cautaNumeAutor(cuvantCheie);
    } else if (filtru == "gen") {
        cautaGen(cuvantCheie);
    } else if (filtru == "an aparitie") {
        cautaAnAparitie(cuvantCheie);
    } else {
        std::cout << "Cautarea nu se poate realiza";
    }
}

std::vector<CarteIndexata> Cititor::cauta(const std::vector<Filtru> filtre) {
    std::vector<CarteIndexata> rezultat;

    std::fstream check;
    check.open("../txt_files/ArhivaCarti.txt", std::fstream::in);
    std::string line;

    std::string tempNumeCarte, tempNumeAutor, tempGen, tempAnAparitie;

    while(std::getline(check, line)) {
        std::istringstream iss(line);
        std::string temp;

        std::getline(iss, temp, ';');
        tempNumeCarte = temp;

        std::getline(iss, temp, ';');
        tempNumeAutor = temp;

        std::getline(iss, temp, ';');
        tempGen = temp;

        std::getline(iss, temp, '\n');
        tempAnAparitie = temp;

        rezultat.push_back(CarteIndexata(tempNumeCarte, tempNumeAutor, tempGen, tempAnAparitie));

    }

    for(Filtru filtru:filtre)
        filtru.aplica(rezultat);

    return rezultat;
}
#include "../headers/Cautare.h"

void cautaNumeCarte(const std::string &cuvantCheie) {
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

        if (tempNumeCarte == cuvantCheie) {
            std::cout << "Cartea cautata este scrisa de " << tempNumeAutor << ", apartine genului " << tempGen << " si a aparut in anul " << tempAnAparitie << '\n';
            check.close();
            return;
        }
    }
    check.close();
    std::cout << "Cartea " << cuvantCheie << " nu exista in arhiva noastra";
}

void cautaNumeAutor(const std::string &cuvantCheie) {
    bool gasit = false;

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

        if (tempNumeAutor == cuvantCheie) {
            if (!gasit) {
                std::cout << "Autorul " << cuvantCheie << " a scris:\n";
                gasit = true;
            }
            std::cout << "\tCartea \"" << tempNumeCarte << "\" apartinand genului " << tempGen << " si care a aparut in anul " << tempAnAparitie << '\n';
        }
    }
    check.close();
    if(!gasit)
        std::cout << "Nicio carte a autorului " << cuvantCheie << " nu se afla in biblioteca noastra";
}

void cautaGen(const std::string &cuvantCheie) {
    bool gasit = false;

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

        if (tempGen == cuvantCheie) {
            if (!gasit) {
                std::cout << "Cartile apartinand genului " << cuvantCheie << " pe care le avem:\n";
                gasit = true;
            }
            std::cout << "\tCartea \"" << tempNumeCarte << "\" scrisa de " << tempNumeAutor << " si care a aparut in anul " << tempAnAparitie << '\n';
        }
    }
    check.close();
    if (!gasit)
        std::cout << "Nicio carte apartinand genului " << cuvantCheie << " nu se afla in biblioteca noastra";
}

void cautaAnAparitie(const std::string &cuvantCheie) {
    bool gasit = false;

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

        if (tempAnAparitie == cuvantCheie) {
            if (!gasit) {
                std::cout << "Din anul " << cuvantCheie << " avem cartile:\n";
                gasit = true;
            }
            std::cout << "\tCartea \"" << tempNumeCarte << "\" scrisa de " << tempNumeAutor << " apartinand genului " << tempGen << '\n';
        }
    }
    check.close();
    if(!gasit)
        std::cout << "Nicio carte scrisa in anul " << cuvantCheie << " nu se afla in biblioteca noastra";
}
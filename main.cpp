#include <vector>
#include <string>
#include <iostream>

class carte {
    std::string numeCarte;
    std::string gen;
    int anAparitie;
public:
    carte(const std::string &numeCarte, const std::string &gen, int anAparitie) : numeCarte(numeCarte), gen(gen), anAparitie(anAparitie) {}

    friend std::ostream &operator<<(std::ostream &os, const carte &carte) {
        os << "numeCarte: " << carte.numeCarte << " gen: " << carte.gen << " anAparitie: " << carte.anAparitie << "\n";
        return os;
    }

    ~carte() {
//        std::cout << "Destructor carte";
    }
};

class autor {
    std::string numeAutor;
    std::vector<carte> opere;
public:
    void adauga(carte opera) {
        opere.push_back(opera);
    }

    autor(const std::string &numeAutor) : numeAutor(numeAutor) {}

    autor(const std::string &numeAutor, const std::vector<carte> &opere) : numeAutor(numeAutor), opere(opere) {}

    autor(const autor& copie) {
        this->numeAutor = copie.numeAutor;
        this->opere = copie.opere;
    }

    autor& operator=(const autor& copie) {
        if(this != &copie) {
            this->numeAutor = copie.numeAutor;
            this->opere = copie.opere;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const autor &autor) {
        os << "\t\tnumeAutor: " << autor.numeAutor << " opere: ";
        for(const auto& opera : autor.opere)
            os << opera;
        return os;
    }

    ~autor() {
//        std::cout << "Destructor autor\n";
    }
};

class curentLiterar {
    std::string numeCurent;
    std::vector<autor> autori;
public:
    curentLiterar(const std::string &numeCurent, const std::vector<autor> &autori) : numeCurent(numeCurent), autori(autori) {}

    friend std::ostream &operator<<(std::ostream &os, const curentLiterar &curent) {
        os << "numeCurent: " << curent.numeCurent << "\n\tautori:\n";
        for(const auto& autor : curent.autori)
            os << autor;
        return os;
    }

    ~curentLiterar() {
//        std::cout << "Destructor curentLiterar";
    }
};

class cititor {
    std::string nume;
    std::string prenume;
    int nrCartiImprumutate=0;
    std::vector<carte> cartiImprumutate;
public:
    void imprumuta(carte opera) {
        cartiImprumutate.push_back(opera);
        nrCartiImprumutate++;
    }


    cititor(const std::string &nume, const std::string &prenume) : nume(nume), prenume(prenume) {}

    friend std::ostream &operator<<(std::ostream &os, const cititor &cititor) {
        os << "Cititorul " << cititor.nume << " " << cititor.prenume << " a imprumutat " << cititor.nrCartiImprumutate << " carti.";
        return os;
    }

    ~cititor() {
//        std::cout << "Destructor cititor";
    }
};

int main() {
    carte c1{"Moara cu noroc", "epic", 1881};
    carte c2{"Ion", "epic", 1920};
    carte c3{"O scrisoare pierduta", "dramatic", 1883};

    autor a1{"Ioan Slavici", {c1}};
    autor a2{"Liviu Rebreanu", {c2}};
    autor a3("Ion Luca Caragiale", {c3});

    curentLiterar cL1("realism", {a1, a2, a3});
    std::cout << cL1;

    cititor A{"Ion", "Andrei"};
    A.imprumuta(c1);
    A.imprumuta(c2);
    std::cout << A << '\n';
    return 0;
}
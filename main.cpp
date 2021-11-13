#include <iostream>

#include "./headers/Autor.h"
#include "./headers/Cititor.h"

int main() {

    Carte c1{"Moara cu noroc", "epic", 1881};
    Carte c2{"Ion", "epic", 1920};
    Carte c3{"O scrisoare pierduta", "dramatic", 1883};
    Carte c4{"Mara", "nuvela", 1894};

//    std::cout << c1 << '\n' << c2 << '\n' << c3 << '\n';

    Autor a1{"Ioan Slavici", {c1}};
    Autor a2{"Liviu Rebreanu", {c2}};
    Autor a3("Ion Luca Caragiale", {c3});
    a3.adaugaCarte(c4);

//    std::cout << a1 << '\n' << a2 << '\n' << a3 << '\n';

    Cititor A{"Ion", "Andrei"};
//    A.imprumuta(c1);
    A.imprumuta(c2);
//    std::cout << A << '\n';

    A.returneaza(c2);
//    std::cout << A << '\n';

    Cititor B{"Ana", "Maria"};
//    B.imprumuta(c3);
//    std::cout << B << '\n';

    Cititor C{"Andreea", "Ionescu"};
//    C.imprumuta(c3);
//    std::cout << C << '\n';

    A.rezerva(c2);
    B.rezerva(c2);
    B.rezerva(c1);

    A.imprumuta(c2);
    std::cout << A << '\n';

    return 0;
}
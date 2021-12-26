#include <iostream>

#include "headers/Autor.h"
#include "headers/VolumPoezii.h"
#include "headers/Roman.h"
#include "headers/Nuvela.h"
#include "headers/PiesaDeTeatru.h"
#include "headers/EroareFiltru.h"
#include "headers/Cititor.h"
#include "headers/CititorBuilder.h"

int main() {

    Nuvela c1{"Moara cu noroc", "epic", 1881, 384};
    Roman c2{"Ion", "epic", 1920, 13};
    PiesaDeTeatru c3{"O scrisoare pierduta", "dramatic", 1883, 4};
    Roman c4{"Mara", "epic", 1894, 21};
    Nuvela c5{"Sarmanul Dionis", "epic", 1872, 176};

    Autor<std::string> a2{"Ioan Slavici", {std::make_shared <Nuvela>(c1)}};
    Autor<std::string> a3{"Liviu Rebreanu", {std::make_shared <Roman>(c2)}};
    Autor<std::string> a4("Ion Luca Caragiale", {std::make_shared <PiesaDeTeatru>(c3)});
    a2.adaugaCarte(c4);

    Poezie p1("Luceafarul", 1883, 392);
    Poezie p2("Pe langa plopii fara sot", 1883, 44);

    VolumPoezii v1("Poesii", "liric", 1883, {p1});
    v1.adaugaPoezie(p2);

    Autor<std::string> a1{"Mihai Eminescu", {std::make_shared <VolumPoezii>(v1), std::make_shared <Nuvela>(c5)}};

//    std::cout << a1 << '\n';
//    std::cout << v1 << '\n';

    CititorBuilder builder;

    Cititor A = builder.adaugaNume("Ion")
            .adaugaPrenume("Andrei")
            .adaugaVarsta(18)
            .adaugaStrada("Bulevardul Republicii 12")
            .build();
//    A.imprumuta(c1);
    A.imprumuta(c2);
//    std::cout << A << '\n';

    A.returneaza(c2);
//    std::cout << A << '\n';

    Cititor B = builder.adaugaNume("Ana")
            .adaugaPrenume("Maria")
            .adaugaVarsta(35)
            .adaugaStrada("Bulevardul Independentei 43")
            .build();
    B.imprumuta(c3);
    std::cout << B << '\n';

    Cititor C = builder.adaugaNume("Andreea")
            .adaugaPrenume("Ionescu")
            .adaugaVarsta(75)
            .adaugaStrada("Dealu cu piatra 20")
            .build();
    C.imprumuta(c3);
    std::cout << C << '\n';

    A.rezerva(c2);
    B.rezerva(c2);
    B.rezerva(c1);

    A.imprumuta(c2);
    std::cout << A << '\n';

    try {
        Roman c0{"Test", "epic", 2022, 5};
        PiesaDeTeatru c01{"Test", "epic", 2000, 5};
        A.returneaza(c5);
    } catch (EroareCarte &error) {
        std::cout << error.what() << '\n';
    }

    std::cout << "\n********************************************************************\n\n";

    std::vector<CarteIndexata> rezA;

    try {
        rezA = A.cauta({Filtru("Nume autor", "Mihai Eminescu"), Filtru("Gen", "liric")});

        for (const auto& r:rezA)
            std::cout << r;

    } catch (EroareFiltru &error) {
        std::cout << error.what() << '\n';
    }

    return 0;
}
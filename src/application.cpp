#include "application.h"
#include "partie.h"
#include "tigre.h"
#include "lion.h"
#include <iostream>

application::application() : d_terrain_charge{9,9,position{0,0}}
{
    d_terrain_charge.ajoute_piege({4,4});
    d_terrain_charge.ajoute_fauve(std::make_unique<tigre>(position{8, 8}));
    d_terrain_charge.ajoute_fauve(std::make_unique<lion>(position{8, 0}));
}

void application::run() {
    bool goOn = true;
    while (goOn)
    {
        int choice {menu_principal()};
        switch(choice)
        {
            case 1 : jouer(); break;
            case 2 : creation_terrain(); break;
            case 3 : edition_terrain(); break;
            default: goOn = false;
        }
    }
}

int application::menu_principal() {
    int choice;
    do
    {
        std::cout<<"MENU PRINCIPAL"<<'\n'<<'\n';
        std::cout<<"(1) Jouer"<<'\n';
        std::cout<<"(2) Créer un terrain"<<'\n';
        std::cout<<"(3) Editer les terrains"<<'\n';
        std::cout<<"(4) Quitter"<<std::endl;
        std::cin>>choice;
    }
    while (choice<1 || choice>4);

    return choice;
}

void application::jouer() {
    partie p{d_terrain_charge};
    p.run();
}

void application::creation_terrain() {
    std::cout << "Menu création terrain";
}

void application::edition_terrain() {
    std::cout << "Menu edition terrain";
}

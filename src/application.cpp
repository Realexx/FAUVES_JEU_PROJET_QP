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
            case 4 : choix_terrain(); break;
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
        std::cout<<"(3) Editer un terrain"<<'\n';
        std::cout<<"(4) Choisir le terrain à charger"<<'\n';
        std::cout<<"(5) Quitter"<<std::endl;
        std::cin>>choice;
    }
    while (choice<1 || choice>5);

    return choice;
}

void application::jouer() {
    partie p{d_terrain_charge};
    p.run();
    // p.reinitialisation();
}

void application::creation_terrain() {
    std::cout << "Menu création terrain\n";
    // TODO Affiche un questionnaire permettant de généré un fichier texte contenant les informations d'un terrain
}

void application::edition_terrain() {
    std::cout << "Menu edition terrain\n";
    // TODO Affiche la liste des terrains actuelles (affichage du dossier contenant les fichiers (Ex: un dossier "terrains" à la racine du projet)
    // L'utilisateur peut alors sélectionner le terrain/fichier qu'il veut modifier et un questionnaire s'affiche pour savoir ce que l'utilisateur veut modifier
    // + modification en conséquence
}

void application::choix_terrain() {
    std::cout << "Menu choix terrain\n";
    // TODO Affiche la liste des fichiers/terrains + l'utilisateur sélectionne le fichier qu'il veut + conversion du fichier sélectionné en objet de type terrain
    // puis insertion du terrain obtenu dans 'd_terrain_charge'
}

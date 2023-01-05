#include "application.h"
#include "partie.h"
#include "tigre.h"
#include "lion.h"
#include "terrain.h"
#include "fonctions.h"
#include <iostream>

application::application() : d_terrain_charge{9,9,position{0,0}}, d_partie{d_terrain_charge}
{}

void application::run() {
    bool goOn = true;
    while (goOn)
    {
        int choice {menu_principal()};
        switch(choice)
        {
            case 1 : jouer(); break;
            case 2 : creation_terrain(); break;
            case 3 :cout<< "fonctionnalite indisponible..\n" ;break;
//            case 3 : edition_terrain(); break;
            case 4 : choix_terrain(); break;
            case 5 : jouerExpert(); break;
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
        std::cout<<"(2) Creer un terrain"<<'\n';
        std::cout<<"(3) Editer un terrain"<<'\n';
        std::cout<<"(4) Choisir le terrain a charger"<<'\n';
        std::cout<<"(5) Jouer en mode expert"<<'\n';
        std::cout<<"(6) Quitter"<<std::endl;
        std::cin>>choice;
    }
    while (choice<1 || choice>6);

    return choice;
}

void application::jouer() {
    d_partie.run();
}
void application::jouerExpert() {
    d_partie.runExpert();
}

void application::creation_terrain() {
    terrain t1{1};
    t1.creer_Terrain();
    t1.sauvegarde();
    cout << "voici le terrain cree : \n";
    t1.affiche();
}

void application::edition_terrain() {
    std::cout << "Menu edition terrain\n";
    // TODO Affiche la liste des terrains actuelles (affichage du dossier contenant les fichiers (Ex: un dossier "terrains" à la racine du projet)
    // L'utilisateur peut alors sélectionner le terrain/fichier qu'il veut modifier et un questionnaire s'affiche pour savoir ce que l'utilisateur veut modifier
    // + modification en conséquence
}

void application::choix_terrain() {
    std::cout << "Menu choix terrain\n";
    fonctions::printAndSelectFile();
    //La selection se faitn mais bug quand on veut le jouer => pb surcharge d'opérateurs
    // puis insertion du terrain obtenu dans 'd_terrain_charge'
}
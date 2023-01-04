#include "application.h"
#include "partie.h"
#include "tigre.h"
#include "lion.h"
#include "terrain.h"
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
        std::cout<<"(2) Creer un terrain"<<'\n';
        std::cout<<"(3) Editer un terrain"<<'\n';
        std::cout<<"(4) Choisir le terrain à charger"<<'\n';
        std::cout<<"(5) Quitter"<<std::endl;
        std::cin>>choice;
    }
    while (choice<1 || choice>5);

    return choice;
}

void application::jouer() {
    d_partie.run();
    // d_partie.reinitialisation();
}

void application::creation_terrain() {
    terrain t1{1};
    t1.creer_Terrain();
    t1.sauvegarde();
//    set_terrain_charge(t1);
//    jouer();

//    d_partie.set_terrain(t1);
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

//void application::set_terrain_charge(terrain& t){
//    d_terrain_charge.get_largeur() = t.set_largeur(d_terrain_charge.get_largeur());
//    d_terrain_charge.d_hauteur = t.d_hauteur;
//    d_terrain_charge.d_position_joueur = t.d_position_joueur;
//    d_terrain_charge.d_fauves = std::move(t.d_fauves);
//    d_terrain_charge.d_pieges = t.d_pieges;
//}
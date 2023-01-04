#include <iostream>
#include <ctime>
#include "application.h"
#include "terrain.h"
#include "lion.h"
#include "partie.h"
#include "tigre.h"
#include "fonctions.h"

int main() {

//    terrain t{10, 10, {0, 0}};
//    t.sauvegarde("C:\\Users\\rouam\\OneDrive\\Documents\\Cours\\ProjetL3\\FAUVES_JEU_PROJET_QP\\caca.txt");

//    position p {5,5};
//    terrain t {10,10,p};
//    t.sauvegarde();

    application app{};
    app.run();


    /*
    terrain t{10,10,position{0,0}};
    t.ajoute_piege(piege{5,5}); t.ajoute_piege(piege{6,6});
    t.ajoute_fauve(make_unique<lion>(position{5,2}));
    t.ajoute_fauve(make_unique<tigre>(position{9,9}));

    partie p{t};
    p.run();
    */
};
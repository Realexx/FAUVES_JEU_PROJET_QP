#include "fauve.h"
#include "position.h"
#include "terrain.h"
#include <doctest.h>

// Test de construction de la classe
TEST_CASE("Test de construction de la classe fauve") {
    // Création d'un objet fauve avec la constructeur par défaut
    fauve f1;
    // Vérification que la ligne et la colonne de la position sont bien initialisées à 0
    CHECK(f1.get_ligne() == 0);
    CHECK(f1.get_colonne() == 0);
    // Vérification que l'état de vie du fauve est bien initialisé à true
    CHECK(f1.get_est_vivant() == true);
    // Vérification que le symbole du fauve est bien initialisé à une chaîne vide
    CHECK(f1.get_symbole() == "");

    // Création d'un objet fauve avec la constructeur avec paramètres
    position pos(3, 4);
    fauve f2(pos);
    // Vérification que la ligne et la colonne de la position sont bien initialisées à 3 et 4
    CHECK(f2.get_ligne() == 3);
    CHECK(f2.get_colonne() == 4);
    // Vérification que l'état de vie du fauve est bien initialisé à true
    CHECK(f2.get_est_vivant() == true);
    // Vérification que le symbole du fauve est bien initialisé à une chaîne vide
    CHECK(f2.get_symbole() == "");
}

// Test de la méthode get_ligne
TEST_CASE("Test de la méthode get_ligne de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Vérification que la méthode retourne bien la ligne de la position du fauve
    CHECK(f.get_ligne() == 3);
}

// Test de la méthode get_colonne
TEST_CASE("Test de la méthode get_colonne de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Vérification que la méthode retourne bien la colonne de la position du fauve
    CHECK(f.get_colonne() == 4);
}

// Test de la méthode set_colonne
TEST_CASE("Test de la méthode set_colonne de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Mise à jour de la colonne de la position du fauve
    f.set_colonne(6);
    // Vérification que la colonne de la position du fauve a bien été mise à jour
    CHECK(f.get_colonne() == 6);
}

// Test de la méthode get_est_vivant
TEST_CASE("Test de la méthode get_est_vivant de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Vérification que la méthode retourne bien l'état de vie du fauve
    CHECK(f.get_est_vivant() == true);
}

// Test de la méthode set_est_vivant
TEST_CASE("Test de la méthode set_est_vivant de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Mise à jour de l'état de vie du fauve
    f.set_est_vivant(false);
    // Vérification que l'état de vie du fauve a bien été mis à jour
    CHECK(f.get_est_vivant() == false);
}

// Test de la méthode get_symbole
TEST_CASE("Test de la méthode get_symbole de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    f.set_symbole("L");
    // Vérification que la méthode retourne bien le symbole du fauve
    CHECK(f.get_symbole() == "L");
}

// Test de la méthode set_symbole
TEST_CASE("Test de la méthode set_symbole de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    // Mise à jour du symbole du fauve
    f.set_symbole("T");
    // Vérification que le symbole du fauve a bien été mis à jour
    CHECK(f.get_symbole() == "T");
}

// Test de la méthode verif_deplacement avec un fauve sur la même case qu'un piège
TEST_CASE("Test de la méthode verif_deplacement avec un fauve sur la même case qu'un piège de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    terrain t(5, 5, pos);
    t.ajoute_piege(piege(3, 4));
    // Vérification que l'état de vie du fauve est mis à false lorsqu'il se retrouve sur la même case qu'un piège
    f.verif_deplacement(t);
    CHECK(f.get_est_vivant() == false);
}

// Test de la méthode verif_deplacement avec un fauve qui sort du terrain
TEST_CASE("Test de la méthode verif_deplacement avec un fauve qui sort du terrain de la classe fauve") {
    position pos(3, 4);
    fauve f(pos);
    terrain t(5, 5, pos);
    // Mise à jour de la position du fauve pour qu'il sorte du terrain
    f.set_ligne(-1);
    f.set_colonne(-1);
    // Vérification que l'état de vie du fauve est mis à false lorsqu'il sort du terrain
    f.verif_deplacement(t);
    CHECK(f.get_est_vivant() == false);
}
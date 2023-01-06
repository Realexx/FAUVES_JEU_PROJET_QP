#include "position.h"
#include "doctest.h"

TEST_CASE("Test du constructeur par défaut de position") {
    position p;
    CHECK(p.get_ligne() == 0);
    CHECK(p.get_colonne() == 0);
}

TEST_CASE("Test du constructeur avec paramètres de position") {
    position p{3, 4};
    CHECK(p.get_ligne() == 3);
    CHECK(p.get_colonne() == 4);
}

TEST_CASE("Test de la fonction set_ligne") {
    position p;
    p.set_ligne(5);
    CHECK(p.get_ligne() == 5);
}

TEST_CASE("Test de la fonction set_colonne") {
    position p;
    p.set_colonne(6);
    CHECK(p.get_colonne() == 6);
}

TEST_CASE("Tests des getters de la classe Position") {
    position pos;
    CHECK(pos.get_ligne() == 0);
    CHECK(pos.get_colonne() == 0);
    position pos2(5, 3);
    CHECK(pos2.get_ligne() == 5);
    CHECK(pos2.get_colonne() == 3);
}
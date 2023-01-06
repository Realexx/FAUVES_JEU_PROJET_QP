#include "doctest.h"
#include "piege.h"

TEST_CASE("Test de la classe piège") {
    piege p;
    CHECK(p.get_ligne() == 0);
    CHECK(p.get_colonne() == 0);
}

TEST_CASE("Test de la méthode get_ligne() de la classe piege") {
    piege p1;
    CHECK(p1.get_ligne() == 0);
    piege p2(5, 4);
    CHECK(p2.get_ligne() == 5);
}

TEST_CASE("Test de la méthode get_colonne() de la classe piege") {
    piege p1;
    CHECK(p1.get_colonne() == 0);
    piege p2(5, 4);
    CHECK(p2.get_colonne() == 4);
}

TEST_CASE("Test setters de la classe piege") {
    piege p;
    p.set_ligne(4);
    p.set_colonne(7);
    CHECK(p.get_ligne() == 4);
    CHECK(p.get_colonne() == 7);
}
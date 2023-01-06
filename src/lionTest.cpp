#include "doctest.h"
#include "lion.h"

// Teste que le lion est créé correctement avec une position donnée
TEST_CASE("Test du constructeur de lion avec position donnée") {
    position pos{2, 3};
    lion l{pos};
    CHECK(l.get_ligne() == 2);
    CHECK(l.get_colonne() == 3);
    CHECK(l.get_symbole() == "L");
}

// Teste que le lion est créé correctement sans position donnée
TEST_CASE("Test du constructeur de lion sans position donnée") {
    lion l;
    CHECK(l.get_ligne() == 0);
    CHECK(l.get_colonne() == 0);
    CHECK(l.get_symbole() == "L");
}

// Teste la méthode get_type() de lion
TEST_CASE("Test de la méthode get_type() de lion") {
    lion l;
    CHECK(l.get_type() == "lion");
}

// Teste la méthode deplacement() de lion
TEST_CASE("Test de la méthode deplacement() de lion") {
    // Création d'un terrain avec la position du joueur en (5, 5)
    terrain t{10, 10, position{5, 5}};
    lion l{position{4, 4}};
    // Le lion doit se déplacer vers le joueur
    l.deplacement(t);
    CHECK(l.get_ligne() == 5);
    CHECK(l.get_colonne() == 5);

    // Création d'un autre lion, cette fois-ci en (6, 6)
    lion l2{position{6, 6}};
    // Le lion doit se déplacer vers le joueur
    l2.deplacement(t);
    CHECK(l2.get_ligne() == 5);
    CHECK(l2.get_colonne() == 5);
}

#include "partie.h"
#include "terrain.h"
#include "doctest.h"

TEST_CASE("Test de la méthode est_deplacement_dans_bordures() de la classe partie") {
    terrain t{10, 10, {0, 0}};
    partie p{t};
    CHECK(p.est_deplacement_dans_bordures() == true);
    t.set_joueur_ligne(-1);
    CHECK(p.est_deplacement_dans_bordures() == false);
    t.set_joueur_ligne(0);
    t.set_joueur_colonne(-1);
    CHECK(p.est_deplacement_dans_bordures() == false);
    t.set_joueur_colonne(0);
    t.set_joueur_ligne(10);
    CHECK(p.est_deplacement_dans_bordures() == false);
    t.set_joueur_ligne(9);
    t.set_joueur_colonne(10);
    CHECK(p.est_deplacement_dans_bordures() == false);
}

TEST_CASE("Tests de la méthode joueur_se_deplace de la classe partie") {
    terrain t{10, 10, position{5, 5}};
    partie p{t};
    // Test du déplacement du joueur vers le haut
    t.set_joueur_ligne(t.get_joueur_ligne() - 1);
    REQUIRE(p.joueur_se_deplace() == true);
    REQUIRE(t.get_joueur_ligne() == 4);
    REQUIRE(t.get_joueur_colonne() == 5);

    // Test du déplacement du joueur vers le bas
    t.set_joueur_ligne(t.get_joueur_ligne() + 2);
    REQUIRE(p.joueur_se_deplace() == true);
    REQUIRE(t.get_joueur_ligne() == 6);
    REQUIRE(t.get_joueur_colonne() == 5);

    // Test du déplacement du joueur vers la droite
    t.set_joueur_colonne(t.get_joueur_colonne() + 1);
    REQUIRE(p.joueur_se_deplace() == true);
    REQUIRE(t.get_joueur_ligne() == 6);
    REQUIRE(t.get_joueur_colonne() == 6);

    // Test du déplacement du joueur vers la gauche
    t.set_joueur_colonne(t.get_joueur_colonne() - 2);
    REQUIRE(p.joueur_se_deplace() == true);
    REQUIRE(t.get_joueur_ligne() == 6);
    REQUIRE(t.get_joueur_colonne() == 4);
}

TEST_CASE("Tests de la fonction joueur_en_vie de la classe partie") {
    terrain t1{10, 10, {5, 5}};
    partie p1{t1};

    // Test 1 : le joueur se trouve sur une case vide
    REQUIRE(p1.joueur_en_vie() == true);

    // Test 2 : le joueur se trouve sur une case occupée par un fauve
    t1.get_fauves().front()->set_ligne(5);
    t1.get_fauves().front()->set_colonne(5);
    REQUIRE(p1.joueur_en_vie() == false);
}

TEST_CASE("Tests de la fonction fauves_en_vie de la classe partie") {
    terrain t1{10, 10, {5, 5}};
    partie p1{t1};

    // Test 1 : il y a des fauves vivants sur le terrain
    REQUIRE(p1.fauves_en_vie() == true);

    // Test 2 : il n'y a plus de fauves vivants sur le terrain
    for (auto &f: t1.get_fauves()) {
        f->set_est_vivant(false);
    }
    REQUIRE(p1.fauves_en_vie() == false
}

TEST_CASE("test de la méthode faire_bouger_fauves de la classe partie") {
    terrain t{10, 10, position{3, 3}};
    t.ajoute_fauve(std::make_unique<tigre>(position{2, 3}));
    t.ajoute_fauve(std::make_unique<lion>(position{2, 4}));
    t.ajoute_fauve(std::make_unique<fauve>(position{6, 6}));

    partie p{t};

    // Le tigre se déplace vers le joueur
    p.faire_bouger_fauves();
    CHECK(t.get_fauves()[0]->get_ligne() == 3);
    CHECK(t.get_fauves()[0]->get_colonne() == 3);

    // Le lion se déplace vers le joueur
    p.faire_bouger_fauves();
    CHECK(t.get_fauves()[1]->get_ligne() == 3);
    CHECK(t.get_fauves()[1]->get_colonne() == 4);

    // Le fauve se déplace vers sa dernière position connue (le joueur)
    p.faire_bouger_fauves();
    CHECK(t.get_fauves()[2]->get_ligne() == 4);
    CHECK(t.get_fauves()[2]->get_colonne() == 4);
}


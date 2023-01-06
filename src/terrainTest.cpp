#include "doctest.h"
#include "terrain.h"
#include "fauve.h"
#include "lion.h"
#include "tigre.h"
#include "position.h"

TEST_CASE("Test du constructeur par défaut de terrain") {
    terrain t;
    CHECK(t.get_largeur() == 10);
    CHECK(t.get_hauteur() == 10);
    CHECK(t.get_joueur_ligne() == 0);
    CHECK(t.get_joueur_colonne() == 0);
    CHECK(t.get_fauves().empty());
    CHECK(t.get_pieges().empty());
}

TEST_CASE("Test du constructeur avec paramètres de terrain") {
    terrain t(15, 20, position(5, 6));
    CHECK(t.get_largeur() == 15);
    CHECK(t.get_hauteur() == 20);
    CHECK(t.get_joueur_ligne() == 5);
    CHECK(t.get_joueur_colonne() == 6);
    CHECK(t.get_fauves().empty());
    CHECK(t.get_pieges().empty());
}

TEST_CASE("Test ajout piege sur terrain") {
    terrain t{10, 10, {0, 0}};
    piege p{4, 4};
    t.ajoute_piege(p);
    std::vector<piege> pieges = t.get_pieges();
    CHECK(pieges.size() == 1);
    CHECK(pieges[0].get_colonne() == 4);
    CHECK(pieges[0].get_ligne() == 4);
}


TEST_CASE("Test ajout fauve sur terrain") {
    terrain t{10, 10, {0, 0}};
    std::unique_ptr<fauve> f = std::make_unique<tigre>(position{8, 8});
    t.ajoute_fauve(std::move(f));
    std::vector<std::unique_ptr<fauve>> fauves = t.get_fauves();
    CHECK(fauves.size() == 1);
    CHECK(fauves[0]->get_symbole() == "T");
    CHECK(fauves[0]->get_colonne() == 8);
    CHECK(fauves[0]->get_ligne() == 8);
    CHECK(fauves[0]->get_est_vivant() == true);
}

TEST_CASE("Test de la méthode affiche de la classe terrain") {
    // Création d'un terrain de test
    terrain t{10, 10, {5, 5}};
    t.ajoute_fauve(std::make_unique<tigre>(position{8, 8}));
    t.ajoute_fauve(std::make_unique<lion>(position{8, 0}));

    // Redirige la sortie standard dans un flux de chaîne
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    // Affiche le terrain
    t.affiche();

    // Rétablit la sortie standard
    std::cout.rdbuf(sbuf);

    // Récupère le contenu du flux de chaîne dans une chaîne
    std::string output = buffer.str();

    // Vérifie que le contenu du flux de chaîne est ce qui était attendu
    CHECK(output == " \n 0 1 2 3 4 5 6 7 8 9 \n 0 . . . . . . . . . . \n 1 . . . . . . . . . . \n 2 . . . . . . . . . . \n 3 . . . . . . . . . . \n 4 . . . . . J . . . . \n 5 . . . . . . . . . . \n 6 . . . . . . . . . . \n 7 . . . . . . . . . . \n 8 . L . . . . . . T . \n 9 . . . . . . . . . . \n");
}


#include "tigre.h"
#include "position.h"
#include "terrain.h"
#include <doctest.h>

// Test du constructeur par défaut de la classe tigre
TEST_CASE("Test du constructeur par défaut de la classe tigre") {
    tigre t;
    // Vérification que le type du tigre est bien "tigre"
    CHECK(t.get_type() == "tigre");
    // Vérification que le symbole du tigre est bien "T"
    CHECK(t.get_symbole() == "T");
}

// Test du constructeur avec paramètres de la classe tigre
TEST_CASE("Test du constructeur avec paramètres de la classe tigre") {
    position pos(3, 4);
    tigre t(pos);
    // Vérification que le type du tigre est bien "tigre"
    CHECK(t.get_type() == "tigre");
    // Vérification que le symbole du tigre est bien "T"
    CHECK(t.get_symbole() == "T");
    // Vérification que la ligne et la colonne de la position du tigre sont correctes
    CHECK(t.get_ligne() == 3);
    CHECK(t.get_colonne() == 4);
}

// Test de la méthode deplacement de la classe tigre
TEST_CASE("Test de la méthode deplacement de la classe tigre") {
    position pos(3, 4);
    tigre t(pos);
    terrain t2(5, 5, pos);
    t.deplacement(t2);
    // Vérification que le tigre a bien bougé
    CHECK((t.get_ligne() != 3 || t.get_colonne() != 4));
}

// Test de la méthode deplacement avec un tigre qui ne peut pas bouger
TEST_CASE("Test de la méthode deplacement avec un tigre qui ne peut pas bouger de la classe tigre") {
    position pos(3, 4);
    tigre t(pos);
    terrain t2(5, 5, pos);
    t2.set_joueur_ligne(3);
    t2.set_joueur_colonne(4);
    // Sauvegarde de la position du tigre avant déplacement
    int ligne_initiale = t.get_ligne();
    int colonne_initiale = t.get_colonne();
    // Déplacement du tigre
    t.deplacement(t2);
    // Vérification que le tigre n'a pas bougé car il était déjà sur la même case que le joueur
    CHECK(t.get_ligne() == ligne_initiale);
    CHECK(t.get_colonne() == colonne_initiale);
}

// Test de la méthode deplacement avec un tigre qui sort du terrain
TEST_CASE("Test de la méthode deplacement avec un tigre qui sort du terrain de la classe tigre") {
    position pos(3, 4);
    tigre t(pos);
    terrain t2(5, 5, pos);
    // Mise à jour de la position du joueur pour que le tigre sorte du terrain lors de son déplacement
    t2.set_joueur_ligne(-1);
    t2.set_joueur_colonne(-1);
    tigre::deplacement(t2);
    // Vérification que le tigre a bien été mis à mort (état de vie à false) lorsqu'il est sorti du terrain
    CHECK(!t.get_est_vivant());
}

// Test de la méthode verif_deplacement avec un tigre qui tombe sur un piège
TEST_CASE("Test de la méthode verif_deplacement avec un tigre qui tombe sur un piège de la classe tigre") {
    position pos(3, 4);
    tigre t(pos);
    terrain t2(5, 5, pos);
    // Création d'un piège sur la case du tigre
    piege p(3, 4);
    t2.ajoute_piege(p);
    // Vérification que l'état de vie du tigre est mis à false lorsqu'il tombe sur un piège
    t.verif_deplacement(t2);
    CHECK(!t.get_est_vivant());
}


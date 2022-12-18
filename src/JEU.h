#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Représente un fauve
struct Fauve {
    int x, y; // Position du fauve sur le terrain
    bool est_lion; // Vrai si le fauve est un lion, faux s'il est un tigre
    bool est_vivant; // Vrai si le fauve est encore en vie, faux sinon
};

// Représente un piège
struct Piege {
    int x, y; // Position du piège sur le terrain
};

// Représente un terrain de jeu
struct Terrain {
    std::vector<Fauve> fauves; // Liste des fauves présents sur le terrain
    std::vector<Piege> pieges; // Liste des pièges présents sur le terrain
    int joueur_x, joueur_y; // Position du joueur sur le terrain
    int largeur, hauteur; // Taille du terrain (en cases)
};

// Affiche le terrain de jeu en mode texte
void afficher_terrain(const Terrain& terrain) {
    for (int y = 0; y < terrain.hauteur; y++) {
        for (int x = 0; x < terrain.largeur; x++) {
            // Affiche le joueur
            if (x == terrain.joueur_x && y == terrain.joueur_y) {
                std::cout << 'J';
                continue;
            }

            // Affiche les fauves
            bool fauve_trouve = false;
            for (const Fauve& fauve : terrain.fauves) {
                if (fauve.x == x && fauve.y == y && fauve.est_vivant) {
                    std::cout << (fauve.est_lion ? 'L' : 'T');
                    fauve_trouve = true;
                    break;
                }
            }
            if (fauve_trouve) continue;

            // Affiche les pièges
            bool piege_trouve = false;
            for (const Piege& piege : terrain.pieges) {
                if (piege.x == x && piege.y == y) {
                    std::cout << 'P';
                    piege_trouve = true;
                    break;
                }
            }
            if (piege_trouve) continue;

            // Affiche une case vide
            std::cout << '.';
        }
        std::cout << std::endl;
    }
}

// Demande au joueur de déplacer le personnage et met à jour sa position
void joueur_se_deplace(Terrain& terrain) {
    std::cout << "Où souhaitez-vous déplacer le joueur ? (haut/bas/gauche/droite/haut-gauche/haut-droite/bas-gauche/bas-droite)" << std::endl;
    std::string direction;
    std::cin >> direction;

    if (direction == "haut") {
        terrain.joueur_y--;
    } else if (direction == "bas") {
        terrain.joueur_y++;
    } else if (direction == "gauche") {
        terrain.joueur_x--;
    } else if (direction == "droite") {
        terrain.joueur_x++;
    } else if (direction == "haut-gauche") {
        terrain.joueur_x--;
        terrain.joueur_y--;
    } else if (direction == "haut-droite") {
        terrain.joueur_x++;
        terrain.joueur_y--;
    } else if (direction == "bas-gauche") {
        terrain.joueur_x--;
        terrain.joueur_y++;
    } else if (direction == "bas-droite") {
        terrain.joueur_x++;
        terrain.joueur_y++;
    } else {
        std::cout << "Direction invalide, veuillez réessayer." << std::endl;
    }
}

// Fait bouger un fauve du terrain
void fauve_se_deplace(Terrain& terrain, Fauve& fauve) {
    // Si le fauve est un lion, il ne peut se déplacer que horizontalement ou verticalement
    if (fauve.est_lion) {
        if (fauve.x < terrain.joueur_x) {
            fauve.x++;
        } else if (fauve.x > terrain.joueur_x) {
            fauve.x--;
        } else if (fauve.y < terrain.joueur_y) {
            fauve.y++;
        } else if (fauve.y > terrain.joueur_y) {
            fauve.y--;
        }
    } else { // Si le fauve est un tigre, il peut se déplacer aussi en diagonale
        if (fauve.x < terrain.joueur_x) {
            fauve.x++;
        } else if (fauve.x > terrain.joueur_x) {
            fauve.x--;
        } else if (fauve.y < terrain.joueur_y) {
            fauve.y++;
        } else if (fauve.y > terrain.joueur_y) {
            fauve.y--;
        }
    }

    // Si le fauve se retrouve sur la même case qu'un autre fauve, ils s'affrontent
    for (Fauve& autre_fauve : terrain.fauves) {
        if (&autre_fauve == &fauve) continue; // On ignore le fauve lui-même
        if (autre_fauve.x == fauve.x && autre_fauve.y == fauve.y) {
            if (autre_fauve.est_lion == fauve.est_lion) {
                // Si les fauves sont du même type, ils essaient de s'éviter et ne bougent pas
                fauve.x = fauve.x;
                fauve.y = fauve.y;
            } else {
                // Si les fauves sont de types différents, ils s'affrontent et l'un des deux meurt
                fauve.est_vivant = false;
                autre_fauve.est_vivant = false;
            }
            break;
        }
    }

    // Si le fauve se retrouve sur un piège, il meurt
    for (Piege& piege : terrain.pieges) {
        if (piege.x == fauve.x && piege.y == fauve.y) {
            fauve.est_vivant = false;
            break;
        }
    }
}
// Fait bouger tous les fauves du terrain
void faire_bouger_fauves(Terrain& terrain) {
    for (Fauve& fauve : terrain.fauves) {
        fauve_se_deplace(terrain, fauve);
    }
}

// Vérifie si le joueur est encore en vie
bool joueur_en_vie(const Terrain& terrain) {
    for (const Fauve& fauve : terrain.fauves) {
        if (fauve.x == terrain.joueur_x && fauve.y == terrain.joueur_y && fauve.est_vivant) {
            return false;
        }
    }
    return true;
}

// Vérifie si il reste des fauves en vie sur le terrain
bool fauves_en_vie(const Terrain& terrain) {
    for (const Fauve& fauve : terrain.fauves) {
        if (fauve.est_vivant) return true;
    }
    return false;
}

int main() {
    // Création du terrain
    Terrain terrain;
    terrain.largeur = 10;
    terrain.hauteur = 10;
    terrain.joueur_x = 0;
    terrain.joueur_y = 0;

    // Ajout de fauves et de pièges au terrain
    terrain.fauves.push_back({2, 2, true, true});
    terrain.fauves.push_back({4, 4, false, true});
    terrain.pieges.push_back({5, 5});
    terrain.pieges.push_back({6, 6});

    // Boucle de jeu
    while (joueur_en_vie(terrain) && fauves_en_vie(terrain)) {
        // Affichage du terrain
        afficher_terrain(terrain);

        // Déplacement du joueur
        joueur_se_deplace(terrain);

        // Déplacement des fauves
        faire_bouger_fauves(terrain);
    }

    // Fin de la partie
    if (joueur_en_vie(terrain)) {
        std::cout << "Vous avez gagné !" << std::endl;
    } else {
        std::cout << "Vous avez perdu !" << std::endl;
    }

    return 0;
}
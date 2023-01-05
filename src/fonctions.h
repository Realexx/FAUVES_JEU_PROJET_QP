#ifndef FAUVES_JEU_PROJET_QP_FONCTIONS_H
#define FAUVES_JEU_PROJET_QP_FONCTIONS_H

#include <iostream>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include "terrain.h"
#include "tigre.h"
#include "lion.h"


using namespace  std;
class fonctions {
public:


    static int  demande_entier(const string &message) {
        cout << message;
        int n;
        cin >> n;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veuillez entrer un entier : ";
            cin >> n;
        }
        return n;
    }

    static string demande_choix(const string &message, const vector<string> &choix) {
       cout << message;
        string reponse;
        cin >> reponse;
        while (find(choix.begin(), choix.end(), reponse) == choix.end()) {
            cout << "Veuillez entrer une des valeurs suivantes : ";
            for (const string &c: choix) {
                cout << c << " ";
            }
           cout << endl;
            cin >> reponse;
        }
        return reponse;
    }

    static char demande_oui_non(const string &message) {
       cout << message;
        char reponse;
        cin >> reponse;
        while (reponse != 'o' && reponse != 'n') {
            cout << "Veuillez entrer 'o' ou 'n' : ";
            cin >> reponse;
        }
        return reponse;
    }

    static void affiche_vector(const std::vector<std::string>& vec) {
        for (const std::string& s : vec) {
            std::cout << s << std::endl;
        }
    }

    static terrain lire_fichier(const std::string& nom_fichier) {
        string chemin = "..\\src\\saves\\" ;
        string fichierComplet = chemin + nom_fichier;
        std::ifstream fichier(fichierComplet);
        if (!fichier) {
            throw std::runtime_error("Error opening file");
        }

        int largeur, hauteur;
        int joueur_ligne, joueur_colonne;
        fichier >> largeur >> hauteur >> joueur_ligne >> joueur_colonne;

        terrain t(largeur, hauteur, position(joueur_ligne, joueur_colonne));

        std::string ligne;
        while (std::getline(fichier, ligne)) {
            std::istringstream iss(ligne);
            char type;
            int ligne, colonne;
            iss >> type >> ligne >> colonne;
            if (type == 'T') {
                t.ajoute_fauve(std::make_unique<tigre>(position(ligne, colonne)));
            } else if (type == 'L') {
                t.ajoute_fauve(std::make_unique<lion>(position(ligne, colonne)));
            }
        }
        int n;
        fichier >> n;
        for (int i = 0; i < n; i++) {
            int ligne, colonne;
            fichier >> ligne >> colonne;
            t.ajoute_piege(piege(ligne, colonne));
        }

        return t;
    }

    static std::vector<std::string> get_files() {
        std::vector<std::string> files;
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir("..\\src\\saves")) != nullptr) {
            // Affiche tout les répertoires
            while ((ent = readdir(dir)) != NULL) {
                    files.push_back(ent->d_name);
            }
            closedir(dir);
        } else {
            throw std::runtime_error("Error opening directory");
        }
        return files;
    }

    static string printAndSelectFile(){
        vector<string> files  = get_files();
        if (files.empty()) {
            std::cout << "Pas de fichier dans le repertoire." << std::endl;
            return "";
        }
        std::cout << "Choisir un fichier:" << std::endl;
        for (int i = 0; i < files.size(); i++) {
            std::cout << i + 1 << ") " << files[i] << std::endl;
        }
        int choice;
        std::cin >> choice;
        if (choice < 1 || choice > files.size()) {
            std::cout << "choix invalide." << std::endl;
            return "";
        }
        std::cout << "Vous avez choisi: " << files[choice - 1] << std::endl;
        return files[choice-1];
    }
};


#endif //FAUVES_JEU_PROJET_QP_FONCTIONS_H

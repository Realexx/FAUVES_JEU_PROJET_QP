//
// Created by Zak on 03/01/2023.
//

#ifndef FAUVES_JEU_PROJET_QP_FONCTIONS_H
#define FAUVES_JEU_PROJET_QP_FONCTIONS_H

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>


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
};


#endif //FAUVES_JEU_PROJET_QP_FONCTIONS_H

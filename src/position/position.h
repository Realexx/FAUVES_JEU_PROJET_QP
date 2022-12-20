//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

class position {
public:
    position(int ligne, int colonne);
    int getLigne() const;
    void setLigne(int ligne);
    int getColonne() const;
    void setColonne(int colonne);

private:
    int d_ligne, d_colonne;
};

#endif //UNTITLED_POSITION_H

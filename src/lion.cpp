#include "lion.h"

lion::lion() : d_pos{}
{}

lion::lion(position pos) : d_pos{pos.getLigne(), pos.getColonne()}
{}

vector<position> lion::positionsSuivantesPossibles() {
    // TODO générer la liste des positions suivantes possibles selon la position actuelle du lion

    return vector<position>();
}

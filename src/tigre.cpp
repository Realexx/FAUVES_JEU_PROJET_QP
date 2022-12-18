#include "tigre.h"

tigre::tigre() : d_pos{}
{}

tigre::tigre(position pos) : d_pos{pos.getLigne(), pos.getColonne()}
{}

vector<position> tigre::positionsSuivantesPossibles() {
    // TODO générer la liste des positions suivantes possibles selon la position actuelle du tigre

    return vector<position>();
}

//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H

#include "../position/position.h"

class entity {
public:
    entity(int ligne, int colonne);
    virtual ~entity() = default;
protected:
    position d_position;
};


#endif //UNTITLED_ENTITY_H

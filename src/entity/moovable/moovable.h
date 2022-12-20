//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#ifndef UNTITLED_MOOVABLE_H
#define UNTITLED_MOOVABLE_H

#include "../entity.h"
#include "vector"

class moovable : public entity {
public:
    virtual std::vector<position> positionsSuivantesPossibles() = 0;
};


#endif //UNTITLED_MOOVABLE_H

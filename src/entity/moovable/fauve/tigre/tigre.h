//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#ifndef UNTITLED_TIGRE_H
#define UNTITLED_TIGRE_H

#include "../../moovable.h"

class tigre : public moovable {
public:
    std::vector<position> positionsSuivantesPossibles() override;
};

#endif //UNTITLED_TIGRE_H

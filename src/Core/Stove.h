//
// Created by Jason Evans on 20/11/2025.
//

#ifndef CHEFGAME3D_STOVE_H
#define CHEFGAME3D_STOVE_H
#include "Raylib.h"

class Stove {
public:
    Stove();
    float posX;
    float posY;
    float posZ;
    Vector3 position;
    Model model;
    BoundingBox baseBox;
    BoundingBox worldBox;
    void Draw() const;
    void Update();
    void UpdateWorldBox();

    ~Stove();
};


#endif //CHEFGAME3D_STOVE_H
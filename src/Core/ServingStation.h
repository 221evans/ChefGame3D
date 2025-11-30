//
// Created by Jason Evans on 30/11/2025.
//

#ifndef CHEFGAME3D_SERVINGSTATION_H
#define CHEFGAME3D_SERVINGSTATION_H
#include "raylib.h"


class ServingStation {
public:
    ServingStation();
    float posX;
    float posY;
    float posZ;
    Vector3 position;

    void Draw() const;
    void Update();
    void UpdateWorldBox();
    BoundingBox baseBox;
    BoundingBox worldBox;
    Model model;

    ~ServingStation();


};


#endif //CHEFGAME3D_SERVINGSTATION_H
//
// Created by Jason Evans on 29/11/2025.
//

#ifndef CHEFGAME3D_FOOD_H
#define CHEFGAME3D_FOOD_H
#include "raylib.h"

class Food {
public:
    Food();
    float posX;
    float posY;
    float posZ;

    bool isHeld;
    bool isSpawned;
    bool isPlaced;

    Vector3 position;
    BoundingBox baseBox;
    BoundingBox worldBox;

    Model rawModel;
    Model cookedModel;
    Model burntModel;
    Model currentModel;

    virtual void Draw() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void UpdateWorldBox() = 0;
    virtual void UpdateCooking(float deltaTime) = 0;

    virtual ~Food();
};


#endif //CHEFGAME3D_FOOD_H
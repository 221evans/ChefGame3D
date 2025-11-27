//
// Created by Jason Evans on 02/11/2025.
//

#ifndef CHEFGAME3D_STEAK_H
#define CHEFGAME3D_STEAK_H
#include "Raylib.h"

class Steak {
public:
    Steak();
    float posX;
    float posY;
    float posZ;

    bool isHeld;
    bool isSpawned;
    bool isPlaced;

    bool isCooking;
    bool isCooked;
    bool isBurnt;

    float cookingTimer;
    float timeToCook;
    float timeToBurn;

    Model rawModel;
    Model currentModel;
    Model cookedModel;
    Model burntModel;
    Vector3 position;
    BoundingBox baseBox;
    BoundingBox worldBox;

    void Draw();
    void Update(float deltaTime);
    void UpdateWorldBox();
    void UpdateCooking(float deltaTime);
    ~Steak();
};


#endif //CHEFGAME3D_STEAK_H

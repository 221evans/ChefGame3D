#pragma once
#include "raylib.h"

class Player {

public:

    Player();

    float posX;
    float posY;
    float posZ;
    float rotationAngle;

    Vector3 position;
    Model idleModel;

    BoundingBox baseBox;
    BoundingBox worldBox;


    void Draw();
    void Update(float deltaTime);
    void UpdateBoundingBox();
    ~Player();

};

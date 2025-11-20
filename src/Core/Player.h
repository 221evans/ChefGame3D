#pragma once
#include "raylib.h"

class Player {

public:

    Player();

    float posX;
    float posY;
    float posZ;
    float rotationAngle;
    float speed;

    Vector3 position;
    Model idleModel;

    BoundingBox baseBox;
    BoundingBox worldBox;


    void Draw();
    void Update(float deltaTime);
    void UpdateBoundingBox();
    ~Player();

};

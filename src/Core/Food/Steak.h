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

    Model rawModel;
    Model currentModel;
    Vector3 position;

    void Draw();
    void Update(float deltaTime);
    ~Steak();
};


#endif //CHEFGAME3D_STEAK_H
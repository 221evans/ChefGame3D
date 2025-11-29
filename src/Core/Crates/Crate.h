#ifndef CHEFGAME3D_CRATE_H
#define CHEFGAME3D_CRATE_H
#include "raylib.h"

class Crate {

public:
    Crate();
    float posX;
    float posY;
    float posZ;

    Model crateModel;
    Vector3 position;
    BoundingBox baseBox;
    BoundingBox worldBox;

    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void UpdateBoundingBox();

    virtual ~Crate();



};


#endif //CHEFGAME3D_CRATE_H
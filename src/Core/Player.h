#include "raylib.h"

class Player {

public:

    Player();
    float posX;
    float posY;
    float posZ;

    Vector3 positon;
    Model idleModel;

    void Draw();

    ~Player();

};

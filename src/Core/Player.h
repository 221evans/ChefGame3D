#include "raylib.h"

class Player {

public:

    Player();

    float posX;
    float posY;
    float posZ;
    float rotationAngle;

    Vector3 positon;
    Model idleModel;

    void Draw();
    void Update(float deltaTime);
    ~Player();

};

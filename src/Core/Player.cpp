#include "Player.h"
#include "raylib.h"

Player::Player() : posX(0),posY(0),posZ(0), rotationAngle(-180.0f), speed(3.0f){
    position = {posX,posY,posZ};
    idleModel = LoadModel("Assets/Player/Dummy.glb");
    baseBox = GetModelBoundingBox(idleModel);
}

void Player::Draw(){
    DrawModelEx(idleModel, position,(Vector3){0,1,0}, rotationAngle,(Vector3){1,1,1}, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Player::Update(float deltaTime){
    if (IsKeyDown(KEY_A)) {
        posX -= speed * deltaTime;

        if (rotationAngle != -90.0f) {
            rotationAngle = -90.0f;
        }
    }
    else if (IsKeyDown(KEY_D)){
        posX += speed * deltaTime;

        if (rotationAngle != -275.0f) {
            rotationAngle = -275.0f;
        }
    }
    else if (IsKeyDown(KEY_W)){
        posZ -= speed * deltaTime;

        if(rotationAngle != -180.0f){
            rotationAngle = -180.0f;
        }
    }
    else if (IsKeyDown(KEY_S)){
        posZ += speed * deltaTime;

        if(rotationAngle != 0){
            rotationAngle = 0;
        }
    }

   position = {posX,posY,posZ};

    UpdateBoundingBox();
}

void Player::UpdateBoundingBox() {

    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}


Player::~Player(){

    UnloadModel(idleModel);

}



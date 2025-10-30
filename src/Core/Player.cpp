#include "Player.h"
#include "raylib.h"

Player::Player() : posX(0),posY(0),posZ(0), rotationAngle(-180.0f){
    positon = {posX,posY,posZ};
    idleModel = LoadModel("Assets/Player/Dummy.glb");
}

void Player::Draw(){
   DrawModelEx(idleModel, positon,(Vector3){0,1,0}, rotationAngle,(Vector3){1,1,1}, WHITE); 
}

void Player::Update(float deltaTime){
    if (IsKeyDown(KEY_A)) {
        posX -= 1.0f * deltaTime;

        if (rotationAngle != -90.0f) {
            rotationAngle = -90.0f;
        }
    }
    else if (IsKeyDown(KEY_D)){
        posX += 1.0f * deltaTime;

        if (rotationAngle != -275.0f) {
            rotationAngle = -275.0f;
        }
    }
    else if (IsKeyDown(KEY_W)){
        posZ -= 1.0f * deltaTime;

        if(rotationAngle != -180.0f){
            rotationAngle = -180.0f;
        }
    }
    else if (IsKeyDown(KEY_S)){
        posZ += 1.0f * deltaTime;

        if(rotationAngle != 0){
            rotationAngle = 0;
        }
    }

   positon = {posX,posY,posZ};


}


Player::~Player(){

    UnloadModel(idleModel);

}



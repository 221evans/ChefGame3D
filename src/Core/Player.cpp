#include "Player.h"
#include "raylib.h"

Player::Player() : posX(0),posY(0),posZ(0){
    positon = {posX,posY,posZ};
    idleModel = LoadModel("Assets/Player/Dummy.glb");
}

void Player::Draw(){
   DrawModel(idleModel, positon, 1.0f, WHITE); 
}


Player::~Player(){

}



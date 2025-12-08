//
// Created by Jason Evans on 30/11/2025.
//

#include "ServingStation.h"

ServingStation::ServingStation() {

    posX = 0;
    posY = 0;
    posZ = 5;
    position = {posX,posY,posZ};

    model = LoadModel("Assets/Crates/kitchencounter_straight_B.obj");
    baseBox = GetModelBoundingBox(model);
}

void ServingStation::Draw() const {

    DrawModel(model, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void ServingStation::Update() {
    position = {posX, posY,posZ};



    UpdateWorldBox();


}

void ServingStation::UpdateWorldBox() {
    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}

ServingStation::~ServingStation() {
    UnloadModel(model);
}

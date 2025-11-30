//
// Created by Jason Evans on 29/11/2025.
//

#include "CarrotCrate.h"

CarrotCrate::CarrotCrate() {
    posX = -5;
    posY = 0;
    posZ = 0;
    position = {posX,posY,posZ};
    crateModel = LoadModel("Assets/Crates/crate_carrots.obj");
    baseBox = GetModelBoundingBox(crateModel);
}

void CarrotCrate::Draw() {
    DrawModel(crateModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void CarrotCrate::Update() {
    position = {posX, posY,posZ};
    UpdateBoundingBox();
}

CarrotCrate::~CarrotCrate() {
    UnloadModel(crateModel);
}

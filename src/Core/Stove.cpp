//
// Created by Jason Evans on 20/11/2025.
//

#include "Stove.h"

Stove::Stove() {
    model = LoadModel("Assets/Crates/stove_single.obj");
    posX = 5;
    posY = 0;
    posZ = 0;
    position = {posX,posY,posZ};
    baseBox = GetModelBoundingBox(model);
}

void Stove::Draw() const {
    DrawModel(model, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Stove::Update() {
    position = {posX,posY,posZ};
    UpdateWorldBox();
}

void Stove::UpdateWorldBox() {

    TraceLog(LOG_INFO, "Stove world box updated to: %.2f %.2f %.2f",
    worldBox.min.x + position.x,
    worldBox.min.y + position.y,
    worldBox.min.z + position.z
);

    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}

Stove::~Stove() {
    UnloadModel(model);
}


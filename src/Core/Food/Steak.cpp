//
// Created by Jason Evans on 02/11/2025.
//

#include "Steak.h"

Steak::Steak() : posX(0), posY(0), posZ(2),isHeld(false), isSpawned(false) {

    rawModel = LoadModel("Assets/Crates/food_ingredient_steak.obj");
    currentModel = rawModel;
    baseBox = GetModelBoundingBox(rawModel);
}

void Steak::Draw() {
    DrawModel(currentModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Steak::Update(float deltaTime) {
    position = {posX, posY,posZ};

    if (!isHeld) {

        if (posY > 0.0f) {
            posY -= 1.0f * deltaTime;
        }
    }

    UpdateWorldBox();
}

void Steak::UpdateWorldBox() {
    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}

Steak::~Steak() {
}

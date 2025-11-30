//
// Created by Jason Evans on 30/11/2025.
//

#include "Carrot.h"

Carrot::Carrot() {
    posX = 0;
    posY = 0;
    posZ = 0;
    position = {posX,posY,posZ};
    rawModel = LoadModel("Assets/Crates/food_ingredient_carrot.obj");
    currentModel = rawModel;
    baseBox = GetModelBoundingBox(currentModel);

    isHeld = false;
    isPlaced = false;
    isSpawned = false;
}

void Carrot::Draw() {
    DrawModel(currentModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Carrot::Update(float deltaTime) {
    UpdateWorldBox();

    position = {posX,posY,posZ};

    // Apply Gravity
    if (!isHeld && !isPlaced) {
        if (posY > 0.0f) {
            posY -= 1.0f * deltaTime;
        }
    }

    // Cooking logic here if needed
}

void Carrot::UpdateWorldBox() {
    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}

void Carrot::UpdateCooking(float deltaTime) {
    // Cooking logic here if needed
}

Carrot::~Carrot() {
    UnloadModel(rawModel);
}

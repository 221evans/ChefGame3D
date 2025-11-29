//
// Created by Jason Evans on 02/11/2025.
//

#include "Steak.h"
#include <iostream>
#include <ostream>

Steak::Steak() : posX(0), posY(0), posZ(2),isHeld(false), isSpawned(false),
                 isPlaced(false), isCooking(false), isCooked(false), isBurnt(false),
                 cookingTimer(0.0f), timeToCook(5.0f), timeToBurn(8.0f) {

    rawModel = LoadModel("Assets/Crates/food_ingredient_steak.obj");
    cookedModel = LoadModel("Assets/Crates/cookedSteak.glb");
    burntModel = LoadModel("Assets/Crates/burntSteak.glb");
    currentModel = rawModel;
    baseBox = GetModelBoundingBox(rawModel);
    
}

void Steak::Draw() {
    DrawModel(currentModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Steak::Update(float deltaTime) {
    position = {posX, posY,posZ};

    // Apply Gravity
    if (!isHeld && !isPlaced) {

        if (posY > 0.0f) {
            posY -= 1.0f * deltaTime;
        }
    }

    if (isCooking) {
        UpdateCooking(deltaTime);
    }

    if (isCooked) {
        currentModel = cookedModel;
    }
    if (isBurnt) {
        currentModel = burntModel;
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

void Steak::UpdateCooking(float deltaTime) {

    cookingTimer += deltaTime;

    if (!isCooked && cookingTimer >= timeToCook) {
        isCooked = true;
        std::cout << "Cooked Steak" << std::endl;
    }
    else if (isCooked && cookingTimer >= timeToBurn) {
        isBurnt = true;
        std::cout << "Burnt Steak" << std::endl;
    }
}

Steak::~Steak() {
    UnloadModel(rawModel);
    UnloadModel(cookedModel);
    UnloadModel(burntModel);
}

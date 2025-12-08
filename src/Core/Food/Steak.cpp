//
// Created by Jason Evans on 02/11/2025.
//

#include "Steak.h"
#include <iostream>
#include <ostream>

Steak::Steak() : isCooking(false),
                 isCooked(false),isBurnt(false),
                 cookingTimer(0.0f), timeToCook(5.0f), timeToBurn(8.0f) {

    posX = 0;
    posY = 0;
    posZ = 0;
    position = {posX, posY,posZ};
    rawModel = LoadModel("Assets/Crates/food_ingredient_steak.obj");
    cookedModel = LoadModel("Assets/Crates/cookedSteak.glb");
    burntModel = LoadModel("Assets/Crates/burntSteak.glb");
    currentModel = rawModel;
    baseBox = GetModelBoundingBox(currentModel);


}

void Steak::Draw() {
    DrawModel(currentModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void Steak::Update(float deltaTime) {

    UpdateWorldBox();

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


}

void Steak::UpdateCooking(float deltaTime) {

    cookingTimer += deltaTime;

    if (!isCooked && cookingTimer >= timeToCook) {
        isCooked = true;
        std::cout << "Cooked Steak" << std::endl;
    }
    else if (cookingTimer >= timeToBurn) {
        isBurnt = true;
        isCooked = false;
        std::cout << "Burnt Steak" << std::endl;
    }
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

void Steak::HandlePickUp(Player *player) {

    if (isHeld) {
        posX = player->posX;
        posY = player->posY + 1.2f;
        posZ = player->posZ + 1.0f;
    }
}

Steak::~Steak() {
    UnloadModel(rawModel);
    UnloadModel(cookedModel);
    UnloadModel(burntModel);
}

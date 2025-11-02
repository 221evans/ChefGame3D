//
// Created by Jason Evans on 02/11/2025.
//

#include "Steak.h"

Steak::Steak() : posX(0), posY(0), posZ(2),isHeld(false) {

    rawModel = LoadModel("Assets/Crates/food_ingredient_steak.obj");
    currentModel = rawModel;
}

void Steak::Draw() {
    DrawModel(currentModel, position, 1.0f, WHITE);
}

void Steak::Update(float deltaTime) {
    position = {posX, posY,posZ};
}

Steak::~Steak() {
}

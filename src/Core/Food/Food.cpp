//
// Created by Jason Evans on 29/11/2025.
//

#include "Food.h"

Food::Food() :rawModel(), cookedModel(), burntModel() {
    posX = 0;
    posY = 0;
    posZ = 0;
    position = {0,0,0};
    isHeld = false;
    isPlaced = false;
    isSpawned = false;

    baseBox = {0};
    worldBox = {0};
}


void Food::UpdateWorldBox() {

}

Food::~Food() = default;

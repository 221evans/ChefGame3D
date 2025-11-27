//
// Created by Jason Evans on 08/11/2025.
//

#include "Game.h"

#include <iostream>

Game::Game() = default;


void Game::Draw() {
    steakCrate.Draw();
    player.Draw();
    stove.Draw();
}

void Game::Update(float deltaTime) {
    steakCrate.Update();
    steak.Update(deltaTime);
    player.Update(deltaTime);
    stove.Update();

    if (steak.isSpawned) {
        steak.Draw();
    }

    if (steak.isHeld) {
        steak.posX = player.posX;
        steak.posY = player.posY + 1.0f;
        steak.posZ = player.posZ + 0.5f;
    }

    if (CheckCollisionBoxes(player.worldBox, steakCrate.worldBox) && IsKeyDown(KEY_E)) {
        steak.isSpawned = true;
        steak.isHeld = true;
        steak.isPlaced = false;
        steak.isCooking = false;
    }

    if (CheckCollisionBoxes(steak.worldBox, player.worldBox) && !steak.isHeld && IsKeyDown(KEY_E)) {
        steak.isHeld = true;
        steak.isPlaced = false;
        steak.isCooking = false;
    }

    if (IsKeyDown(KEY_F)) {
        steak.isHeld = false;
    }

    if (CheckCollisionBoxes(player.worldBox, stove.worldBox) && steak.isHeld && IsKeyDown(KEY_Q)) {
        steak.posX = stove.posX;
        steak.posY = stove.posY + 1.2f;
        steak.posZ = stove.posZ;

        steak.isHeld = false;
        steak.isPlaced = true;
        steak.isCooking = true;
    }

}

Game::~Game() = default;



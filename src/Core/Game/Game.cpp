//
// Created by Jason Evans on 08/11/2025.
//

#include "Game.h"

#include <iostream>

Game::Game() : heldSteak(nullptr), heldCarrot(nullptr) {

}


void Game::Draw() {

    for (auto* steak : steaks) {
        steak->Draw();
    }

    for (auto* carrot : carrots) {
        carrot->Draw();
    }

    steakCrate.Draw();
    carrotCrate.Draw();
    player.Draw();
    stove.Draw();
    servingStation.Draw();
}

void Game::Update(float deltaTime) {


    player.Update(deltaTime);
    servingStation.Update();
    stove.Update();
    HandleSteakUpdate(deltaTime);
    HandleCarrotUpdate(deltaTime);
    HandleServingStationUpdate(deltaTime);
}


void Game::HandleSteakUpdate(float deltaTime) {

    steakCrate.Update();

    for (auto steak : steaks) {
        steak->Update(deltaTime);

        if (steak->isHeld) {
            steak->posX = player.posX;
            steak->posY = player.posY + 1.2f;
            steak->posZ = player.posZ + 1.0f;
        }
    }

    // Spawn a new steak from the crate
    if (CheckCollisionBoxes(steakCrate.worldBox, player.worldBox)) {
        if (IsKeyPressed(KEY_E)) {
            auto* newSteak = new Steak();
            steaks.push_back(newSteak);

            heldSteak = newSteak;
            heldSteak->isHeld = true;
        }
    }

    // Drop steak
    if (IsKeyPressed(KEY_F)) {
        if (heldSteak) {
            heldSteak->isHeld = false;
            heldSteak = nullptr;
        }
    }

    if (heldSteak) {
        if (CheckCollisionBoxes(player.worldBox, stove.worldBox) && IsKeyPressed(KEY_Q)) {
            heldSteak->posX = stove.posX;
            heldSteak->posY = stove.posY + 1.2f;
            heldSteak->posZ = stove.posZ;
            heldSteak->isPlaced = true;
            heldSteak->isHeld = false;
            heldSteak->isCooking = true;
            heldSteak = nullptr;

        }
    }

    // pickup already spawned steak
   for (auto steak : steaks) {
       if (CheckCollisionBoxes(steak->worldBox,player.worldBox)) {
           if (IsKeyPressed(KEY_E)) {
               heldSteak = steak;
               heldSteak->isHeld = true;
               heldSteak->isCooking = false;
               heldSteak->isPlaced = false;
           }
       }
   }
}

void Game::HandleCarrotUpdate(float deltaTime) {

    carrotCrate.Update();

    for (auto carrot : carrots) {
        carrot->Update(deltaTime);

        if (carrot->isHeld) {
            carrot->posX = player.posX;
            carrot->posY = player.posY + 1.2f;
            carrot->posZ = player.posZ + 1.0f;
        }
    }

    if (CheckCollisionBoxes(carrotCrate.worldBox, player.worldBox)) {

        // Spawn new Carrot
        if (IsKeyPressed(KEY_E)) {
            auto* newCarrot = new Carrot();
            carrots.push_back(newCarrot);

            heldCarrot = newCarrot;
            heldCarrot->isHeld = true;
        }
    }

    if (IsKeyPressed(KEY_F)) {
        if (heldCarrot) {
            heldCarrot->isHeld = false;
            heldCarrot = nullptr;
        }
    }

    if (heldCarrot) {
        if (CheckCollisionBoxes(player.worldBox, stove.worldBox) && IsKeyPressed(KEY_Q)) {
            heldCarrot->posX = stove.posX;
            heldCarrot->posY = stove.posY + 1.2f;
            heldCarrot->posZ = stove.posZ;
            heldCarrot->isPlaced = true;
            heldCarrot->isHeld = false;
        }
    }
}

void Game::HandleServingStationUpdate(float deltaTime) {
}


Game::~Game() = default;



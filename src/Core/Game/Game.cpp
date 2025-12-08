//
// Created by Jason Evans on 08/11/2025.
//

#include "Game.h"

#include <forward_list>
#include <iostream>

Game::Game() : isFoodHeld(false), score(0), heldSteak(nullptr), heldCarrot(nullptr) {}


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

    DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, RED);
}


void Game::HandleSteakUpdate(float deltaTime) {

    steakCrate.Update();

    for (auto steak : steaks) {
        steak->Update(deltaTime);

        steak->HandlePickUp(&player);
    }

    // Spawn a new steak from the crate
    if (CheckCollisionBoxes(steakCrate.worldBox, player.worldBox) && !isFoodHeld) {
        if (IsKeyPressed(KEY_E)) {
            auto* newSteak = new Steak();
            steaks.push_back(newSteak);
            heldSteak = newSteak;
            heldSteak->isHeld = true;
            isFoodHeld = true;
        }
    }

    // Drop steak
    if (IsKeyPressed(KEY_F)) {
        if (heldSteak) {
            heldSteak->isHeld = false;
            heldSteak = nullptr;
            isFoodHeld = false;
        }
    }

    if (heldSteak) {
        if (CheckCollisionBoxes(player.worldBox, stove.worldBox)) {

            if (IsKeyPressed(KEY_Q)) {
                heldSteak->posX = stove.posX;
                heldSteak->posY = stove.posY + 1.2f;
                heldSteak->posZ = stove.posZ;
                heldSteak->isPlaced = true;
                heldSteak->isHeld = false;
                heldSteak->isCooking = true;
                heldSteak = nullptr;
                isFoodHeld = false;
            }
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
               isFoodHeld = true;
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
            isFoodHeld = true;
        }
    }

    if (IsKeyPressed(KEY_F)) {
        if (heldCarrot) {
            heldCarrot->isHeld = false;
            heldCarrot = nullptr;
            isFoodHeld = false;
        }
    }

    if (heldCarrot) {
        if (CheckCollisionBoxes(player.worldBox, stove.worldBox)) {

            if (IsKeyPressed(KEY_Q)) {
                heldCarrot->posX = stove.posX;
                heldCarrot->posY = stove.posY + 1.2f;
                heldCarrot->posZ = stove.posZ;
                heldCarrot->isPlaced = true;
                heldCarrot->isHeld = false;
                heldCarrot = nullptr;
                isFoodHeld = false;
            }
        }
    }
}

void Game::HandleServingStationUpdate(float deltaTime) {
    for (auto steak : steaks) {

        if (CheckCollisionBoxes(player.worldBox, servingStation.worldBox)) {
            if (steak->isHeld && steak->isCooked && !steak->isBurnt) {
                if (IsKeyPressed(KEY_E)) {
                    std::erase(steaks, heldSteak);
                    delete heldSteak;
                    heldSteak = nullptr;
                    isFoodHeld = false;
                    score++;
                }
            }

            if (steak->isBurnt) {
                DrawText("Can't Serve burnt food! ", 200,10,20, RED);
            }

        }
    }

    // just for debugging purposes at the moment. Don't think carrots will be served directly
    for (auto carrot : carrots) {
        if (CheckCollisionBoxes(player.worldBox, servingStation.worldBox)) {
            if (carrot->isHeld) {
                if (IsKeyPressed(KEY_E)) {
                    std::erase(carrots, heldCarrot);
                    delete heldCarrot;
                    heldCarrot = nullptr;
                    isFoodHeld = false;
                    score ++;
                }
            }
        }
    }
}


Game::~Game() = default;



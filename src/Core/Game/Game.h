//
// Created by Jason Evans on 08/11/2025.
//

#ifndef CHEFGAME3D_GAME_H
#define CHEFGAME3D_GAME_H

#include "../Food/Steak.h"
#include "../Food/Carrot.h"
#include "../ServingStation.h"
#include "../Crates/CarrotCrate.h"
#include "../Crates/SteakCrate.h"
#include "../Player.h"
#include "../Stove.h"
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void Draw();
    void Update(float deltaTime);
private:

    void HandleSteakUpdate(float deltaTime);
    void HandleCarrotUpdate(float deltaTime);
    void HandleServingStationUpdate(float deltaTime);

    bool isFoodHeld;

    SteakCrate steakCrate;
    CarrotCrate carrotCrate;
    ServingStation servingStation;
    std::vector<Steak*> steaks;
    std::vector<Carrot*> carrots;
    Steak *heldSteak;
    Carrot *heldCarrot;
    Player player;
    Stove stove;
};


#endif //CHEFGAME3D_GAME_H
//
// Created by Jason Evans on 08/11/2025.
//

#ifndef CHEFGAME3D_GAME_H
#define CHEFGAME3D_GAME_H

#include "../Food/Steak.h"
#include "../Crates/Crate.h"
#include "../Crates/SteakCrate.h"
#include "../Player.h"
#include "../Stove.h"

class Game {
public:
    SteakCrate steakCrate;
    Steak steak;
    Player player;
    Stove stove;
    Game();
    void Draw();
    void Update(float deltaTime);
    ~Game();
};


#endif //CHEFGAME3D_GAME_H
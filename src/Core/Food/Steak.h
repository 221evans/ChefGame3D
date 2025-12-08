//
// Created by Jason Evans on 02/11/2025.
//

#ifndef CHEFGAME3D_STEAK_H
#define CHEFGAME3D_STEAK_H
#include "Food.h"
#include "raylib.h"
#include  "../Player.h"
class Steak : public Food{
public:
    Steak();

    bool isCooking;
    bool isCooked;
    bool isBurnt;

    float cookingTimer;
    float timeToCook;
    float timeToBurn;

    Vector3 position;

    void Draw() override;
    void Update(float deltaTime) override;
    void UpdateCooking(float deltaTime) override;
    void UpdateWorldBox() override;
    void HandlePickUp(Player* player);
    ~Steak() override;
};


#endif //CHEFGAME3D_STEAK_H

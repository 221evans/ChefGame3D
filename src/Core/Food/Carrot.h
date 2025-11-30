//
// Created by Jason Evans on 30/11/2025.
//

#ifndef CHEFGAME3D_CARROT_H
#define CHEFGAME3D_CARROT_H
#include "Food.h"


class Carrot : public  Food {
public:
    Carrot();
    void Draw() override;
    void Update(float deltaTime) override;
    void UpdateWorldBox() override;
    void UpdateCooking(float deltaTime) override;
    ~Carrot() override;
};


#endif //CHEFGAME3D_CARROT_H
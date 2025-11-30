//
// Created by Jason Evans on 29/11/2025.
//

#ifndef CHEFGAME3D_BURGERCRATE_H
#define CHEFGAME3D_BURGERCRATE_H
#include "../Crates/Crate.h"

class CarrotCrate : public Crate {
public:
    CarrotCrate();
    void Draw() override;
    void Update() override;

    ~CarrotCrate() override;
};


#endif //CHEFGAME3D_BURGERCRATE_H
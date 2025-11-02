#include "SteakCrate.h"


SteakCrate::SteakCrate() : posX(0), posY(0), posZ(0){
    position = {posX, posY,posZ};
    crateModel = LoadModel("Assets/Crates/crate_steak.obj");
    baseBox = GetModelBoundingBox(crateModel);
}

void SteakCrate::Draw(){
    DrawModel(crateModel, position, 1.0f, WHITE);
    DrawBoundingBox(baseBox, RED);
}

void SteakCrate::Update() {

    position = {posX, posY,posZ};
}

SteakCrate::~SteakCrate(){

}

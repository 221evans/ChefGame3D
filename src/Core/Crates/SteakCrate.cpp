#include "SteakCrate.h"


SteakCrate::SteakCrate() : posX(0), posY(0), posZ(0) {
    position = {posX, posY,posZ};
    crateModel = LoadModel("Assets/Crates/crate_steak.obj");
    baseBox = GetModelBoundingBox(crateModel);
}

void SteakCrate::Draw(){
    DrawModel(crateModel, position, 1.0f, WHITE);
    DrawBoundingBox(worldBox, RED);
}

void SteakCrate::Update() {
    position = {posX, posY,posZ};
    UpdateBoundingBox();
}

void SteakCrate::UpdateBoundingBox() {
    worldBox = baseBox;

    worldBox.min.x += position.x;
    worldBox.min.y += position.y;
    worldBox.min.z += position.z;

    worldBox.max.x += position.x;
    worldBox.max.y += position.y;
    worldBox.max.z += position.z;
}

SteakCrate::~SteakCrate() {
    UnloadModel(crateModel);
}

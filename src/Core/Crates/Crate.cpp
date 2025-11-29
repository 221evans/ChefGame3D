//
// Created by Jason Evans on 28/11/2025.
//

#include "Crate.h"

Crate::Crate() : crateModel() {
 posX = 0;
 posY = 0;
 posZ = 0;
 position = {0, 0, 0};
 baseBox = GetModelBoundingBox(crateModel);

 worldBox = {0};
}

void Crate::UpdateBoundingBox() {
 worldBox = baseBox;

 worldBox.min.x += position.x;
 worldBox.min.y += position.y;
 worldBox.min.z += position.z;

 worldBox.max.x += position.x;
 worldBox.max.y += position.y;
 worldBox.max.z += position.z;
}

Crate::~Crate() = default;





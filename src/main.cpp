#include <iostream>
#include <ostream>

#include "raylib.h"
#include "Core/Player.h"
#include "Core/Crates/SteakCrate.h"
#include "Core/Food/Steak.h"

int main(){
    int windowWidth = 800;
    int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "Chef Game 3D");

    //Create 3D Camera
    Camera3D camera;
    Player player;
    SteakCrate steakCrate;
    Steak steak;

    camera.position = (Vector3){0.0f,10.0f,10.0f};
    camera.target = (Vector3){0.0f,0.0f,0.0f};
    camera.up = (Vector3){0.0f,1.0f,0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        player.Update(deltaTime);
        DrawGrid(20,1);
        player.Draw();
        steakCrate.Draw();

        if (CheckCollisionBoxes(player.worldBox, steakCrate.baseBox) && IsKeyPressed(KEY_E)) {
            steak.isHeld = true;
        }
        else if (IsKeyPressed(KEY_F)) {
            steak.isHeld = false;
        }

        if (steak.isHeld) {
            steak.Update(deltaTime);
            steak.Draw();
            steak.posX = player.posX + 1;
            steak.posY = player.posY + 1;
            steak.posZ = player.posZ;
        }
        EndMode3D();
        EndDrawing();

    
    };
    return 0;
};

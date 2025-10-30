#include "raylib.h"
#include "Core/Player.h"
int main(){
    int windowWidth = 800;
    int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "Chef Game 3D");

    //Create 3D Camera
    Camera3D camera;
    Player player;
    camera.position = (Vector3){0.0f,10.0f,10.0f};
    camera.target = (Vector3){0.0f,0.0f,0.0f};
    camera.up = (Vector3){0.0f,1.0f,0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 position = {0.0f,0.0f,0.0f};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawGrid(20,1);
        player.Draw();
        EndMode3D();
        EndDrawing();

    
    }
    return 0;
};

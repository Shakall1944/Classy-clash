#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{

    // window dimensions
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy clash game!");

    // Load map from texture
    Texture2D worldmap = LoadTexture("nature_tileset/WorldMap32x32.png");
    float worldPosX{};
    float worldPosY{};
    Vector2 worldPos{worldPosX, worldPosY};
    // create instance Character + set screen position

    Character knigth;
    knigth.setScreenPos(windowDimensions[0],windowDimensions[1]);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        worldPos = Vector2Scale(knigth.getWorldPos(), -1.f);

        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, 4, WHITE);

        // tick function + pass GetFrameTime
        knigth.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(worldmap);
    CloseWindow();
}
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
    const float mapScale{4.f};
    
    // create instance Character + set screen position
    Character knigth{windowDimensions[0],windowDimensions[1]};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        worldPos = Vector2Scale(knigth.getWorldPos(), -1.f);

        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, mapScale, WHITE);

        // tick function + pass GetFrameTime
        knigth.tick(GetFrameTime());
        // check map bounds
        if (knigth.getWorldPos().x < 0.f || 
            knigth.getWorldPos().y < 0.f ||
            knigth.getWorldPos().x + windowDimensions[0] > worldmap.width * mapScale ||
            knigth.getWorldPos().y + windowDimensions[1] > worldmap.height * mapScale
            )
        {
            //stop making moves funtions 
            knigth.undoMovement();
        }

        EndDrawing();
    }
    UnloadTexture(worldmap);
    CloseWindow();
}
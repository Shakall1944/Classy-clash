#include "raylib.h"

int main()
{

    //window dimensions
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy clash game!");
    
    //Load map from texture
    Texture2D worldmap = LoadTexture("nature_tileset/WorldMap32x32.png");
    float worldPosX{};
    float worldPosY{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        //Start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        

        Vector2 worldPos{worldPosX - worldmap.width/2, worldPosY - worldmap.height/2};
        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, 4, WHITE);

        EndDrawing();
    }
    UnloadTexture(worldmap);
    CloseWindow();

}
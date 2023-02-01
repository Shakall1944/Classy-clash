#include "raylib.h"

int main()
{

    //window dimensions
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy clash game!");

    // show map on the window
    Texture2D worldmap = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 worldPos{0,0};
    DrawTextureEx(worldmap, worldPos, 0.0, 4, WHITE);

}
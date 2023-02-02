#include "raylib.h"
#include "raymath.h"

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
    Vector2 worldPos{worldPosX - worldmap.width/2, worldPosY - worldmap.height/2};
    float speed{4.0};
    
    //load character
    Texture2D knigth = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knigthPos{
        (float)windowDimensions[0]/2.0f - 4.0f * (0.5f * (float)knigth.width/6.0f),
        (float)windowDimensions[1]/2.0f - 4.0f * (0.5f * (float)knigth.height)
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        //Start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        
        Vector2 direction{};

        
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            //set worldPos = worldPos - direction + scale vector
            
            worldPos = Vector2Subtract(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, 4, WHITE);
        // draw the character
        Rectangle source;
        source.width = (float)knigth.width/6.f;
        source.height = (float)knigth.height;
        source.x = 0.0;
        source.y = 0.0;

        Rectangle dest;
        dest.width = 4.0f * (float)knigth.width/6;
        dest.height = 4.0f * (float)knigth.height;
        dest.x = knigthPos.x;
        dest.y = knigthPos.y;
        Vector2 origin{};
        DrawTexturePro(knigth, source, dest, origin, 0.f, WHITE);

        EndDrawing();
    }
    UnloadTexture(worldmap);
    CloseWindow();

}
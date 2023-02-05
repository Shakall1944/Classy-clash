#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"

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
    //create an instance of prop and def. it with Array
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };
    
    // collision variable
    //bool collision{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        worldPos = Vector2Scale(knigth.getWorldPos(), -1.f);

        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, mapScale, WHITE);

        // draw the prop with Render funtion and knigth function from array
        for (auto prop : props)
        {
            prop.Render(knigth.getWorldPos());
        }
        
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
        // check collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.GetCollisionRec(knigth.getWorldPos()), knigth.GetCollisionRec()))
            {
                knigth.undoMovement();
            }
        }
        
        EndDrawing();
    }
    UnloadTexture(worldmap);
    CloseWindow();
}
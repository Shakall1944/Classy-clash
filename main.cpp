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
    
    //load idle character
    Texture2D knigth = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knigthPos{
        (float)windowDimensions[0]/2.0f - 4.0f * (0.5f * (float)knigth.width/6.0f),
        (float)windowDimensions[1]/2.0f - 4.0f * (0.5f * (float)knigth.height)
    };
    // load running and idle character
    Texture2D knigth_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knigth_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    
    // 1 : facing right direction, -1 we are facing the left direc
    float rightLeft{1.f};
    // animation variables
    float runningTime{0.0};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // delta time variable - time since last frame
        const float dT{GetFrameTime()};
        //Start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        
        //set the direction variable for the movement
        Vector2 direction{};

        // set the movement to all directions
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            //set worldPos = worldPos - direction + scale vector, it's opposite to windows
            
            worldPos = Vector2Subtract(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
            /*if (direction.x < 0.f)
            {
                rightLeft = -1.f;
            }
            else
            {
                rightLeft = 1.f;
            }*/
            //this is the same code as aobe if statement
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knigth = knigth_run;

        }
        else
        {
            knigth = knigth_idle;
        }
        
        
        // update animation frame
        runningTime += dT;
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }

        // draw map on the window
        DrawTextureEx(worldmap, worldPos, 0.0, 4, WHITE);
        // draw the character in the center of window
        Rectangle source;
        source.width = rightLeft * (float)knigth.width/6.f;
        source.height = (float)knigth.height;
        source.x = frame * (float)knigth.width/6.f;
        source.y = 0.f;

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
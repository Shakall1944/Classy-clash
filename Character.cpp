#include "Character.h"
#include "raymath.h"

Character::Character ()
{   
    width = texture.width / maxFrames;
    heigth = texture.height;
}

void Character::setScreenPos(int windWidth, int winHeight)
{
    screenPos = {
        (float)windWidth / 2.0f - 4.0f * (0.5f * width),
        (float)windWidth / 2.0f - 4.0f * (0.5f * heigth)
    };
}

void Character::tick(float deltaTime)
{
    // set the direction variable for the movement
    Vector2 direction{};
    // set the movement to all directions
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // set worldPosChar = worldPosChar + direction + scale vector

        worldPosChar = Vector2Add(worldPosChar, Vector2Scale(Vector2Normalize(direction), speed));
        /*if (direction.x < 0.f)
        {
                rightLeft = -1.f;
        }
        elsewidth
        {
            rightLeft = 1.f;
        }*/
        // this is the same code as aobe if statement
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
    // draw the character in the center of window
    Rectangle source;
    source.width = rightLeft * width;
    source.height = heigth;
    source.x = frame * width;
    source.y = 0.f;

    Rectangle dest;
    dest.width = 4.0f * width;
    dest.height = 4.0f * heigth;
    dest.x = screenPos.x;
    dest.y = screenPos.y;
    Vector2 origin{};

    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}

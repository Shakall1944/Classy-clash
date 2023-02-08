#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
    
}

//stop making moves funtions
void BaseCharacter::undoMovement()
{
    worldPosChar = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return Rectangle{
    screenPos.x,
    screenPos.y,
    width * scale,
    heigth * scale
    };
}

void BaseCharacter::tick(float deltaTime)
{
        // set variable of last position
    worldPosLastFrame = worldPosChar;

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
    dest.width = scale * width;
    dest.height = scale * heigth;
    dest.x = screenPos.x;
    dest.y = screenPos.y;
    Vector2 origin{};

    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}


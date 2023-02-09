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
    getScreenPos().x,
    getScreenPos().y,
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

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPosChar = worldPosChar + velocity + scale vector

        worldPosChar = Vector2Add(worldPosChar, Vector2Scale(Vector2Normalize(velocity), speed));
        /*if (direction.x < 0.f)
        {
                rightLeft = -1.f;
        }
        elsewidth
        {
            rightLeft = 1.f;
        }*/
        // this is the same code as aobe if statement
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
        // animation from baseChar class

    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // draw the character in the center of window
    Rectangle source;
    source.width = rightLeft * width;
    source.height = heigth;
    source.x = frame * width;
    source.y = 0.f;

    Rectangle dest;
    dest.width = scale * width;
    dest.height = scale * heigth;
    dest.x = getScreenPos().x;
    dest.y = getScreenPos().y;
    Vector2 origin{};

    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}


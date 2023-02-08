#include "Character.h"
#include "raymath.h"

Character::Character(int windWidth, int winHeigth)
{   
    width = texture.width / maxFrames;
    heigth = texture.height;
    screenPos = {
        static_cast<float>(windWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(winHeigth) / 2.0f - scale * (0.5f * heigth)
    };
}



/*void Character::setScreenPos(int windWidth, int winHeight)
{
    screenPos = {
        (float)windWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * heigth)
    };
}*/

void Character::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);
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

}



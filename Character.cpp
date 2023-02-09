#include "Character.h"
#include "raymath.h"

Character::Character(int windWidth, int winHeigth) :
    windowWidth(windWidth),
    windowHeight(winHeigth)
{   
    width = texture.width / maxFrames;
    heigth = texture.height;
  
}

/*void Character::setScreenPos(int windWidth, int winHeight)
{
    screenPos = {
        (float)windWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * heigth)
    };
}*/
Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * heigth)
    };

}

void Character::tick(float deltaTime)
{
    
    // set the direction variable for the movement
    
    // set the movement to all directions
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    
    BaseCharacter::tick(deltaTime);


}



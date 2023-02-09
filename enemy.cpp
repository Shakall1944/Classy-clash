#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPosChar = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    heigth = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{   
    //this is pseudo code
    //Get toTarget we will setup vector to character

    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    //we use Vector2SNormalize for toTarget vector + multiply it with speed
    //toTarget = Vector2Normalize(toTarget);
    //toTarget = Vector2Scale(toTarget, speed);
    //move enemy using set worldPosChar
    //worldPosChar = Vector2Add(worldPosChar, toTarget);
    // set position of enemy using pointer to char
    //function for normalizing, scaling, adding vector
    BaseCharacter::tick(deltaTime);

}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPosChar, target->getWorldPos());
        
}
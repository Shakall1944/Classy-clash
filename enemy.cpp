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
}

void Enemy::tick(float deltaTime)
{   
    // set postion of enemy using pointer to char
    screenPos = Vector2Subtract(worldPosChar, target->getWorldPos());
    BaseCharacter::tick(deltaTime);

}


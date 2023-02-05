#include "enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) :
    worldPosChar(pos),
    texture(idle_texture),
    idle(idle_texture),
    run(run_texture)
{
    width = texture.width / maxFrames;
    heigth = texture.height;
}

void Enemy::tick(float deltaTime)
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

void Enemy::undoMovement()
{
    worldPosChar = worldPosLastFrame;
}

Rectangle Enemy::GetCollisionRec()
{
    return Rectangle{
    screenPos.x,
    screenPos.y,
    width * scale,
    heigth * scale
    };
}
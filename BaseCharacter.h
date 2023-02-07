#include "raylib.h"
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

class BaseCharacter
{
    public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPosChar; }
    //void setScreenPos(int windWidth, int winHeight);
    void undoMovement();
    Rectangle GetCollisionRec();

    protected:

    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPosChar{};
    Vector2 worldPosLastFrame{};
    // 1 : facing right direction, -1 we are facing the left direc
    float rightLeft{1.f};
    // animation variables
    float runningTime{0.0};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float heigth{};
    float scale{4.f};

    private:
};

#endif
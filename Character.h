#ifndef CHARACTER_H
#define CHARACTER_H

// class for char
#include "raylib.h"
#include "BaseCharacter.h"


class Character : public BaseCharacter
{
public:
    Character(int winWith, int winHeigth);
    //void setScreenPos(int windWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisonRec() { return weaponCollisionRec; }


private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
};
#endif
#ifndef CHARACTER_H
#define CHARACTER_H

// class for char
#include "raylib.h"
#include "BaseCharacter.h"


class Character : public BaseCharacter
{
private:


public:
    Character(int winWith, int winHeigth);
    //void setScreenPos(int windWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    Vector2 getScreenPos() { return screenPos; }
};

#endif
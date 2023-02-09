#ifndef CHARACTER_H
#define CHARACTER_H

// class for char
#include "raylib.h"
#include "BaseCharacter.h"


class Character : public BaseCharacter
{
private:
    int windowWidth{};
    int windowHeight{};

public:
    Character(int winWith, int winHeigth);
    //void setScreenPos(int windWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
};

#endif
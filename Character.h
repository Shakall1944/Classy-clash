// class for char
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
private:


public:
    Character(int winWith, int winHeigth);
    //void setScreenPos(int windWidth, int winHeight);
    void tick(float deltaTime);
};
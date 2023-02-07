#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
    
}

//stop making moves funtions
void BaseCharacter::undoMovement()
{
    worldPosChar = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return Rectangle{
    screenPos.x,
    screenPos.y,
    width * scale,
    heigth * scale
    };
}


#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    // void setScreenPos(int windWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    // funtion to call a pointer to char
    void setTarget(Character* character) {target = character;}
    virtual Vector2 getScreenPos() override;

private:
    // pointer to knigth
    Character* target;
    

};

#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    static float Speed;
    static float Hp;
    static float MaxHp;
    static float Exp;
    static float MaxExp;
    static int Lv;
    static int Damage;
    static int PlayerScore;


    texture* hp;
    texture* exp;

    Timer* Score;

    Timer* Attack_Timer;
    Timer* Homing_Bullet_Timer;

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};


#pragma once
#include "Object.h"
class M_Enemy :
    public Object
{
    Timer* Enemy_Attack;

    VECtexture* explosion;
    Timer* ex_Timer;
    int ex_Index;

    int Hp;
    int Speed;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};


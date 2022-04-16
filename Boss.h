#pragma once
#include "Object.h"
class Boss :
    public Object
{
    VECtexture* Idle;

    Timer* Idle_Timer;
    Timer* Move_Timer;
    Timer* Attack_Timer;
    Timer* Around_Attack;
    Timer* Pattern_1_Timer;

    int Anim_Index;

    int i;
    int Speed;
    int Count;
    int Hp;
    int num;
    bool isMove;

    bool Attack;

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;

    void BossPattern_1();
};


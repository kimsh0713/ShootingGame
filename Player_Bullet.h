#pragma once
#include "Object.h"
class Player_Bullet :
    public Object
{
public:
    static int Speed;

    bool isHit;
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};


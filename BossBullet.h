#pragma once
#include "Object.h"
class BossBullet :
    public Object
{
public:
    BossBullet(Vector2 dir);
    static int Speed;
    Vector2 dir;
    int num;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};


#pragma once
#include "Object.h"
class S_Enemy_Bullet :
    public Object
{
public:
    S_Enemy_Bullet(Vector2 dir);
    Vector2 dir;
    static int Speed;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};


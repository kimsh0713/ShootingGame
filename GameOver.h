#pragma once
#include "Scene.h"
class GameOver :
    public Scene
{
    texture* img;
    texture* img2;
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};


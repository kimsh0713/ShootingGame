#pragma once
#include "Scene.h"
#include "ScrollMap.h"
class Stage :
    public Scene
{
public:
    static bool isSpawn;
    static bool isBoss;

    ScrollMap* Map;
    Timer* Enemy_Spawn;

    int Enemy_Count;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};


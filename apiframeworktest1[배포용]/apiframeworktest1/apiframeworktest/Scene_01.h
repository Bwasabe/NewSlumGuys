#pragma once
#include "Scene.h"
class Scene_01 :
    public Scene
{
private:
public:
    Scene_01();
    virtual ~Scene_01();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    virtual void Render(HDC _dc)override;
};


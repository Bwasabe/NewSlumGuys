#pragma once
#include "Scene.h"
class EndingScene :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    EndingScene();
    virtual ~EndingScene();
};


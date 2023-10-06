#pragma once
#include "Scene.h"
class TipScene :
    public Scene
{
public:
    TipScene();
    virtual ~TipScene();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};


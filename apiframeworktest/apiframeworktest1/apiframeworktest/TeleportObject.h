#pragma once
#include "BaseCircle.h"

class TeleportObject :
    public BaseCircle
{
public:
    TeleportObject();
    virtual ~TeleportObject();

public:
    virtual void Init() override;
    virtual void Render(HDC _dc)override { Component_Render(_dc); }
    void        SetMoveValue(float value) { m_fMoveValue = value; }
    //void        SetMovePos(Vec2 movePos) { m_vMovePos = movePos; }
private:
    CLONE(TeleportObject);

public:
    virtual void	EnterCollision(Collider* _pOther)override;

private:
    float        m_fMoveValue;

};


#pragma once
#include "BaseCircle.h"

class BaseMoveCircle :
    public BaseCircle
{
public:
    BaseMoveCircle();
    virtual ~BaseMoveCircle();

private:
    CLONE(BaseMoveCircle);

public:
    void    SetIsGoRight(bool isRight) { m_bIsGoRight = isRight; }
    bool    GetIsGoRight() { return m_bIsGoRight; }

    void    SetTimer(float timer) { m_fTimer = timer; }
    float    GetTimer() { return m_fTimer; }
   // void    SetInOrOutCircle(bool isIn);

    void    SetSpeed(float speed) { m_fSpeed = speed; }
    float   GetSpeed() { return m_fSpeed; }

    void    MoveObject();

private:
    float   m_fSpeed;
    float   m_fTimer;

    bool    m_bIsGoRight;

};


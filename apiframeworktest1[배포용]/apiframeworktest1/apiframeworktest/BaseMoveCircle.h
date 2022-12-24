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

   // void    SetInOrOutCircle(bool isIn);

    void    MoveObject();

private:
    float   m_fSpeed;
    float   m_fTimer;

    bool    m_bIsGoRight;

};


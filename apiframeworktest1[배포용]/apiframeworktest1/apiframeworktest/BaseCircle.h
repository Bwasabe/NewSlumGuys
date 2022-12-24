#pragma once
#include "Object.h"

class BaseCircle : public Object
{
public:
    BaseCircle();
    virtual ~BaseCircle();

private:
    CLONE(BaseCircle);

public:
    virtual void Update() override{}

public:
    void        InitCollider(Vec2 offset);


public:
    void        SetStartPos(Vec2 value) { m_vStartPos = value; }

    //void        SetMyRadius(float radius) { m_fMyRadius = radius; }
    //float       GetMyRadius() { return m_fMyRadius; }

    int         GetAlpha() { return m_iAlpha; }
    void        SetAlpha(int alpha) { m_iAlpha = alpha; }

    void        SetCurrentRadius(float radius) { m_fCurrentCircleRadius = radius; }

    void        SetPosToCirclePos(float moveValue);

    COLORREF    GetColor() { return m_Color; }
    void        SetColor(COLORREF color) { m_Color = color; }

    void        SetInOrOutCircle(bool isIn);



protected:
    //float   m_fMyRadius;
private:
    float   m_fCurrentCircleRadius;

    int     m_iAlpha;

protected:
    bool    m_bIsIn;

private:
    COLORREF    m_Color;

private:
    Vec2    m_vStartPos;
};


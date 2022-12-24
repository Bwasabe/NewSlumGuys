#pragma once
#include "Object.h"
class Image;

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
    void        InitCollider(Vec2 offset = Vec2(0,0));


public:
    void        SetStartPos(Vec2 value) { m_vStartPos = value; }
    Vec2        GetStartPos() { return m_vStartPos; }
    //void        SetMyRadius(float radius) { m_fMyRadius = radius; }
    //float       GetMyRadius() { return m_fMyRadius; }

    int         GetAlpha() { return m_iAlpha; }
    void        SetAlpha(int alpha) { m_iAlpha = alpha; }

    void        SetCurrentRadius(float radius) { m_fCurrentCircleRadius = radius; }
    float       GetCurrentRadius() { return m_fCurrentCircleRadius; }

    void        SetPosToCirclePos(float moveValue);

    COLORREF    GetColor() { return m_Color; }
    void        SetColor(COLORREF color) { m_Color = color; }

    void        SetInOrOutCircle(bool isIn);

    void        SetImage(Image* image) { m_iImage = image; }
    Image*      GetImage() { return m_iImage; }

protected:
    //float   m_fMyRadius;
private:
    float   m_fCurrentCircleRadius;

    int     m_iAlpha;

protected:
    bool    m_bIsIn;

private:
    COLORREF    m_Color;

protected:
    Vec2    m_vStartPos;

private:
    Image* m_iImage;

};


#pragma once
#include "Object.h"
class Image;
class Circle :
    public Object
{
public:
    Circle();
    virtual ~Circle();
private:
    CLONE(Circle);

public:
    void Init() override;
    void Update()       override;
    void Render(HDC _dc) override;

    void    SetStartPos(Vec2 value) { m_vStartPos = value; }

private:
    float   m_fRadius;
    float   m_fTimer;
    float   m_fSpeed;

    bool    m_bIsIn;

    Image* m_pImage;


private:
    Vec2    m_vStartPos;
};
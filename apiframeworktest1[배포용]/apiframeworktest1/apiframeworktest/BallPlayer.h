#pragma once
#pragma once
#include "Object.h"

class Image;
class BallPlayer :
    public Object
{
private:
    Image* m_pImage;
public:
    BallPlayer();
    BallPlayer(KEY upKey, KEY downKey);
    virtual ~BallPlayer();

private:
    CLONE(BallPlayer);

public:
    void Init() override;
    void Update()       override;
    void Render(HDC _dc) override;

    void    SetStartPos(Vec2 value) { m_vStartPos = value; }
    void    SetMyRadius(float radius) { m_fMyRadius = radius; }
    float   GetMyRadius() { return m_fMyRadius; }
    void    SetIsGoRight(bool isRight) { m_bIsGoRight = isRight; }
    void    SetInnerCircleRadius(float circleRadius) { m_fInnerCircleRadius = circleRadius;}
    void    SetOuterCircleRadius(float circleRadius) { m_fOuterCircleRadius = circleRadius;}
    void    SetCurrentRadius(float radius) { m_fCurrentCircleRadius = radius; }

private:
    float   m_fMyRadius;
    float   m_fTimer;
    float   m_fSpeed;
    float   m_fInnerCircleRadius;
    float   m_fOuterCircleRadius;
    float   m_fCurrentCircleRadius;

    int     m_iAlpha;

    bool    m_bIsIn;
    bool    m_bIsGoRight;

    KEY     m_kUpKey;
    KEY     m_kDownKey;
private:
    Vec2    m_vStartPos;
};

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
    virtual ~BallPlayer();
private:
    CLONE(BallPlayer);

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

private:
    Vec2    m_vStartPos;
};

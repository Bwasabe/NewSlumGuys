#pragma once
#include "Object.h"
class Image;

class Explain :
    public Object
{
private:
    Image* m_btnImage;
    RECT m_rect;
public:
    // Object을(를) 통해 상속됨
    void Render(HDC _dc) override;
    virtual void Update() override;
    CLONE(Explain);
public:
    Explain(Vec2 pos);
    ~Explain();
public:
    void OnClick();
    void ClickCheck();
};


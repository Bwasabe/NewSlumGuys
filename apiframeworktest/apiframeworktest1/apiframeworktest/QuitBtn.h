#pragma once
#include "Object.h"
class Image;

class QuitBtn :
    public Object
{
private:
    Image* m_btnImage;
    RECT m_rect;
public:
    // Object을(를) 통해 상속됨
    void Render(HDC _dc) override;
    virtual void Update() override;
    CLONE(QuitBtn);
public:
    QuitBtn(Vec2 pos);
    ~QuitBtn();
public:
    void OnClick();
    void ClickCheck();

};


#pragma once
#include "Object.h"
class Image;
class EscBtn :
    public Object
{
private:
    Image* m_btnImage;
    RECT m_rect;
public:
    // Object��(��) ���� ��ӵ�
    void Render(HDC _dc) override;
    virtual void Update() override;
    CLONE(EscBtn);
public:
    EscBtn(Vec2 pos);
    ~EscBtn();
public:
    void OnClick();
    void ClickCheck();
};


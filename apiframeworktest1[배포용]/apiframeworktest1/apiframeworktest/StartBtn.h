#pragma once
#include "Object.h"
class Image;
class StartBtn :
    public Object
{
    private:
        Image* m_btnImage;
        RECT m_rect;
    public:
        // Object을(를) 통해 상속됨
        void Render(HDC _dc) override;
        virtual void Update() override;
        CLONE(StartBtn);
    public:
        StartBtn(Vec2 pos);
        ~StartBtn();
public:
        void OnClick();
         void ClickCheck();
};


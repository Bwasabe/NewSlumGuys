#pragma once
#include "Object.h"
class Image;
class EndBtn :
    public Object
{
    private:
        Image* m_btnImage;
        RECT m_rect;
    public:
        // Object을(를) 통해 상속됨
        void Render(HDC _dc) override;
        virtual void Update() override;
        CLONE(EndBtn);
    public:
        EndBtn(Vec2 pos);
        ~EndBtn();
    public:
        void OnClick();
        void ClickCheck();

 };


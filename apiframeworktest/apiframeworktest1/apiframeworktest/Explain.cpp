#include "pch.h"
#include "Explain.h"
#include "TimeMgr.h"
#include "Image.h"
#include "Scene.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Core.h"


Explain::Explain(Vec2 pos)
{
    m_btnImage = ResMgr::GetInst()->ImgLoad(L"Gasi", L"Image\bag_1_Button_1.bmp");
    SetPos(pos);


    m_rect.left = pos.x - m_btnImage->GetWidth() / 2;
    m_rect.right = pos.x + m_btnImage->GetWidth() / 2;
    m_rect.top = pos.y - m_btnImage->GetHeight() / 2;
    m_rect.bottom = pos.y + m_btnImage->GetHeight() / 2;
}

Explain::~Explain()
{
}

void Explain::OnClick()
{
    ChangeScene(SCENE_TYPE::TIP);
}

void Explain::ClickCheck()
{
    POINT mousePos;
    GetCursorPos(&mousePos);
    ScreenToClient(Core::GetInst()->GetWndHandle(), &mousePos);

    if (PtInRect(&m_rect, mousePos))
    {
        if (KEY_AWAY(KEY::LBTN))
        {
            OnClick();
        }
    }
    else
    {
        return;
    }
}

void Explain::Render(HDC _dc)
{
    int Width = (int)m_btnImage->GetWidth();
    int Height = (int)m_btnImage->GetHeight();
    Vec2 vPos = GetPos();
    BitBlt(_dc
        , (int)(vPos.x - (float)(Width / 2))
        , (int)(vPos.y - (float)(Height / 2))
        , Width, Height
        , m_btnImage->GetDC()
        , 0, 0, SRCCOPY);

    Component_Render(_dc);

    SetTextAlign(_dc, TA_CENTER);
    SetBkMode(_dc, TRANSPARENT);
    TextOut(_dc, GetPos().x, GetPos().y - 20, L"Help", lstrlen(L"Help"));


    SetTextAlign(_dc, OPAQUE);
    SetBkMode(_dc, TA_LEFT);
}

void Explain::Update()
{
    ClickCheck();
}
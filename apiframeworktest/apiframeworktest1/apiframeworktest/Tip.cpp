#include "pch.h"
#include "Tip.h"
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


Tip::Tip(Vec2 pos)
{
    m_btnImage = ResMgr::GetInst()->ImgLoad(L"TipImage", L"Image\\tip.bmp");
    SetPos(pos);


    m_rect.left = pos.x - m_btnImage->GetWidth() / 2;
    m_rect.right = pos.x + m_btnImage->GetWidth() / 2;
    m_rect.top = pos.y - m_btnImage->GetHeight() / 2;
    m_rect.bottom = pos.y + m_btnImage->GetHeight() / 2;
}

Tip::~Tip()
{
}
void Tip::Render(HDC _dc)
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
    //TextOut(_dc, GetPos().x, GetPos().y - 20, L"플레이어 1 조작법 : W, S 플레이어 2 조작법  방향키 업 다운 적의 패턴을 피해서 오래 버티세요", lstrlen(L"플레이어 1 조작법 : W, S 플레이어 2 조작법 : 방향키 업 다운 적의 패턴을 피해서 오래 버티세요 "));


    SetTextAlign(_dc, OPAQUE);
    SetBkMode(_dc, TA_LEFT);
}

void Tip::Update()
{
}
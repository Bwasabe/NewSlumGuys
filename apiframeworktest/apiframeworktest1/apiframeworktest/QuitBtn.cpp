#include "pch.h"
#include "QuitBtn.h"
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

QuitBtn::QuitBtn(Vec2 pos)
{
	m_btnImage = ResMgr::GetInst()->ImgLoad(L"Gasi", L"Image\\bag_1_Button_1.bmp");
	SetPos(pos);


	m_rect.left = pos.x - m_btnImage->GetWidth() / 2;
	m_rect.right = pos.x + m_btnImage->GetWidth() / 2;
	m_rect.top = pos.y - m_btnImage->GetHeight() / 2;
	m_rect.bottom = pos.y + m_btnImage->GetHeight() / 2;
}

QuitBtn::~QuitBtn()
{
}

void QuitBtn::OnClick()
{
	DestroyWindow(Core::GetInst()->GetWndHandle());
}

void QuitBtn::ClickCheck()
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

void QuitBtn::Render(HDC _dc)
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
	TextOut(_dc, GetPos().x, GetPos().y - 20, L"Quit", lstrlen(L"Quit"));


	SetTextAlign(_dc, OPAQUE);
	SetBkMode(_dc, TA_LEFT);
}

void QuitBtn::Update()
{
	ClickCheck();
}
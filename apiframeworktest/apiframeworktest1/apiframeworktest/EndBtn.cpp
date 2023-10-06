#include "pch.h"
#include "EndBtn.h"
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

EndBtn::EndBtn(Vec2 pos)
{
	m_btnImage = ResMgr::GetInst()->ImgLoad(L"EndImage", L"Image\\end.bmp");

	m_rect.left = pos.x - m_btnImage->GetWidth() / 2;
	m_rect.right = pos.x + m_btnImage->GetWidth() / 2;
	m_rect.top = pos.y - m_btnImage->GetHeight() / 2;
	m_rect.bottom = pos.y + m_btnImage->GetHeight() / 2;

	SetPos(pos);
}

EndBtn::~EndBtn()
{
}



void EndBtn::OnClick()
{
	DestroyWindow(Core::GetInst()->GetWndHandle());
}

void EndBtn::ClickCheck()
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

void EndBtn::Render(HDC _dc)
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
}

void EndBtn::Update()
{
	ClickCheck();
}
#include "pch.h"
#include "StartBtn.h"
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
#include "SelectGDI.h"
StartBtn::StartBtn(Vec2 pos)
{
	m_btnImage = ResMgr::GetInst()->ImgLoad(L"Gasi", L"Image\\bag_1_Button_1.bmp");
	SetPos(pos);

	   
	m_rect.left = pos.x - m_btnImage->GetWidth() / 2;
	m_rect.right = pos.x + m_btnImage->GetWidth() / 2;
	m_rect.top = pos.y - m_btnImage->GetHeight() / 2;
	m_rect.bottom = pos.y + m_btnImage->GetHeight() / 2;
}

StartBtn::~StartBtn()
{
}

void StartBtn::OnClick()
{
	ChangeScene(SCENE_TYPE::SCENE_01);
}

void StartBtn::ClickCheck()
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

void StartBtn::Render(HDC _dc)
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

	//hdc = BeginPaint(hWnd, &ps);
	//font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "�ü�");
	//oldfont = (HFONT)SelectObject(hdc, font);
	//TextOut(hdc, 100, 100, str, strlen(str));
	//SelectObject(hdc, oldfont);
	//DeleteObject(font);
	//EndPaint(hWnd, &ps);

	HFONT font, oldfont;;

	font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("�ü�"));
	//font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"�ü�");

	oldfont = (HFONT)SelectObject(_dc, font);
	

	SelectObject(_dc, oldfont);

	/*SelectGDI s(_dc, CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
		VARIABLE_PITCH | FF_ROMAN, TEXT("���� �߳�ü")));*/
	//SelectGDI s1(_dc, RGB(255, 255, 255), CHANGE_TYPE::FONT_COLOR);*/

	TextOut(_dc, GetPos().x, GetPos().y - 20, L"Play", lstrlen(L"Play"));


	SetTextAlign(_dc, OPAQUE);
	SetBkMode(_dc, TA_LEFT);
}

void StartBtn::Update()
{
	ClickCheck();
}


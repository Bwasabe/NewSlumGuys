#include "pch.h"
#include "Gasi.h"
#include "TimeMgr.h"
#include "Image.h"
#include "Scene.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"
#include "ResMgr.h"

Gasi::Gasi()
{
	m_gasiImage = ResMgr::GetInst()->ImgLoad(L"Gasi", L"Image\\gasi.bmp");

}

Gasi::~Gasi()
{
}


void Gasi::Render(HDC _dc)
{
	int Width = (int)m_gasiImage->GetWidth();
	int Height = (int)m_gasiImage->GetHeight();
	Vec2 vPos = GetPos();
	BitBlt(_dc	
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_gasiImage->GetDC()
		, 0, 0, SRCCOPY);

	Component_Render(_dc);
}

void Gasi::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
}


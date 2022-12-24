#include "pch.h"
#include "FaceObj.h"
#include "Core.h"
#include "SceneMgr.h"
#include "func.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SelectGDI.h"
#include "TimeMgr.h"
#include "SoundMgr.h"
#include "Image.h"
FaceObj::FaceObj(Vec2 pos, FaceState state) : m_faceState(state)
{
	SetPos(pos);

	switch (m_faceState)
	{
	case FaceState::Smile:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"SMILE", L"Image\\smile.bmp");
		break;
	case FaceState::Angry:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"ANGRY", L"Image\\angry.bmp");
		break;
	case FaceState::Die:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"DIE", L"Image\\die.bmp");
		break;
	}
}

FaceObj::~FaceObj()
{
	
}
void FaceObj::ChcekFace()
{
	switch (m_faceState)
	{
	case FaceState::Smile:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"SMILE", L"Image\\smile.bmp");
		break;
	case FaceState::Angry:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"ANGRY", L"Image\\angry.bmp");
		break;
	case FaceState::Die:
		m_faceImage = ResMgr::GetInst()->ImgLoad(L"DIE", L"Image\\die.bmp");
	}
}

void FaceObj::Render(HDC _dc)
{
	int Width = (int)m_faceImage->GetWidth();
	int Height = (int)m_faceImage->GetHeight();
	Vec2 vPos = GetPos();

	//BitBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//	, Width, Height
	//	, m_faceImage->GetDC()
	//	, 0, 0, SRCCOPY);

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_faceImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));

	Component_Render(_dc);
}

void FaceObj::Update()
{
	if (KEY_TAP(KEY::B))
	{
		m_faceState = FaceState::Angry;
	}
	ChcekFace();
}


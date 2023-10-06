#include "pch.h"
#include "ThornMonster.h"
#include "TimeMgr.h"
#include "Image.h"
#include "Scene.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"
#include "ResMgr.h"

ThornMonster::ThornMonster() : m_iHp(5), m_iThornTime(6), m_iThornCnt(5)
{
	m_iTImage = ResMgr::GetInst()->ImgLoad(L"ThornEnemy", L"Image\\go.bmp");

	// animator 생성 및 animation 사용
	/*CreateAnimator();
	GetAnimator()->CreateAnimation(L"ThornEnemy", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"ThornEnemy", true);*/

	// animation offset 위로 올리기. 
	/*Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);*/
}

ThornMonster::~ThornMonster()
{
}
void ThornMonster::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
}


void ThornMonster::Render(HDC _dc)
{
	int Width = (int)m_iTImage->GetWidth();
	int Height = (int)m_iTImage->GetHeight();
	Vec2 vPos = GetPos();
	BitBlt(_dc
	,(int)(vPos.x - (float)(Width / 2))
	,(int)(vPos.y - (float)(Height / 2))
    , Width, Height
    , m_iTImage->GetDC()
    , 0,0, SRCCOPY);

	Component_Render(_dc);
}

void ThornMonster::CreateThorn()
{
	//원의 정보를 알고 360개로 쪼개고 거기서 랜덤으로 돌려
}


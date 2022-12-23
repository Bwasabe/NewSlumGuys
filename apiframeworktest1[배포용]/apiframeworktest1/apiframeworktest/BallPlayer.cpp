#include "pch.h"
#include "BallPlayer.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"

BallPlayer::BallPlayer()
	: m_fTimer(0)
	, m_fMyRadius(30)
	, m_fSpeed(3)
	, m_bIsIn(true)
	, m_bIsGoRight(true)
	, m_fInnerCircleRadius(300)
	, m_fOuterCircleRadius(300)
	, m_fCurrentCircleRadius(0)
	, m_kUpKey(KEY::A)
	, m_kDownKey(KEY::A)
{
	// collider 새성
	CreateCollider(COLLIDER_TYPE::CIRCLE);
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	//Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
	m_pImage = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", m_pImage, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset 위로 올리기. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);

}

BallPlayer::BallPlayer(KEY upKey, KEY downKey)
	: m_fTimer(0)
	, m_fMyRadius(30)
	, m_fSpeed(3)
	, m_bIsIn(true)
	, m_bIsGoRight(true)
	, m_fInnerCircleRadius(300)
	, m_fOuterCircleRadius(300)
	, m_fCurrentCircleRadius(0)
	, m_kUpKey(upKey)
	, m_kDownKey(downKey)
	, m_iAlpha(255)
{
	// collider 새성
	CreateCollider(COLLIDER_TYPE::CIRCLE);
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	//Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
	m_pImage = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", m_pImage, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset 위로 올리기. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}

BallPlayer::~BallPlayer()
{
	//if(nullptr !=m_pImage)
//	delete m_pImage;
}

void BallPlayer::Init()
{
	//m_vStartPos = GetPos();
}

void BallPlayer::Update()
{
	if(m_bIsGoRight)
		m_fTimer += fDT;
	else
		m_fTimer -= fDT;

	Vec2 vPos = GetPos();

	vPos.x = m_vStartPos.x + cos(m_fTimer * m_fSpeed) * m_fCurrentCircleRadius;
	vPos.y = m_vStartPos.y + sin(m_fTimer * m_fSpeed) * m_fCurrentCircleRadius;

	if (KEY_TAP(m_kUpKey))
	{
		m_bIsIn = false;
		m_fCurrentCircleRadius = m_fOuterCircleRadius + m_fMyRadius * 0.5f;
	}
	if (KEY_TAP(m_kDownKey))
	{
		m_bIsIn = true;
		m_fCurrentCircleRadius = m_fInnerCircleRadius - m_fMyRadius * 0.5f;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		m_bIsGoRight = !m_bIsGoRight;
	}
	SetPos(vPos);
	GetAnimator()->Update();
}

void BallPlayer::Render(HDC _dc)
{
	BLENDFUNCTION bf;
	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = m_iAlpha;

	/*Vec2 vPos = GetPos();
	Ellipse(_dc
		, (int)(vPos.x - (float)(m_fMyRadius / 2))
		, (int)(vPos.y - (float)(m_fMyRadius / 2))
		, (int)(vPos.x + (float)(m_fMyRadius / 2))
		, (int)(vPos.y + (float)(m_fMyRadius / 2))
	);*/

	HDC hMemDC = CreateCompatibleDC(_dc);
	Vec2 resolution = Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	HBITMAP hBitMap = CreateCompatibleBitmap(_dc, resolution.x, resolution.y);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitMap);

	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC, blackBrush);

	Vec2 vPos = GetPos();

	PatBlt(hMemDC, 0, 0, resolution.x, resolution.y, WHITENESS);
	Ellipse(hMemDC
		, (int)(vPos.x - (float)(m_fMyRadius / 2))
		, (int)(vPos.y - (float)(m_fMyRadius / 2))
		, (int)(vPos.x + (float)(m_fMyRadius / 2))
		, (int)(vPos.y + (float)(m_fMyRadius / 2))
	);
	//BitBlt(_dc, 0, 0, resolution.x, resolution.y, hMemDC, 0, 0, SRCCOPY);

	AlphaBlend(_dc
		, (int)(vPos.x - (float)(m_fMyRadius / 2))
		, (int)(vPos.y - (float)(m_fMyRadius / 2))
		, m_fMyRadius
		, m_fMyRadius
		, hMemDC
		, (int)(vPos.x - (float)(m_fMyRadius / 2))
		, (int)(vPos.y - (float)(m_fMyRadius / 2))
		, m_fMyRadius
		, m_fMyRadius
		, bf);

	SelectObject(hMemDC, oldBrush);
	SelectObject(hMemDC, hOldBitmap); // 기존 비트맵 선택

	DeleteObject(blackBrush);
	DeleteObject(hBitMap);
	DeleteDC(hMemDC);


}

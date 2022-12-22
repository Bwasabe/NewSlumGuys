#include "pch.h"
#include "Bullet.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Circle.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Circle::Circle()
    : m_fTimer(0)
    , m_fRadius(300)
    , m_fSpeed(3)
    , m_bIsIn(true)
{
    // collider 새성
    CreateCollider();
    GetCollider()->SetScale(Vec2(20.f, 30.f));

    // image 업로드
    m_pImage = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\go.bmp");

    // animator 생성 및 animation 사용
    //CreateAnimator();
    //GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
    //GetAnimator()->Play(L"Jiwoofront", true);

    // animation offset 위로 올리기. 
    //Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
    //for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
        //pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);

}

Circle::~Circle()
{
    //if(nullptr !=m_pImage)
//    delete m_pImage;
}

void Circle::Init()
{
    m_vStartPos = GetPos();
}

void Circle::Update()
{
    m_fTimer += fDT;
    Vec2 vPos = GetPos();
    vPos.x = m_vStartPos.x + cos(m_fTimer * m_fSpeed) * m_fRadius;
    vPos.y = m_vStartPos.y + sin(m_fTimer * m_fSpeed) * m_fRadius;

    if (KEY_TAP(KEY::SPACE))
    {
        m_bIsIn = !m_bIsIn;
        m_fRadius = m_bIsIn ? 300 : 250;
    }
    SetPos(vPos);
    //GetAnimator()->Update();
}

void Circle::Render(HDC _dc)
{
    int Width = (int)m_pImage->GetWidth();
    int Height = (int)m_pImage->GetHeight();
    Vec2 vPos = GetPos();
    BitBlt(_dc
        , (int)(vPos.x - (float)(Width / 2))
        , (int)(vPos.y - (float)(Height / 2))
        , Width, Height
        , m_pImage->GetDC()
        , 0, 0, SRCCOPY);

    Component_Render(_dc);
}
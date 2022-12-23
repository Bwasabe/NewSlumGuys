#include "pch.h"
#include "PlayerManager.h"
#include "Core.h"
#include "CircleMgr.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::PlayerManager(CircleMgr* mgr)
{
	m_pCircleMgr = mgr;
}


PlayerManager::~PlayerManager()
{
}

void PlayerManager::Init()
{
	BallPlayer* pObj = new BallPlayer(KEY::UP, KEY::DOWN);
	int halfResolutionY = Core::GetInst()->GetResolution().y / 2;

	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));

	BallPlayer* pObj2 = new BallPlayer(KEY::W, KEY::S);

	pObj2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj2->SetScale(Vec2(100.f, 100.f));

	pObj->SetStartPos(m_pCircleMgr->GetCirclePos());
	pObj2->SetStartPos(m_pCircleMgr->GetCirclePos());

	pObj->SetInnerCircleRadius(m_pCircleMgr->GetInnerRadius());
	pObj2->SetInnerCircleRadius(m_pCircleMgr->GetInnerRadius());

	pObj->SetOuterCircleRadius(m_pCircleMgr->GetInnerRadius() + m_pCircleMgr->GetThickness());
	pObj2->SetOuterCircleRadius(m_pCircleMgr->GetInnerRadius() + m_pCircleMgr->GetThickness());

	pObj->SetCurrentRadius(m_pCircleMgr->GetInnerRadius() + m_pCircleMgr->GetThickness() + pObj->GetMyRadius() * 0.5f);
	pObj2->SetCurrentRadius(m_pCircleMgr->GetInnerRadius() + m_pCircleMgr->GetThickness() + pObj2->GetMyRadius() * 0.5f);

	pObj->SetIsGoRight(true);
	pObj2->SetIsGoRight(false);

	SetPlayer1(pObj);
	SetPlayer2(pObj2);
}

void PlayerManager::Update()
{
	m_pPlayer1->Update();
	m_pPlayer2->Update();

}

void PlayerManager::Render(HDC _dc)
{
	m_pPlayer1->Render(_dc);
	m_pPlayer2->Render(_dc);
}

#include "pch.h"
#include "PlayerManager.h"
#include "Core.h"
#include "CircleMgr.h"

PlayerManager::PlayerManager()
{
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

	pObj->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
	pObj2->SetStartPos(CircleMgr::GetInst()->GetCirclePos());

	pObj->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius());
	pObj2->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius());

	pObj->SetMyRadius(30);
	pObj2->SetMyRadius(30);

	pObj->SetColor(RGB(0, 0, 0));
	pObj2->SetColor(RGB(0,0,0));

	pObj->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness() + pObj->GetMyRadius() * 0.5f);
	pObj2->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness() + pObj2->GetMyRadius() * 0.5f);

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


#include "pch.h"
#include "PlayerManager.h"
#include "Core.h"
#include "CircleMgr.h"
#include "SceneMgr.h"
#include "Scene.h"

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
	pObj->SetScale(Vec2(15.f, 15.f));

	//BallPlayer* pObj2 = new BallPlayer(KEY::W, KEY::S);

	//pObj2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	//pObj2->SetScale(Vec2(15.f, 15.f));

	pObj->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
	//pObj2->SetStartPos(CircleMgr::GetInst()->GetCirclePos());

	pObj->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius());
	//pObj2->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius());

	pObj->SetColor(RGB(0, 0, 0));
	//pObj2->SetColor(RGB(0,0,0));

	pObj->SetAlpha(255);
	//pObj2->SetAlpha(255);

	pObj->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness() + pObj->GetScale().x);
	//pObj2->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness() + pObj2->GetScale().x);

	pObj->SetIsGoRight(true);
	//pObj2->SetIsGoRight(false);

	pObj->InitCollider(Vec2(0,0));

	pObj->SetSpeed(2);
	//pObj2->InitCollider(Vec2(0, 0));

	SetPlayer1(pObj);
	//SetPlayer2(pObj2);

	SceneMgr::GetInst()->GetCurScene()->AddObject(pObj, GROUP_TYPE::PLAYER);
	//SceneMgr::GetInst()->GetCurScene()->AddObject(pObj2, GROUP_TYPE::PLAYER);
}
//
//void PlayerManager::Update()
//{
//	m_pPlayer1->Update();
//	m_pPlayer2->Update();
//}
//
//void PlayerManager::Render(HDC _dc)
//{
//	m_pPlayer1->Render(_dc);
//	m_pPlayer2->Render(_dc);
//}
//
//void PlayerManager::FinalUpdate()
//{
//	m_pPlayer1->FinalUpdate();
//	m_pPlayer2->FinalUpdate();
//}


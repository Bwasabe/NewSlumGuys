#include "pch.h"
#include "BaseEnemy.h"
#include "CircleMgr.h"
#include "BaseCircle.h"
#include "CircleRenderMgr.h"
#include "func.h"
#include "ResMgr.h"
#include "Image.h"
#include "CircleGasi.h"
#include "PlayerManager.h"
#include "SceneMgr.h"
#include "Scene.h"
BaseEnemy::BaseEnemy(PlayerManager* mgr) : m_pPlayerMgr(mgr)
{
	
}

BaseEnemy::~BaseEnemy()
{
}


void BaseEnemy::Init()
{
	CreateCollider(COLLIDER_TYPE::CIRCLE);

	GetCollider()->SetScale(Vec2(30.f, 30.f));

	Vec2 colliderOffset = CircleMgr::GetInst()->GetCirclePos();
	colliderOffset.y -= (CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness());

	GetCollider()->SetOffsetPos(colliderOffset);


}

void BaseEnemy::Update()
{
	if (!m_bIsCanChangePattern)return;
	if (m_bIsRemove)
	{
		for (int i = 0; i < m_vPatternObjs.size(); ++i)
		{
			if (m_vPatternObjs[i] != nullptr)
			{
				CircleRenderMgr::GetInst()->RemoveCircle(m_vPatternObjs[i]);
				DeleteObject(m_vPatternObjs[i]);
			}
		}
		m_vPatternObjs.clear();
	}
	m_bIsCanChangePattern = false;

#pragma region 변수
	float angleTable0[4] = { 90.f,120.f,150.f,180.f };
	bool isIn0[4] = { false, true, false ,true };

	float angleTable1[6] = { 30.f, 90.f, 120.f,  210.f, 240.f, 350.f };
	bool isIn1[6] = { false , true ,true , false , true, true};

	float angleTable2[5] = { 0.f, 90.f, 150.f, 170.f, 210.f };
	bool isIn2[5] = { false, true , true ,false , false  };

	float angleTable3[6] = { 10.f, 30.f, 100.f, 170.f, 210.f, 300.f };
	bool isIn3[6] = { true, false , false ,true , false , false };


	float angleTable4[5] = { 10.f, 50.f, 100.f, 150.f, 200.f};
	bool isIn4[5] = { true, false , false ,true , true };

	float angleTable5[2] = { 125.f, 250.f };
	bool isIn5[2] = { false, true };

	float angleTable6[2] = { 150.f, 300.f };
	bool isIn6[2] = { true, false };

	float angleTable7[9] = { 0.f, 40.f, 75.f, 110.f, 145.f, 190.f, 230.f, 290.f, 330.f };
	bool isIn7[9] = { false, true, false ,true, true, false, false, true, false };

	float angleTable8[3] = { 60.f, 140.f,  220.f };
	bool isIn8[3] = { true, false , true };

	
#pragma endregion

	

	switch (m_iPattern)
	{
	case 0:
		break;
	case 1:
		for (int i = 0; i < 4; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn0[i]);

			circle->SetPosToCirclePos(angleTable0[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);

			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);
			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = false;
		
		break;
	case 2:
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());
		m_bIsRemove = true;
		break;
	case 3:
	{
		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn1[i]);

			circle->SetPosToCirclePos(angleTable1[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
	}
	break;

	case 4:
		for (int i = 0; i < 5; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn2[i]);

			circle->SetPosToCirclePos(angleTable2[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 5:

		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn3[i]);

			circle->SetPosToCirclePos(angleTable3[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = false;
		break;
	case 6:

		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());
		m_bIsRemove = true;
		break;

	case 7:
		for (int i = 0; i < 5; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn4[i]);

			circle->SetPosToCirclePos(angleTable4[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 8:
		m_pPlayerMgr->GetPlayer1()->SetSpeed(3);
		for (int i = 0; i < 2; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn5[i]);

			circle->SetPosToCirclePos(angleTable5[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = false;
		break;
	case 9:
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());
		for (int i = 0; i < 2; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn6[i]);

			circle->SetPosToCirclePos(angleTable6[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 10:
		m_pPlayerMgr->GetPlayer1()->SetSpeed(2);
		break;
	case 11:
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());
		for (int i = 0; i < 9; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn7[i]);

			circle->SetPosToCirclePos(angleTable7[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		//방향전환
		break;

	case 12:
		m_pPlayerMgr->GetPlayer1()->SetSpeed(4);
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());
		for (int i = 0; i < 2; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn6[i]);

			circle->SetPosToCirclePos(angleTable6[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 13:
		m_pPlayerMgr->GetPlayer1()->SetSpeed(2);
		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn3[i]);

			circle->SetPosToCirclePos(angleTable3[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;

		break;

	case 14:
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());

		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(isIn1[i]);

			circle->SetPosToCirclePos(angleTable1[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 15:
		m_pPlayerMgr->GetPlayer1()->SetSpeed(1.5f);
		m_pPlayerMgr->GetPlayer1()->SetIsGoRight(!m_pPlayerMgr->GetPlayer1()->GetIsGoRight());

		for (int i = 0; i < 3; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			circle->SetInOrOutCircle(angleTable8[i]);

			circle->SetPosToCirclePos(angleTable8[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);

			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;

	/*case 16:
		break;*/
		// 씬 로딩
	}
}



void BaseEnemy::Render(HDC _dc)
{



	Component_Render(_dc);
}

void BaseEnemy::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	m_iPattern++;
	m_bIsCanChangePattern = true;
	//pOtherObj->SetDead();
	/*if (pOtherObj->GetName() == L"Player1")
	{
		m_hp--;
	}*/
}

void BaseEnemy::ExecutePattern()
{
	// Switch문으로 index에 따라 오브젝트 생성
}



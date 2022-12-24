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
				delete m_vPatternObjs[i];
			}
		}
		m_vPatternObjs.clear();
	}
	m_bIsCanChangePattern = false;

#pragma region 변수
	float angleTable0[4] = { 90.f,120.f,150.f,180.f };
	bool isIn0[4] = { false, true, false ,true };

	float angleTable1[12] = { 0.f,30.f, 60.f, 90.f, 120.f, 150.f, 180.f, 210.f, 240.f, 270.f, 300.f, 330.f };
	bool isIn1[12] = { false, false , true ,true , false , true, true, false, false, false, true, true };

	float angleTable2[6] = { 20.f, 80.f, 130.f, 170.f, 210.f, 300.f };
	bool isIn2[6] = { false, false , true ,true , false , false };

	float angleTable3[6] = { 10.f, 30.f, 100.f, 170.f, 210.f, 300.f };
	bool isIn3[6] = { true, false , false ,true , false , false };


	float angleTable4[10] = { 5.f, 25.f, 60.f ,100.f, 130.f, 170.f, 200.f, 220.f,  270.f, 330.f };
	bool isIn4[10] = { true, false , true ,false , true , false, false, true, false, true };

	float angleTable5[8] = { 0.f, 45.f, 90.f, 135.f, 180.f, 225.f, 270.f, 315.f };
	bool isIn5[8] = { false, false , true ,true, true , true, false, false };


	float angleTable6[6] = { 20.f, 100.f, 160.f, 200.f, 280.f, 310.f };
	bool isIn6[6] = { true, false , true, true, true, false };

	float angleTable7[4] = { 90.f,120.f,150.f,180.f };
	bool isIn7[4] = { false, true, false ,true };

	float angleTable8[3] = { 60.f, 140.f,  220.f };
	bool isIn8[3] = { true, false , true };

	float angleTable9[3] = { 60.f, 140.f,  220.f };
	bool isIn9[3] = { false, true , false };

	float angleTable10[5] = { 10.f, 70.f, 130.f, 190.f, 240.f };
	bool isIn10[5] = { false, true , false, false , true };

	float angleTable11[7] = { 25.f, 55.f, 70.f, 115.f, 170.f, 240.f, 300.f };
	bool isIn11[7] = { true, true, false, true , false, false , true };

	float angleTable12[7] = { 0.f, 30.f, 70.f, 120.f, 200.f, 240.f, 300.f };
	bool isIn12[7] = { false, false, false, true , true, false , true };

	float angleTable13[7] = { 60.f, 120.f, 180.f, 240.f, 300.f };
	bool isIn13[7] = { false, true, false, true , true };

	float angleTable14[12] = { 0.f,30.f, 60.f, 90.f, 120.f, 150.f, 180.f, 210.f, 240.f, 270.f, 300.f, 330.f };
	bool isIn14[12] = { false, false , true ,true , false , true, true, false, false, false, true, true };
#pragma endregion

	

	switch (m_iPattern)
	{
	case 0:
		for (int i = 0; i < 4; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			//circle->SetImage(ResMgr::GetInst()->ImgLoad(L"CircleGasi", L"Image\\circleGasi.bmp"));
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn0[i]);

			circle->SetPosToCirclePos(angleTable0[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);

			circle->InitCollider();
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
			SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::MONSTER);
			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = true;
		break;
	case 1:
		for (int i = 0; i < 12; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			//circle->SetImage(ResMgr::GetInst()->ImgLoad(L"CircleGasi", L"Image\\circleGasi.bmp"));
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn1[i]);

			circle->SetPosToCirclePos(angleTable1[i] * DEG2RAD);
			circle->SetColor(RGB(255, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();

			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
			m_vPatternObjs.push_back(circle);
		}
		m_bIsRemove = false;
		break;
	case 2:
		m_pPlayerMgr->GetPlayer1()->GetIsGoRight();

		//PlayerManager() pObj->SetIsGoRight(true);
		//pObj2->SetIsGoRight(false);
		//방향전환
		break;
	case 3:
	{
		//Object* tObj = new Circle;
		//tObj->SetPos(Vec2(Core::GetInst()->GetR5esolution().x / 2, Core::GetInst()->GetResolution().y / 2));
		//tObj->SetScale(Vec2(300.f, 300.f));
		//AddObject(tObj, GROUP_TYPE::MONSTER);
		m_bIsRemove = true;
	}
	//돌아가는 공
	break;
	case 4:
		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn2[i]);

			circle->SetPosToCirclePos(angleTable2[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			circle->InitCollider();

			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
			m_vPatternObjs.push_back(circle);

		}
		m_bIsRemove = false;

	case 5:
		//방향전환
		break;
	case 6:
		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new CircleGasi;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn3[i]);

			circle->SetPosToCirclePos(angleTable3[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
			m_vPatternObjs.push_back(circle);

		}
		m_bIsRemove = true;

		break;
	case 7:
		//순간이동
		break;
		m_bIsRemove = true;
	case 8:
		for (int i = 0; i < 10; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn4[i]);

			circle->SetPosToCirclePos(angleTable4[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}

	case 9:
		for (int i = 0; i < 8; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
		///	circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn5[i]);

			circle->SetPosToCirclePos(angleTable5[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 10:
		//돌아가는공
		break;
	case 11:
		//방향전환
		break;
	case 12:
		for (int i = 0; i < 6; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn6[i]);

			circle->SetPosToCirclePos(angleTable6[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;

	case 13:
		//돌아가는 공
		break;

	case 14:
		//순간이동
		break;

	case 15:
		for (int i = 0; i < 4; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn7[i]);

			circle->SetPosToCirclePos(angleTable7[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 16:
		//순간이ㅣ동
		break;
	case 17:
		//방향전환
		break;
	case 18:
		for (int i = 0; i < 3; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn8[i]);

			circle->SetPosToCirclePos(angleTable8[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);

		}
		break;
	case 19:
		for (int i = 0; i < 3; ++i)
		{

			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn9[i]);

			circle->SetPosToCirclePos(angleTable9[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 20:
		//돌아가는공
		break;

	case 21:
		//돌아가는공
		break;
	case 22:
		//방향전환
		break;
	case 23:
		for (int i = 0; i < 5; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn10[i]);

			circle->SetPosToCirclePos(angleTable10[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;

	case 24:
		//방향전환
		break;
	case 25:
		for (int i = 0; i < 7; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn11[i]);

			circle->SetPosToCirclePos(angleTable11[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 26:
		for (int i = 0; i < 7; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn12[i]);

			circle->SetPosToCirclePos(angleTable12[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 27:
		//순간이동
		break;
	case 28:
		for (int i = 0; i < 5; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn13[i]);

			circle->SetPosToCirclePos(angleTable13[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 29:
		//방향전환
		break;
	case 30:
		for (int i = 0; i < 12; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			//circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn14[i]);

			circle->SetPosToCirclePos(angleTable14[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	default:
		break;
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
	pOtherObj->SetDead();
	/*if (pOtherObj->GetName() == L"Player1")
	{
		m_hp--;
	}*/
}

void BaseEnemy::ExecutePattern()
{
	// Switch문으로 index에 따라 오브젝트 생성
}



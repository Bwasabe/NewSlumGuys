#include "pch.h"
#include "Scene_01.h"
#include "KeyMgr.h"
#include "BallPlayer.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Circle.h"
#include "CircleMgr.h"
#include "PlayerManager.h"
#include "CircleRenderMgr.h"
#include "BaseEnemy.h"
Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	// Object 추가

	//CircleMgr* circleMgr = new CircleMgr;

	/*circleMgr->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	circleMgr->SetScale(Vec2(100.f, 100.f));*/

	//AddObject(CircleMgr::GetInst(), GROUP_TYPE::PLAYER);
	AddObject(CircleMgr::GetInst(), GROUP_TYPE::PLAYER);

	PlayerManager* playerMgr = new PlayerManager;

	AddObject(playerMgr, GROUP_TYPE::PLAYER);


	AddObject(CircleRenderMgr::GetInst(), GROUP_TYPE::PLAYER);

	BaseEnemy* baseEnemy = new BaseEnemy;

	AddObject(baseEnemy, GROUP_TYPE::MONSTER);


	//// 충돌 지정 
	//// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

	Scene::Enter();

	CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer1());
	CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer2());
	//CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	//

	//원 적 패턴중 하나
	/*Object* cObj = new Circle;
	cObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	cObj->SetScale(Vec2(100.f, 100.f));
	AddObject(cObj, GROUP_TYPE::PLAYER);*/

	
	int index = 0;
	float angle;//18은 개수
	float angleTable[4] = { 90.f,30.f,50.f,60.f };
	bool isIn[100] = { false, true, false ,true };
	switch (index)
	{
	case 0:
		for (int i = 0; i < 4; ++i)
		{
			BaseCircle* circle = new BaseCircle;
			circle->SetStartPos(CircleMgr::GetInst()->GetCirclePos());
			circle->SetScale(Vec2(15.f, 15.f));
			//circle->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
			circle->SetMyRadius(15);

			//circle->SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - circle->GetMyRadius() * 0.5f);
			circle->SetInOrOutCircle(isIn[i]);

			circle->SetPosToCirclePos(angleTable[i] * DEG2RAD);
			circle->SetColor(RGB(0, 0, 0));
			circle->SetAlpha(255);
			//SceneMgr::GetInst()->GetCurScene()->AddObject(circle, GROUP_TYPE::PLAYER);
			//circle->CreateCollider(COLLIDER_TYPE::CIRCLE);
			CircleRenderMgr::GetInst()->AddCircle(circle);
		}
		break;
	case 1:
	
		break;
	case 2:
		//방향전환
		break;
	case 3:
	{
		//Object* tObj = new Circle;
		//tObj->SetPos(Vec2(Core::GetInst()->GetR5esolution().x / 2, Core::GetInst()->GetResolution().y / 2));
		//tObj->SetScale(Vec2(300.f, 300.f));
		//AddObject(tObj, GROUP_TYPE::MONSTER);
	}

	//돌아가는 공
	break;
	case 4:

	case 5:
		//방향전환
		break;
	case 6:


		break;
	case 7:
		//순간이동
		break;
	case 8:

	case 9:

		break;
	case 10:

		//돌아가는공
		break;
	case 11:
		//방향전환
		break;
	case 12:

		break;

	case 13:
		//돌아가는 공
		break;

	case 14:
		//순간이동
		break;

	case 15:
		break;
	case 16:
		//순간이ㅣ동
		break;
	case 17:
		//방향전환
		break;
	case 18:

		break;
	case 19:

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
		break;

	case 24:
		//방향전환
		break;
	case 25:

		break;
	case 26:

		break;
	case 27:
		//순간이동
		break;
	case 28:

		break;
	case 29:
		//방향전환
		break;
	case 30:

		break;
	default:
		break;
	}

}

void Scene_01::Exit()
{
	/*POINT apt[3];
	PlgBlt()*/
}

void Scene_01::Update()
{
	Scene::Update();
	/*if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}*/
}

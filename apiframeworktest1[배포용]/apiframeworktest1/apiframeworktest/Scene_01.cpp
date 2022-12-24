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

	AddObject(CircleMgr::GetInst(), GROUP_TYPE::PLAYER);

	PlayerManager* playerMgr = new PlayerManager;

	AddObject(playerMgr, GROUP_TYPE::PLAYER);

	CircleRenderMgr* circleRenderMgr = new CircleRenderMgr;

	AddObject(circleRenderMgr, GROUP_TYPE::PLAYER);

	BaseEnemy* baseEnemy = new BaseEnemy;

	AddObject(baseEnemy, GROUP_TYPE::MONSTER);


	//// 충돌 지정 
	//// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	//CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	//

	//원 적 패턴중 하나
	/*Object* cObj = new Circle;
	cObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	cObj->SetScale(Vec2(100.f, 100.f));
	AddObject(cObj, GROUP_TYPE::PLAYER);*/

	Scene::Enter();

	circleRenderMgr->AddCircle(playerMgr->GetPlayer1());
	circleRenderMgr->AddCircle(playerMgr->GetPlayer2());
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

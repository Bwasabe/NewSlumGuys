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
#include "TeleportObject.h"
#include "FaceObj.h"

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
	//AddObject(CircleMgr::GetInst(), GROUP_TYPE::PLAYER);
	CircleMgr::GetInst()->Init();

	PlayerManager* playerMgr = new PlayerManager;

	AddObject(playerMgr, GROUP_TYPE::PLAYER);

	Object* faceObj = new FaceObj(Vec2(float((Core::GetInst()->GetResolution().x / 2)), (Core::GetInst()->GetResolution().y / 2) * 1.f), FaceState::Smile);
	faceObj->SetScale(Vec2(300.f, 300.f));
	AddObject(faceObj, GROUP_TYPE::UI);

	//AddObject(CircleRenderMgr::GetInst(), GROUP_TYPE::PLAYER);

	//CircleRenderMgr::GetInst()->Init();

	BaseEnemy* baseEnemy = new BaseEnemy(playerMgr);

	AddObject(baseEnemy, GROUP_TYPE::MONSTER);


	/*Vec2 movePos;
	movePos.x = CircleMgr::GetInst()->GetCirclePos().x + cos(210 * DEG2RAD) * teleportObj->GetCurrentRadius();
	movePos.y = teleportObj->GetStartPos().y + sin(210 * DEG2RAD) * teleportObj->GetCurrentRadius();

	teleportObj->SetMovePos(movePos);*/


	Scene::Enter();


	//// 충돌 지정 
	//// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);


	CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer1());
	//CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer2());
}

void Scene_01::Exit()
{
	/*POINT apt[3];
	PlgBlt()*/
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
	CircleRenderMgr::GetInst()->RemoveAllCircle();
}

void Scene_01::Update()
{
	CircleMgr::GetInst()->Update();
	Scene::Update();
	/*if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}*/

}

void Scene_01::Render(HDC _dc)
{
	CircleMgr::GetInst()->Render(_dc);
	CircleRenderMgr::GetInst()->Render(_dc);
	Scene::Render(_dc);
}


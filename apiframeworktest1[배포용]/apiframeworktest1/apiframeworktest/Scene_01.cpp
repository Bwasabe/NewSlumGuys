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
	AddObject(CircleMgr::GetInst(), GROUP_TYPE::PLAYER);

	PlayerManager* playerMgr = new PlayerManager;

	AddObject(playerMgr, GROUP_TYPE::PLAYER);


	AddObject(CircleRenderMgr::GetInst(), GROUP_TYPE::PLAYER);

	BaseEnemy* baseEnemy = new BaseEnemy;

	AddObject(baseEnemy, GROUP_TYPE::MONSTER);


	Object* faceObj = new FaceObj(Vec2(float((Core::GetInst()->GetResolution().x / 2)), (Core::GetInst()->GetResolution().y / 2) * 1.f), FaceState::Smile);
	faceObj->SetScale(Vec2(300.f, 300.f));
	AddObject(faceObj, GROUP_TYPE::UI);

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

	int hp = 30;

	
	int index = 19;
	float angle;//18은 개수

	float angleTable0[4] = { 90.f,120.f,150.f,180.f };
	bool isIn0[4] = { false, true, false ,true };

	float angleTable1[12] = { 0.f,30.f, 60.f, 90.f, 120.f, 150.f, 180.f, 210.f, 240.f, 270.f, 300.f, 330.f };
	bool isIn1[12] = { false, false , true ,true , false , true, true, false, false, false, true, true };

	float angleTable2[6] = { 20.f, 80.f, 130.f, 170.f, 210.f, 300.f };
	bool isIn2[6] = { false, false , true ,true , false , false };

	float angleTable3[6] = { 10.f, 30.f, 100.f, 170.f, 210.f, 300.f };
	bool isIn3[6] = { true, false , false ,true , false , false };


	float angleTable4[10] = { 5.f, 25.f, 60.f ,100.f, 130.f, 170.f, 200.f, 220.f,  270.f, 330.f};
	bool isIn4[10] = { true, false , true ,false , true , false, false, true, false, true };

	float angleTable5[8] = { 0.f, 45.f, 90.f, 135.f, 180.f, 225.f, 270.f, 315.f };
	bool isIn5[8] = { false, false , true ,true, true , true, false, false};


	float angleTable6[6] = { 20.f, 100.f, 160.f, 200.f, 280.f, 310.f};
	bool isIn6[6] = { true, false , true, true, true, false };

	float angleTable7[4] = { 90.f,120.f,150.f,180.f };
	bool isIn7[4] = { false, true, false ,true };

	float angleTable8[3] = { 60.f, 140.f,  220.f };
	bool isIn8[3] = { true, false , true };

	float angleTable9[3] = { 60.f, 140.f,  220.f };
	bool isIn9[3] = { false, true , false };
	
	float angleTable10[5] = { 10.f, 70.f, 130.f, 190.f, 240.f};
	bool isIn10[5] = { false, true , false, false , true};

	float angleTable11[7] = { 25.f, 55.f, 70.f, 115.f, 170.f, 240.f, 300.f };
	bool isIn11[7] = { true, true, false, true , false, false , true };

	float angleTable12[7] = { 0.f, 30.f, 70.f, 120.f, 200.f, 240.f, 300.f };
	bool isIn12[7] = { false, false, false, true , true, false , true };

	float angleTable13[7] = { 60.f, 120.f, 180.f, 240.f, 300.f};
	bool isIn13[7] = { false, true, false, true , true};

	float angleTable14[12] = { 0.f,30.f, 60.f, 90.f, 120.f, 150.f, 180.f, 210.f, 240.f, 270.f, 300.f, 330.f };
	bool isIn14[12] = { false, false , true ,true , false , true, true, false, false, false, true, true };



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
	int 
	if (BaseEnemy::GettHP())
	{

	}
}

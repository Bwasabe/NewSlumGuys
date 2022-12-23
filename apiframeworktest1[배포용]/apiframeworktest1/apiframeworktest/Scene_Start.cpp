#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ThornMonster.h";
#include "Gasi.h";
#include "StartBtn.h"
#include "QuitBtn.h"
#include "Explain.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object 추가
	//Object* tObj = new ThornMonster;
	//tObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	//tObj->SetScale(Vec2(300.f, 300.f));
	//AddObject(tObj, GROUP_TYPE::MONSTER);


	Object* startBtnObj = new StartBtn(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 0.6f));
	startBtnObj->SetScale(Vec2(200.f, 200.f));
	AddObject(startBtnObj, GROUP_TYPE::UI);

	Object* tipBtnObj = new Explain(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 1.f));
	tipBtnObj->SetScale(Vec2(200.f, 200.f));
	AddObject(tipBtnObj, GROUP_TYPE::UI);


	Object* quitBtnObj = new QuitBtn(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 1.4f));
	quitBtnObj->SetScale(Vec2(200.f, 200.f));
	AddObject(quitBtnObj, GROUP_TYPE::UI);

	//	gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
	//		(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
	//	gObj->SetScale(Vec2(20.f, 20.f));
	//	AddObject(gObj, GROUP_TYPE::MONSTER);
	//}


	/*bool MyPtInRect(POINT pt, RECT rc)
	{
		if (rc.left <= pt.x && pt.x <= rc.right && rc.top <= pt.y && pt.y >= rc.bottom)
		{
		
			return true;
		}
		else
		{
			return false;
		}
	}
	*/
	
	//float angle = 360.f / 20.f; //18은 개수
	//for (int i = 0; i < 20; i++)
	//{
	//	//	//가시클래스를 갖고온다 가시클래스에 set 크리에이트 뭐가있을거야
	//	//	//하나 각도 구하는 식은
	// 	//	//가쉬 위치 밑에

	//	Object* gObj = new Gasi;
	//	gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
	//		(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
	//	gObj->SetScale(Vec2(20.f, 20.f));
	//	AddObject(gObj, GROUP_TYPE::MONSTER);
	//}

	/*Object* pObj = new Player;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);*/

//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

	// Monster Object 추가
	//Monster* pMonsterObj = new Monster;
	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

	// 몬스터 배치
	/*Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iMonster = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
	Monster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonster; i++)
	{
		pMonsterObj = new Monster;
		pMonsterObj->SetName(L"Monster");
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}*/


	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{  
	Scene::Update();
	/*if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}*/
}

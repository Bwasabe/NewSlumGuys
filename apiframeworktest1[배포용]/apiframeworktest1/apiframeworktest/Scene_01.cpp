#include "pch.h"
#include "Scene_01.h"
#include "KeyMgr.h"
#include "BallPlayer.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Circle.h"
Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	// Object �߰�
	//Object* pObj = new BallPlayer;
	//int halfResolutionY = Core::GetInst()->GetResolution().y / 2;
	//// TODO: ���߿� Y�� ��������ŭ �����ִ� ������ �ٲ��ֱ�

	//pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	//pObj->SetScale(Vec2(100.f, 100.f));
	//AddObject(pObj, GROUP_TYPE::PLAYER);
	//// �浹 ���� 
	//// Player - Monster �׷� ���� �浹 üũ
	//CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	//CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	//

	//�� �� ������ �ϳ�
	Object* cObj = new Circle;
	cObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	cObj->SetScale(Vec2(100.f, 100.f));
	AddObject(cObj, GROUP_TYPE::PLAYER);


	Scene::Enter();
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

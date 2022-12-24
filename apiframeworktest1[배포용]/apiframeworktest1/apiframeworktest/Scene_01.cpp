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
	// Object �߰�

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


	//// �浹 ���� 
	//// Player - Monster �׷� ���� �浹 üũ
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

	Scene::Enter();

	CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer1());
	CircleRenderMgr::GetInst()->AddCircle(playerMgr->GetPlayer2());
	//CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	//

	//�� �� ������ �ϳ�
	/*Object* cObj = new Circle;
	cObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	cObj->SetScale(Vec2(100.f, 100.f));
	AddObject(cObj, GROUP_TYPE::PLAYER);*/

	
	int index = 0;
	float angle;//18�� ����
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
		//������ȯ
		break;
	case 3:
	{
		//Object* tObj = new Circle;
		//tObj->SetPos(Vec2(Core::GetInst()->GetR5esolution().x / 2, Core::GetInst()->GetResolution().y / 2));
		//tObj->SetScale(Vec2(300.f, 300.f));
		//AddObject(tObj, GROUP_TYPE::MONSTER);
	}

	//���ư��� ��
	break;
	case 4:

	case 5:
		//������ȯ
		break;
	case 6:


		break;
	case 7:
		//�����̵�
		break;
	case 8:

	case 9:

		break;
	case 10:

		//���ư��°�
		break;
	case 11:
		//������ȯ
		break;
	case 12:

		break;

	case 13:
		//���ư��� ��
		break;

	case 14:
		//�����̵�
		break;

	case 15:
		break;
	case 16:
		//�����̤ӵ�
		break;
	case 17:
		//������ȯ
		break;
	case 18:

		break;
	case 19:

		break;
	case 20:
		//���ư��°�
		break;

	case 21:
		//���ư��°�
		break;
	case 22:
		//������ȯ
		break;
	case 23:
		break;

	case 24:
		//������ȯ
		break;
	case 25:

		break;
	case 26:

		break;
	case 27:
		//�����̵�
		break;
	case 28:

		break;
	case 29:
		//������ȯ
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

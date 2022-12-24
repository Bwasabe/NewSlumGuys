#include "pch.h"
#include "TipScene.h"
#include "KeyMgr.h"
#include "Core.h"
#include "EscBtn.h"
#include "Tip.h"
#include "FaceObj.h"
#include "MinusHP.h"
#include "CircleMgr.h"
#include "PlayerManager.h"
#include "CollisionMgr.h"
#include "Gasi.h"
#include "Circle.h"
TipScene::TipScene()
{
}

TipScene::~TipScene()
{
}

void TipScene::Enter()
{

	Object* escBtnObj = new EscBtn(Vec2((Core::GetInst()->GetResolution().x / 2) * 0.8f, (Core::GetInst()->GetResolution().y / 2) * 1.4f));
	escBtnObj->SetScale(Vec2(200.f, 200.f));
	AddObject(escBtnObj, GROUP_TYPE::UI);

	Object* tipObj = new Tip(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 1.f));
	tipObj->SetScale(Vec2(200.f, 500.f));
	AddObject(tipObj, GROUP_TYPE::UI);

	Object* faceObj = new FaceObj(Vec2((Core::GetInst()->GetResolution().x / 2) * 0.6f, (Core::GetInst()->GetResolution().y / 2) * 0.2f), FaceState::Smile);
	faceObj->SetScale(Vec2(300.f, 300.f));
	AddObject(faceObj, GROUP_TYPE::UI);

	Object* minusObj = new MinusHP();
	minusObj->SetPos(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 0.3f));
	AddObject(minusObj, GROUP_TYPE::ETC);

	CircleMgr* circleMgr = new CircleMgr;

	/*circleMgr->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	circleMgr->SetScale(Vec2(100.f, 100.f));*/

	AddObject(circleMgr, GROUP_TYPE::PLAYER);

	PlayerManager* playerMgr = new PlayerManager(circleMgr);

	AddObject(playerMgr, GROUP_TYPE::PLAYER);

	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ETC);

	int index = 4;
	float angle;//18�� ����
	switch (index)
	{
	case 0:
		angle = 360.f / 3.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 1:
		angle = 360.f / 7.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 2:
		//������ȯ
		break;
	case 3:
		Object* tObj = new Circle;
tObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
tObj->SetScale(Vec2(300.f, 300.f));
AddObject(tObj, GROUP_TYPE::MONSTER);
		//���ư��� ��
		break;
	case 4:
		angle = 360.f / 4.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 5:
		//������ȯ
		break;
	case 6: 
		angle = 360.f / 6.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}

		break;
	case 7:
		//�����̵�
		break;
	case 8:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
	case 9:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 10:

		//���ư��°�
		break;
	case 11:
		//������ȯ
		break;
	case 12:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;

	case 13:
		//���ư��� ��
		break;

	case 14:
		//�����̵�
		break;

	case 15:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 16:
		//�����̤ӵ�
		break;
	case 17:
		//������ȯ
		break;
	case 18:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 19:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
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
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	case 24:
		//������ȯ
		break;
	case 25:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
		break;
	case 26:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
		break;
	case 27:
		//�����̵�
		break;
	case 28:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
		break;
	case 29:
		//������ȯ
		break;
	case 30:
		angle = 360.f / 5.f;
		for (int i = 0; i < angle; i++)
		{
			//	//����Ŭ������ ����´� ����Ŭ������ set ũ������Ʈ ���������ž�
			//	//�ϳ� ���� ���ϴ� ����
			//	//���� ��ġ �ؿ�

			Object* gObj = new Gasi;
			gObj->SetPos(Vec2(cos(DEG2RAD(angle * i)), sin(DEG2RAD(angle * i))) * 300.f +
				(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2)));
			gObj->SetScale(Vec2(20.f, 20.f));
			AddObject(gObj, GROUP_TYPE::MONSTER);
		}
		break;
	default:
		break;
	}

	Scene::Enter();


	/*SetTextAlign(_dc, TA_CENTER);
	SetBkMode(_dc, TRANSPARENT);
	TextOut(_dc, GetPos().x, GetPos().y - 20, L"Quit", lstrlen(L"Quit"));*/
}

void TipScene::Exit()
{
}


void TipScene::Update()
{
	Scene::Update();

}

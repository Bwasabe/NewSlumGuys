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
#include "BaseCircle.h"
#include "CircleRenderMgr.h"
#include "SceneMgr.h"
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

	Object* faceObj = new FaceObj(Vec2((Core::GetInst()->GetResolution().x / 2) * 0.6f, (Core::GetInst()->GetResolution().y / 2) * 1.f), FaceState::Smile);
	faceObj->SetScale(Vec2(300.f, 300.f));
	AddObject(faceObj, GROUP_TYPE::UI);

	/*Object* minusObj = new MinusHP();
	minusObj->SetPos(Vec2((Core::GetInst()->GetResolution().x / 2) * 1.2f, (Core::GetInst()->GetResolution().y / 2) * 0.3f));
	AddObject(minusObj, GROUP_TYPE::ETC);*/

	CircleMgr* circleMgr = new CircleMgr;

	/*circleMgr->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	circleMgr->SetScale(Vec2(100.f, 100.f));*/

	AddObject(circleMgr, GROUP_TYPE::PLAYER);

	PlayerManager* playerMgr = new PlayerManager;

	AddObject(playerMgr, GROUP_TYPE::PLAYER);

	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ETC);



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

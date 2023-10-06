#include "pch.h"
#include "EndingScene.h"
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
#include "ThornMonster.h"
#include "Gasi.h"
#include "StartBtn.h"
#include "QuitBtn.h"
#include "Explain.h"
#include "EndBtn.h"


void EndingScene::Enter()
{

	Object* endBtnObj = new EndBtn(Vec2((Core::GetInst()->GetResolution().x / 2), (Core::GetInst()->GetResolution().y / 2)));
	endBtnObj->SetScale(Vec2(200.f, 200.f));
	AddObject(endBtnObj, GROUP_TYPE::UI);

}

void EndingScene::Exit()
{
}

void EndingScene::Update()
{
	Scene::Update();

}

EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
}

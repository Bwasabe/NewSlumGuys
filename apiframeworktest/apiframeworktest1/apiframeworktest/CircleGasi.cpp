#include "pch.h"
#include "CircleGasi.h"
#include "Core.h"
#include "SceneMgr.h"
#include "func.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SelectGDI.h"
#include "TimeMgr.h"
#include "SoundMgr.h"
#include "Image.h"
#include "SceneMgr.h"
CircleGasi::CircleGasi()
{
}

CircleGasi::~CircleGasi()
{
}

void CircleGasi::Render(HDC _dc)
{

}

void CircleGasi::Update()
{
}

void CircleGasi::EnterCollision(Collider* _pOther)
{
	SceneMgr::GetInst()->ChangeScene(SCENE_TYPE::SCENE_01);
}

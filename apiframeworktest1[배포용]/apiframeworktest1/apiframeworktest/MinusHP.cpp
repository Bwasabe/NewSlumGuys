#include "pch.h"
#include "MinusHP.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

MinusHP::MinusHP(): m_hp(30)
{
	CreateCollider(COLLIDER_TYPE::CIRCLE);

	GetCollider()->SetScale(Vec2(30.f, 30.f));
}

MinusHP::~MinusHP()
{
}

void MinusHP::Update()
{

}

void MinusHP::Render(HDC _dc)
{
	Component_Render(_dc);
}

void MinusHP::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player1")
	{
		int val = GeHP();
		SetHP(val--);

		//DeleteObject(this);
	}
}

#include "pch.h"
#include "BaseEnemy.h"
#include "CircleMgr.h"

BaseEnemy::BaseEnemy()
{
}

BaseEnemy::~BaseEnemy()
{
}


void BaseEnemy::Init()
{
	CreateCollider(COLLIDER_TYPE::CIRCLE);

	GetCollider()->SetScale(Vec2(30.f, 30.f));

	Vec2 colliderOffset = CircleMgr::GetInst()->GetCirclePos();
	colliderOffset.y -= (CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness());

	GetCollider()->SetOffsetPos(colliderOffset);


}

void BaseEnemy::Update()
{
	
}



void BaseEnemy::Render(HDC _dc)
{
	Component_Render(_dc);
}

void BaseEnemy::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player1")
	{
		m_iPattern++;
	}
}

void BaseEnemy::ExecutePattern()
{
	// Switch문으로 index에 따라 오브젝트 생성
	m_vPatternObjs.clear();
}



#include "pch.h"
#include "BaseCircle.h"
#include "CircleMgr.h"

BaseCircle::BaseCircle()
	: m_Color(0)
	, m_bIsIn(false)
	, m_fCurrentCircleRadius(0)
	, m_iAlpha(255)
{
}

BaseCircle::~BaseCircle()
{
}

//void BaseCircle::FinalUpdate()
//{
//	Object::FinalUpdate();
//}

void BaseCircle::InitCollider(Vec2 offset)
{
	// collider »ý¼º
	CreateCollider(COLLIDER_TYPE::CIRCLE);
	GetCollider()->SetScale(GetScale());
	GetCollider()->SetOffsetPos(offset);
}
 
void BaseCircle::SetPosToCirclePos(float moveValue)
{
	Vec2 vPos = GetPos();

	vPos.x = m_vStartPos.x + cos(moveValue) * m_fCurrentCircleRadius;
	vPos.y = m_vStartPos.y + sin(moveValue) * m_fCurrentCircleRadius;

	SetPos(vPos);

}

void BaseCircle::SetInOrOutCircle(bool isIn)
{
	m_bIsIn = isIn;
	if (isIn)
	{
		SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - GetScale().x);
	}
	else
	{
		SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() + CircleMgr::GetInst()->GetThickness() + GetScale().x);
	}
	int a = 0;
}

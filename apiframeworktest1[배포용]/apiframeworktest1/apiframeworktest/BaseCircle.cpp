#include "pch.h"
#include "BaseCircle.h"

BaseCircle::BaseCircle()
	: m_Color(0)
	, m_bIsIn(false)
	, m_fMyRadius(0)
	, m_fCurrentCircleRadius(0)
	, m_iAlpha(255)
{
}

BaseCircle::~BaseCircle()
{
}
 
void BaseCircle::SetPosToCirclePos(float moveValue)
{
	Vec2 vPos = GetPos();

	vPos.x = m_vStartPos.x + cos(moveValue) * m_fCurrentCircleRadius;
	vPos.y = m_vStartPos.y + sin(moveValue) * m_fCurrentCircleRadius;

	SetPos(vPos);

}

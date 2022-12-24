#include "pch.h"
#include "BaseMoveCircle.h"
#include "TimeMgr.h"
#include "CircleMgr.h"

BaseMoveCircle::BaseMoveCircle() : BaseCircle()
	, m_bIsGoRight(true)
	, m_fSpeed(3)
	, m_fTimer(0)
{
}

BaseMoveCircle::~BaseMoveCircle()
{
}


//void BaseMoveCircle::SetInOrOutCircle(bool isIn)
//{
//	m_bIsIn = isIn;
//	if (isIn)
//	{
//		SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius() - m_fMyRadius * 0.5f);
//	}
//	else
//	{
//		SetCurrentRadius(CircleMgr::GetInst()->GetInnerRadius()+CircleMgr::GetInst()-> GetThickness()  + m_fMyRadius * 0.5f);
//	}
//}

void BaseMoveCircle::MoveObject()
{
	if (m_bIsGoRight)
		m_fTimer += fDT;
	else
		m_fTimer -= fDT;

	SetPosToCirclePos(m_fTimer * m_fSpeed);

}

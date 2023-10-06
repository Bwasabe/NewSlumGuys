#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "SelectGDI.h"
UINT Collider::g_iNextID = 0;
Collider::Collider(COLLIDER_TYPE type)
	: m_pOwner(nullptr)
	, m_colliderType(type)
	, m_iID(g_iNextID++)
{

}
Collider::Collider(const Collider& _origin)
	: m_pOwner(nullptr)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iNextID++)
{
	m_colliderType = _origin.m_colliderType;
}
Collider::~Collider()
{
}
void Collider::FinalUpdate()
{
	// Object 위치를 따라가겠다.
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}
/*HPEN hGreenPen = Core::GetInst()->GetPen(PEN_TYPE::GREEN);
	HPEN hDefaultPen = (HPEN)SelectObject(_dc, hGreenPen);*/
	//HBRUSH hHollowBrush = Core::GetInst()->GetBrush(BRUSH_TYPE::HOLLOW);
	//HBRUSH hDefaultBrush = (HBRUSH)SelectObject(_dc, hHollowBrush);
void Collider::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_iCheck)
		ePen = PEN_TYPE::RED;
	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	switch (m_colliderType)
	{
	case COLLIDER_TYPE::BOX:
		Rectangle(_dc
			, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
			, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
			, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
			, (int)(m_vFinalPos.y + m_vScale.y / 2.f));
		break;
	case COLLIDER_TYPE::CIRCLE:
		Ellipse(_dc
			, (int)(m_vFinalPos.x - m_vScale.x)
			, (int)(m_vFinalPos.y - m_vScale.y)
			, (int)(m_vFinalPos.x + m_vScale.x)
			, (int)(m_vFinalPos.y + m_vScale.y));
		break;
	default:
		break;
	}
	
	//SelectObject(_dc, hDefaultPen);
	//SelectObject(_dc, hDefaultBrush);
}

void Collider::StayCollision(Collider* _pOther)
{
	m_pOwner->StayCollision(_pOther);
}

void Collider::EnterCollision(Collider* _pOther)
{
	++m_iCheck;
	m_pOwner->EnterCollision(_pOther);
}

void Collider::ExitCollision(Collider* _pOther)
{
	--m_iCheck;
	m_pOwner->ExitCollision(_pOther);
}

#include "pch.h"
#include "CircleMgr.h"
#include "Core.h"

CircleMgr::CircleMgr()
	: m_fInnerRadius(300)
	, m_fCircleThickness(10)
{
}

CircleMgr::~CircleMgr()
{
}

void CircleMgr::Init()
{
	m_vCirclePos = Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2);
}

void CircleMgr::Update()
{
}

void CircleMgr::Render(HDC _dc)
{
	Vec2 pos = GetCirclePos();
	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, blackBrush);

	Ellipse(_dc,
		pos.x - m_fInnerRadius - m_fCircleThickness,
		pos.y - m_fInnerRadius - m_fCircleThickness,
		pos.x + m_fInnerRadius + m_fCircleThickness,
		pos.y + m_fInnerRadius + m_fCircleThickness);
	HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(_dc, whiteBrush);

	Ellipse(_dc,
		pos.x - m_fInnerRadius,
		pos.y - m_fInnerRadius,
		pos.x + m_fInnerRadius,
		pos.y + m_fInnerRadius);

	SelectObject(_dc, oldBrush);
	DeleteObject(blackBrush);
	DeleteObject(whiteBrush);
}

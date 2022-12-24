#ifndef CIRCLEMGR_H
#define CIRCLEMGR_H
#include "Object.h"

class CircleMgr
{
public:
	SINGLE(CircleMgr);

public:
	CircleMgr();
	virtual ~CircleMgr();
public:
	void Init();
	void Update();
	void Render(HDC _dc);

public:
	Vec2		GetCirclePos() { return m_vCirclePos; }
	void		SetCirclePos(const Vec2& pos) { m_vCirclePos = pos; }

	float		GetInnerRadius() { return m_fInnerRadius; }
	void		SetInnerRadius(const float& radius) { m_fInnerRadius = radius; }

	float		GetThickness() { return m_fCircleThickness; }
	void		SetThickness(const float& thickness) { m_fCircleThickness = thickness; }

private:
	float		m_fInnerRadius;
	float		m_fCircleThickness;
	Vec2		m_vCirclePos;

};

#endif //!CIRCLEMGR_H
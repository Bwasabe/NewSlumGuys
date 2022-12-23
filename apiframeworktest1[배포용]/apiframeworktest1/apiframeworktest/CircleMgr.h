#ifndef CIRCLEMGR_H
#define CIRCLEMGR_H
#include "Object.h"

class CircleMgr : public Object
{
public:
	SINGLE(CircleMgr);
private:
	CLONE(CircleMgr);

public:
	CircleMgr();
	virtual ~CircleMgr();
public:
	void Init() override;
	void Update() override;
	void Render(HDC _dc) override;

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
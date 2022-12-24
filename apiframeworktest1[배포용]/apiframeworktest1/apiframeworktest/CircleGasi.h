#pragma once
#include "BaseCircle.h"
class Image;
class CircleGasi :
    public BaseCircle
{
public:
	CircleGasi();
	~CircleGasi();

public:
	void Render(HDC _dc) override;
	virtual void Update() override;
	virtual void	EnterCollision(Collider* _pOther)override;

	CLONE(CircleGasi);

private:
	Image* m_circleImage;
};



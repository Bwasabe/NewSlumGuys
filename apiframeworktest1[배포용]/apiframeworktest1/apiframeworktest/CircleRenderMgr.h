#pragma once
#include "Object.h"
#include "BaseCircle.h"

class CircleRenderMgr
{
public:
	CircleRenderMgr();
	virtual ~CircleRenderMgr();

	SINGLE(CircleRenderMgr);
public:
	void Render(HDC _dc); // ���� ����

public:
	void AddCircle(BaseCircle* circle) { m_vCircles.push_back(circle); }

private:
	vector<BaseCircle*> m_vCircles;
};


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
	void Render(HDC _dc); // 원들 랜더

public:
	void AddCircle(BaseCircle* circle) { m_vCircles.push_back(circle); }
	void RemoveCircle(BaseCircle* circle) {
		m_vCircles.erase(remove(m_vCircles.begin(), m_vCircles.end(), circle), m_vCircles.end());
		int a = 0;
	}

private:
	vector<BaseCircle*> m_vCircles;
};


#pragma once
#include "Object.h"
#include "BaseCircle.h"
#include "func.h"

class CircleRenderMgr
{
public:
	CircleRenderMgr();
	virtual ~CircleRenderMgr();

	SINGLE(CircleRenderMgr);
public:
	void Render(HDC _dc); // 원들 랜더

public:
	void AddCircle(BaseCircle* circle) { circle->SetIndex(m_vCircles.size()); m_vCircles.push_back(circle); }
	void RemoveCircle(BaseCircle* circle) {
		//m_vCircles.erase(remove(m_vCircles.begin(), m_vCircles.end(), circle), m_vCircles.end());
		m_vCircles.erase(m_vCircles.begin() + circle->GetIndex());
		for (int i = 0; i < m_vCircles.size(); ++i)
		{
			m_vCircles[i]->SetIndex(i);
		}
	}

	void RemoveAllCircle() { m_vCircles.clear(); }

private:
	vector<BaseCircle*> m_vCircles;
};


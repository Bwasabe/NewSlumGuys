#pragma once
#include "Object.h"
#include "BaseCircle.h"

class CircleRenderMgr : public Object
{
public:
	CircleRenderMgr();
	virtual ~CircleRenderMgr();

	SINGLE(CircleRenderMgr);
public:
	void Update() {}; // 플레이어들의 업데이트
	void Render(HDC _dc) override; // 원들 랜더

public:

private:
	CLONE(CircleRenderMgr);

public:
	void AddCircle(BaseCircle* circle) { m_vCircles.push_back(circle); }

private:
	vector<BaseCircle*> m_vCircles;
};


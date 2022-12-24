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
	void Update() {}; // �÷��̾���� ������Ʈ
	void Render(HDC _dc) override; // ���� ����

public:

private:
	CLONE(CircleRenderMgr);

public:
	void AddCircle(BaseCircle* circle) { m_vCircles.push_back(circle); }

private:
	vector<BaseCircle*> m_vCircles;
};


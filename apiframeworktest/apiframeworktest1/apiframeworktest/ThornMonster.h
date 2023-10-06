#pragma once
#include "Object.h"

class Image;
class ThornMonster 
	: public Object
{
private:
	Image* m_iTImage;
	int m_iHp; //����� ���� ��������
	int m_iThornTime; //�� �ʸ��� ���� ������ �ٲܰ��� (������ �ɵ�)
	int m_iThornCnt; //�� ���� ���ø� �����Ұ��� (������ �ɵ�)
public:
		// Object��(��) ���� ��ӵ�
	virtual void Update() override;

	void Render(HDC _dc) override;
	void CreateThorn();
public: 
	ThornMonster();
	~ThornMonster();
private:
	CLONE(ThornMonster);
};


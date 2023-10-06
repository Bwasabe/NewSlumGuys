#pragma once
#include "Object.h"

class Image;
class ThornMonster 
	: public Object
{
private:
	Image* m_iTImage;
	int m_iHp; //몇바퀴 돌면 죽을건지
	int m_iThornTime; //몇 초마다 가시 생성을 바꿀건지 (랜덤이 될듯)
	int m_iThornCnt; //몇 개의 가시를 생성할건지 (랜덤이 될듯)
public:
		// Object을(를) 통해 상속됨
	virtual void Update() override;

	void Render(HDC _dc) override;
	void CreateThorn();
public: 
	ThornMonster();
	~ThornMonster();
private:
	CLONE(ThornMonster);
};


#include "pch.h"
#include "BallPlayer.h"
#include "KeyMgr.h"
#include "Collider.h"

BallPlayer::BallPlayer() 
	: BaseMoveCircle()
	, m_kUpKey(KEY::A)
	, m_kDownKey(KEY::A)
{
	//// collider »õ¼º
	//CreateCollider(COLLIDER_TYPE::CIRCLE);
	//GetCollider()->SetScale(Vec2(30.f, 30.f));
	//GetCollider()->SetOffsetPos(Vec2(0, 0));

}

BallPlayer::BallPlayer(KEY upKey, KEY downKey)
	: BaseMoveCircle()
	, m_kUpKey(upKey)
	, m_kDownKey(downKey)
{


}

BallPlayer::~BallPlayer()
{
}


void BallPlayer::Update()
{
	MoveObject();

	if (KEY_TAP(m_kUpKey)){
		
		SetInOrOutCircle(false);
	}

	if (KEY_TAP(m_kDownKey))
	{
		SetInOrOutCircle(true);
	}
	if (KEY_TAP(KEY::SPACE))
	{
		m_bIsIn = !m_bIsIn;
		SetInOrOutCircle(m_bIsIn);
		//SetIsGoRight(!GetIsGoRight());
	}

 	Collider* c = GetCollider();
	int a = 0;
}

void BallPlayer::Render(HDC _dc)
{
	Component_Render(_dc);
}


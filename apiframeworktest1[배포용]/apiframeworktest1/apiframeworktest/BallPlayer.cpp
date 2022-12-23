#include "pch.h"
#include "BallPlayer.h"
#include "KeyMgr.h"
#include "Collider.h"

BallPlayer::BallPlayer() 
	: BaseMoveCircle()
	, m_kUpKey(KEY::A)
	, m_kDownKey(KEY::A)
{
	// collider 货己
	CreateCollider(COLLIDER_TYPE::CIRCLE);
	GetCollider()->SetScale(Vec2(m_fMyRadius, m_fMyRadius));
	

}

BallPlayer::BallPlayer(KEY upKey, KEY downKey)
	: BaseMoveCircle()
	, m_kUpKey(upKey)
	, m_kDownKey(downKey)
{
	// collider 积己
	CreateCollider(COLLIDER_TYPE::CIRCLE);
	GetCollider()->SetScale(Vec2(m_fMyRadius, m_fMyRadius));

}

BallPlayer::~BallPlayer()
{
}


void BallPlayer::Update()
{
	MoveObject();

	if (KEY_TAP(m_kUpKey))
	{
		SetInOrOutCircle(false);
	}
	if (KEY_TAP(m_kDownKey))
	{
		SetInOrOutCircle(true);
	}
	if (KEY_TAP(KEY::SPACE))
	{
		SetIsGoRight(!GetIsGoRight());
	}
}

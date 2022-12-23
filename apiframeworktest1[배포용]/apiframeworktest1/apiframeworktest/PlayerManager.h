#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "BallPlayer.h"
#include "Object.h"
class CircleMgr;

class PlayerManager : public Object
{
public:
	PlayerManager();
	PlayerManager(CircleMgr* mgr);
	~PlayerManager();

public:
	void Init() override; // 플레이어 생성
	void Update() override; // 플레이어들의 업데이트
	void Render(HDC _dc) override; // 플레이어 랜더

public:
	void SetPlayer1(BallPlayer* player) { m_pPlayer1 = player; }
	void SetPlayer2(BallPlayer* player) { m_pPlayer2 = player; }

private:
	CLONE(PlayerManager);

private:
	BallPlayer* m_pPlayer1;
	BallPlayer* m_pPlayer2;
	CircleMgr* m_pCircleMgr;

};

#endif // !PLAYERMANAGER_H





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
	void Init() override; // �÷��̾� ����
	void Update() override; // �÷��̾���� ������Ʈ
	void Render(HDC _dc) override; // �÷��̾� ����

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





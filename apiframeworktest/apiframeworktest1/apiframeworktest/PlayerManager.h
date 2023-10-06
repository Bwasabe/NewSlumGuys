#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "BallPlayer.h"
#include "Object.h"
class CircleMgr;

class PlayerManager : public Object
{
public:
	PlayerManager();
	~PlayerManager();

public:
	void Init() override; // �÷��̾� ����
	void Update() override {} // �÷��̾���� ������Ʈ
	//void Render(HDC _dc) override; // �÷��̾� �ݸ��� ������ ����
	//void FinalUpdate() override;
public:
	void SetPlayer1(BallPlayer* player) { m_pPlayer1 = player; }
	BallPlayer* GetPlayer1() { return m_pPlayer1; }
	void SetPlayer2(BallPlayer* player) { m_pPlayer2 = player; }
	BallPlayer* GetPlayer2() { return m_pPlayer2; }


private:
	CLONE(PlayerManager);

private:
	BallPlayer* m_pPlayer1;
	BallPlayer* m_pPlayer2;

};

#endif // !PLAYERMANAGER_H





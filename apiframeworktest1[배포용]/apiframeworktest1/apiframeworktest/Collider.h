#pragma once
class Object;

enum class COLLIDER_TYPE
{
	BOX,
	CIRCLE,
};

class Collider
{
private:
	Object* m_pOwner; // collider를 소유하고 있는 오브젝트
	Vec2	m_vOffsetPos; // 오브젝트로부터 상대적인 위치
	Vec2	m_vFinalPos; // finalupdate에서 매 프레임마다 계산
	Vec2	m_vScale;  // 충돌체 크기
	UINT	m_iID;     // 충돌체 고유한 ID 값
	static UINT g_iNextID;
	UINT    m_iCheck;
	COLLIDER_TYPE m_colliderType;
public:
	Collider(COLLIDER_TYPE type);
	Collider(const Collider& _origin);
	~Collider();
public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; } // Circle일경우 Radius가 x와 y임
	UINT GetID() {	return m_iID; }
	Vec2 GetFinalPos() { return m_vFinalPos; }
	Object* GetObj() { return m_pOwner; }
	COLLIDER_TYPE GetColliderType() { return m_colliderType; }

public:
	void FinalUpdate();
	void Render(HDC _dc);
	Collider& operator = (Collider& _origin) = delete;
	void StayCollision(Collider* _pOther); // 충돌 중인 경우 호출 되는 함수
	void EnterCollision(Collider* _pOther); // 충돌 진입 호출 함수
	void ExitCollision(Collider* _pOther);
	friend class Object;
};


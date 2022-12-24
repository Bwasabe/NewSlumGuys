#pragma once
#include "Object.h"

class Image;
enum class FaceState
{
	Smile,
	Angry,
	Die
};
class FaceObj :
    public Object
{
public :
	FaceObj(Vec2 vec, FaceState state);
	~FaceObj();

public:
	void Render(HDC _dc) override;
	virtual void Update() override;
	void ChcekFace();
	CLONE(FaceObj);

private:
	Image* m_faceImage;
	FaceState m_faceState;
	bool m_isSmile;
	bool m_isDead;


public:
	void SetFaceState(FaceState _state) { m_faceState = _state; }
	FaceState GetFaceState() { return m_faceState; }

	void SetIsSmile(bool issmile) { m_isSmile = issmile; }
	bool GetIsSmile() { return  m_isSmile; }
};


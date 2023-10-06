#include "pch.h"
#include "TeleportObject.h"
#include "CircleMgr.h"
#include "CircleRenderMgr.h"
#include "BaseMoveCircle.h"

TeleportObject::TeleportObject()
{
}

TeleportObject::~TeleportObject()
{
}

void TeleportObject::Init()
{
	BaseCircle* teleportObj = new BaseCircle;
	teleportObj->SetScale(GetScale());
	teleportObj->SetStartPos(m_vStartPos);

	teleportObj->SetPosToCirclePos(m_fMoveValue);

	teleportObj->SetColor(RGB(0, 0, 0));
	teleportObj->SetAlpha(255);

	CircleRenderMgr::GetInst()->AddCircle(teleportObj);

}

void TeleportObject::EnterCollision(Collider* _pOther)
{
	BaseMoveCircle* pOtherObj = dynamic_cast<BaseMoveCircle*>(_pOther->GetObj());

	pOtherObj->SetTimer(m_fMoveValue + pOtherObj->GetTimer());

	/*if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}*/
}

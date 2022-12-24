#include "pch.h"
#include "CircleRenderMgr.h"
#include "Core.h"

CircleRenderMgr::CircleRenderMgr()
{
}

CircleRenderMgr::~CircleRenderMgr()
{
}

void CircleRenderMgr::Render(HDC _dc)
{

	HDC hMemDC = CreateCompatibleDC(_dc);
	Vec2 resolution = Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	HBITMAP hBitMap = CreateCompatibleBitmap(_dc, resolution.x, resolution.y);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitMap);


	PatBlt(hMemDC, 0, 0, resolution.x, resolution.y, WHITENESS);

	for (auto it : m_vCircles)
	{
		if (it != nullptr)
		{
			HBRUSH blackBrush = CreateSolidBrush(it->GetColor());
			HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC, blackBrush);

			BLENDFUNCTION bf;
			bf.AlphaFormat = 0;
			bf.BlendFlags = 0;
			bf.BlendOp = AC_SRC_OVER;
			bf.SourceConstantAlpha = it->GetAlpha();

			Vec2 vPos = it->GetPos();

			Ellipse(hMemDC
				, (int)(vPos.x - (float)(it->GetMyRadius()))
				, (int)(vPos.y - (float)(it->GetMyRadius()))
				, (int)(vPos.x + (float)(it->GetMyRadius()))
				, (int)(vPos.y + (float)(it->GetMyRadius()))
			);

			AlphaBlend(_dc
				, (int)(vPos.x - (float)(it->GetMyRadius()))
				, (int)(vPos.y - (float)(it->GetMyRadius()))
				, it->GetMyRadius() * 2.f
				, it->GetMyRadius() * 2.f
				, hMemDC
				, (int)(vPos.x - (float)(it->GetMyRadius()))
				, (int)(vPos.y - (float)(it->GetMyRadius()))
				, it->GetMyRadius() * 2.f
				, it->GetMyRadius() * 2.f
				, bf);

			SelectObject(hMemDC, oldBrush);
			DeleteObject(blackBrush);
		}
	}

	SelectObject(hMemDC, hOldBitmap); // 기존 비트맵 선택

	DeleteObject(hBitMap);
	DeleteDC(hMemDC);

}

#include "pch.h"
#include "CircleRenderMgr.h"
#include "Core.h"
#include "Image.h"

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

			if (it->GetImage() == nullptr)
			{
					Ellipse(hMemDC
				, (int)(vPos.x - (float)(it->GetScale().x))
				, (int)(vPos.y - (float)(it->GetScale().x))
				, (int)(vPos.x + (float)(it->GetScale().x))
				, (int)(vPos.y + (float)(it->GetScale().x))
			);


					AlphaBlend(_dc
						, (int)(vPos.x - (float)(it->GetScale().x))
						, (int)(vPos.y - (float)(it->GetScale().x))
						, it->GetScale().x * 2.f
						, it->GetScale().x * 2.f
						, hMemDC
						, (int)(vPos.x - (float)(it->GetScale().x))
						, (int)(vPos.y - (float)(it->GetScale().x))
						, it->GetScale().x * 2.f
						, it->GetScale().x * 2.f
						, bf);
			}
			else
			{
				int Width = (int)it->GetImage()->GetWidth();
				int Height = (int)it->GetImage()->GetHeight();
				Vec2 vPos = it->GetPos();

				TransparentBlt(_dc
					, (int)(vPos.x - (float)(Width / 2))
					, (int)(vPos.y - (float)(Height / 2))
					, Width * 0.45f, Height * 0.45f
					, it->GetImage()->GetDC()
					, 0, 0, Width, Height
					, RGB(255, 0, 255));


				AlphaBlend(_dc
					, 0,0
					, Width
					, Height
					, hMemDC
					, 0
					, 0
					, Width
					, Height
					, bf);
			}
		


			SelectObject(hMemDC, oldBrush);
			DeleteObject(blackBrush);
		}
	}

	SelectObject(hMemDC, hOldBitmap); // 기존 비트맵 선택

	DeleteObject(hBitMap);
	DeleteDC(hMemDC);

}


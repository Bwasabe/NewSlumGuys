#pragma once
class SelectGDI
{
private:
	HDC		m_hDC;
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;
	HFONT  m_hDefaultFont;
	HFONT  m_hNewFont;
public:
	SelectGDI(HDC _dc, PEN_TYPE _ePenType);
	SelectGDI(HDC _dc, BRUSH_TYPE _eBrushType);
	SelectGDI(HDC _dc, HFONT font);
	~SelectGDI();
};


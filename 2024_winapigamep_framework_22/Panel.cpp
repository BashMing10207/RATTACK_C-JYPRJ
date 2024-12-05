#include "pch.h"
#include "Panel.h"

void Panel::Init()
{

}

void Panel::Update()
{

}

void Panel::Render(HDC _hdc)
{
	RenderText(_hdc);
}

void Panel::RenderText(HDC _hdc)
{
	//AddFontResourceW();


	HFONT myFont = ::CreateFont(
		30						// 높이
		, 0						// 폭 0이면 높이와 비례
		, 0						// 글자 전체 기울기
		, 0						// 기준선이 정해진 기울기
		, 0 						// 폰트의 두께
		, 0						// 이탤릭
		, 0						// 밑줄
		, 0						// 취소선
		, DEFAULT_CHARSET		// 케릭터 셋
		, 0						// 정밀도
		, 0						// 정밀도
		, 0						// 정밀도
		, 0						// 정밀도
		, L"굴림"				// 글꼴이름
	);

	HFONT oldFont = (HFONT)::SelectObject(_hdc, myFont);

	::GetTextExtentPoint32(_hdc, m_text.c_str(), m_text.length(), &textSize);

	// 텍스트의 시작 좌표 
	float textX = m_vPos.x - textSize.cx / 2;
	float textY = m_vPos.y - textSize.cy / 2;

	::TextOut(_hdc, textX, textY, m_text.c_str(), m_text.length());

	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}

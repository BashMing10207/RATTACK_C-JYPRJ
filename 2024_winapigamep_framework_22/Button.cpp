#include "pch.h"
#include "UI.h"
#include "UIManager.h"
#include "Button.h"

void Button::Init()
{
	m_isClick = false;
	m_isHover = false;
}
void Button::Update()
{

}

void Button::Render(HDC _hdc)
{
	RenderText(_hdc);
}

void Button::DrawUI(HDC _hdc)
{

}

bool Button::IsMouseHover()
{
	Vec2 mousePos = INPUT->GetMousePos();

	float left = m_vPos.x;
	float top = m_vPos.y;
	float right = m_vPos.x + m_vSize.x;
	float bottom = m_vPos.y + m_vSize.y;

	return (mousePos.x >= left && mousePos.x <= right && mousePos.y >= top && mousePos.y <= bottom);
}

bool Button::IsMouseUp()
{
	return IsMouseAction(KEY_STATE::UP);
}

bool Button::IsMouseDown()
{
	return IsMouseAction(KEY_STATE::DOWN);
}

bool Button::IsMouseHold()
{
	return IsMouseAction(KEY_STATE::PRESS);
}

bool Button::IsMouseAction(KEY_STATE _state)
{
	return IsMouseHover() && (INPUT->GetKey(KEY_TYPE::LBUTTON) == _state);
}


void Button::RenderText(HDC _hdc)
{
	int a = 0;
	//AddFontResourceW();
	HFONT myFont = ::CreateFont(
		30						// 높이
		, 0						// 폭 0이면 높이와 비례
		, 0						// 글자 전체 기울기
		, 0						// 기준선이 정해진 기울기
		, 0						// 폰트의 두께
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

	::TextOut(_hdc, m_vPos.x, m_vPos.y, m_text.c_str(), m_text.length());
	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}

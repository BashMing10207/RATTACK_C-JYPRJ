#include "pch.h"
#include "UI.h"
#include "UIManager.h"
#include "Button.h"
#include "Utils.h"
#include "TimeManager.h"

void Button::Init()
{
	m_isClick = false;
	m_isHover = false;
}

void Button::Update()
{
	if (IsMouseHover())
	{
		m_isHover = true;

		//cout << "마우스가 UI 위에 있음\n";
	}

	if (IsMouseDown())
	{
		m_isClick = true;
		cout << "마우스 누름\n";
	}
	else
	{
		m_isClick = false;
	}

	if (IsMouseUp())
	{
		cout << "마우스 뗌";
	}
	if (IsMouseHold())
	{
		m_isHover = true;
		cout << "누르고있음\n";
	}
	else
	{
		m_isHover = false;
	}

	if (m_isClick)
	{
		//GET_SINGLE(TimeManager)->AddDelayedTask(aa, 3.0f);
	}
}

void Button::Render(HDC _hdc)
{
	if (this == nullptr) return;
	Utils::RenderRect(_hdc, m_vPos, m_vSize.x, m_vSize.y);

	RenderText(_hdc);
}


bool Button::IsMouseHover()
{
	Vec2 mousePos = INPUT->GetMousePos();

	float left = m_vPos.x - m_vSize.x / 2;
	float top = m_vPos.y - m_vSize.y / 2;
	float right = m_vPos.x + m_vSize.x / 2;
	float bottom = m_vPos.y + m_vSize.y / 2;

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
	//AddFontResourceW();


	HFONT myFont = ::CreateFont(
		30						// 높이
		, 0						// 폭 0이면 높이와 비례
		, 0						// 글자 전체 기울기
		, 0						// 기준선이 정해진 기울기
		, m_isHover ? 0 : FW_BOLD 						// 폰트의 두께
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


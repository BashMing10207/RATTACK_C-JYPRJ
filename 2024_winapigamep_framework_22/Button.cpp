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

		//cout << "���콺�� UI ���� ����\n";
	}

	if (IsMouseDown())
	{
		m_isClick = true;
		cout << "���콺 ����\n";
	}
	else
	{
		m_isClick = false;
	}

	if (IsMouseUp())
	{
		cout << "���콺 ��";
	}
	if (IsMouseHold())
	{
		m_isHover = true;
		cout << "����������\n";
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
		30						// ����
		, 0						// �� 0�̸� ���̿� ���
		, 0						// ���� ��ü ����
		, 0						// ���ؼ��� ������ ����
		, m_isHover ? 0 : FW_BOLD 						// ��Ʈ�� �β�
		, 0						// ���Ÿ�
		, 0						// ����
		, 0						// ��Ҽ�
		, DEFAULT_CHARSET		// �ɸ��� ��
		, 0						// ���е�
		, 0						// ���е�
		, 0						// ���е�
		, 0						// ���е�
		, L"����"				// �۲��̸�
	);

	HFONT oldFont = (HFONT)::SelectObject(_hdc, myFont);

	::GetTextExtentPoint32(_hdc, m_text.c_str(), m_text.length(), &textSize);

	// �ؽ�Ʈ�� ���� ��ǥ 
	float textX = m_vPos.x - textSize.cx / 2;
	float textY = m_vPos.y - textSize.cy / 2;

	::TextOut(_hdc, textX, textY, m_text.c_str(), m_text.length());

	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}


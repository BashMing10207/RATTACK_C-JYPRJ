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
		30						// ����
		, 0						// �� 0�̸� ���̿� ���
		, 0						// ���� ��ü ����
		, 0						// ���ؼ��� ������ ����
		, 0						// ��Ʈ�� �β�
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

	::TextOut(_hdc, m_vPos.x, m_vPos.y, m_text.c_str(), m_text.length());
	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}

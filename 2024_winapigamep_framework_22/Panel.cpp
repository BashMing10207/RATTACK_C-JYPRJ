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
		30						// ����
		, 0						// �� 0�̸� ���̿� ���
		, 0						// ���� ��ü ����
		, 0						// ���ؼ��� ������ ����
		, 0 						// ��Ʈ�� �β�
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

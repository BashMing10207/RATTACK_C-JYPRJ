#include "pch.h"
#include "Panel.h"
#include "Utils.h"

Panel::~Panel()
{
}

void Panel::Init()
{
	m_isHover = false;
	m_isClick = false;
	m_isTexture = false;
	m_textSize = { 0, 0 };
	m_pTex = nullptr;

}

void Panel::Update()
{
	
	if (IsMouseHover())
	{
		m_isHover = true;
		SetPos();
	}

	if (IsMouseDown())
	{
		m_isClick = true;
		cout << "Panel 누름\n";
	}
	else
	{
		m_isClick = false;
	}

	if (IsMouseUp())
	{
		cout << "Panel 뗌";
	}
	if (IsMouseHold())
	{
		
		cout << "Panel누르고있음\n";
	}
	else
	{
		
	}

	if (m_isClick)
	{
		//GET_SINGLE(TimeManager)->AddDelayedTask(aa, 3.0f);
	}
}

void Panel::Render(HDC _hdc)
{
	RenderPanel(_hdc);
	RenderText(_hdc);
	RenderTexture(_hdc);
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

	::GetTextExtentPoint32(_hdc, m_text.c_str(), m_text.length(), &m_textSize);

	// 텍스트의 시작 좌표 
	float textX = m_vPos.x - m_textSize.cx / 2;
	float textY = m_vPos.y - m_textSize.cy / 2;

	::TextOut(_hdc, textX, textY, m_text.c_str(), m_text.length());

	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}

void Panel::RenderTexture(HDC _hdc)
{
	if (m_isTexture)
	{
		Vec2 vPos = GetPos();

		Vec2 vSize = GetSize();

		int width = m_pTex->GetWidth();
		int height = m_pTex->GetHeight();
		::TransparentBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width, height,
			m_pTex->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
}

void Panel::RenderPanel(HDC _hdc)
{
	if (m_hasPanel)
	{
		Utils::RenderRect(_hdc, m_vPos, m_vSize.x, m_vSize.y);
	}
}

void Panel::SetTexture(wstring name, wstring _texture)
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(name, _texture);
	//m_pTex = 	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Granade", L"Texture\\ShinGranade.bmp");;
}

void Panel::SetHasPanel(bool _isHas)
{
	m_hasPanel = _isHas;
}

bool Panel::IsMouseHover()
{
	Vec2 mousePos = INPUT->GetMousePos();

	float left = m_vPos.x - m_vSize.x / 2;
	float top = m_vPos.y - m_vSize.y / 2;
	float right = m_vPos.x + m_vSize.x / 2;
	float bottom = m_vPos.y + m_vSize.y / 2;

	return (mousePos.x >= left && mousePos.x <= right && mousePos.y >= top && mousePos.y <= bottom);
}

bool Panel::IsMouseUp()
{
	return IsMouseAction(KEY_STATE::UP);
}

bool Panel::IsMouseDown()
{
	return IsMouseAction(KEY_STATE::DOWN);
}

bool Panel::IsMouseHold()
{
	return IsMouseAction(KEY_STATE::PRESS);
}

bool Panel::IsMouseAction(KEY_STATE _state)
{
	return IsMouseHover() && (INPUT->GetKey(KEY_TYPE::LBUTTON) == _state);
}



#include "pch.h"
#include "Panel.h"
#include "Utils.h"
#include "TimeManager.h"
#include "GamePlayer.h"
#include "GamePlayManager.h"

Panel::~Panel()
{
}

void Panel::Init()
{
	m_isHover = false;
	m_isSelected = false;
	m_isTexture = false;
	m_textSize = { 0, 0 };
	m_pTex = nullptr;
	m_initPos = { m_vPos.x,m_vPos.y };

}

void Panel::Update()
{

	if (m_isSelected)
	{
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) && !m_isHover)
		{
			m_isSelected = !m_isSelected;
		}
	}

	if (m_isMoveing)
	{
		if (m_currentTime < m_moveTime)
		{
			// Lerp
			float t = m_currentTime / m_moveTime; // ����
			m_vPos.x = Lerp(m_vPos.x, m_targetPos.x, t);
			m_vPos.y = Lerp(m_vPos.y, m_targetPos.y, t);

			m_currentTime += fDT;
		}
		else
		{
			m_vPos = m_targetPos;
			m_currentTime = m_moveTime; // �̵� �Ϸ�
			m_isMoveing = false;
			m_isMoved = true;
		}
	}

	// ���콺�� UI ���� �ȿ� �ִ���
	if (IsMouseHover())
	{
		if (!m_isHover)  // ȣ�� ���°� �ƴϾ�������
		{
			m_isHover = true;  // ȣ�� ����
			SetPosLerp({ m_vPos.x, m_vPos.y - 10 }, 0.5f);  // �̵� ó��
		}
	}
	else //���� �ȿ� ���ٸ�
	{
		// ���콺�� UI�� �����
		if (m_isHover)  // ȣ�� ���¿�������
		{
			SetPosLerp({ m_vPos.x, m_initPos.y }, 0.5f); // ���� ��ġ
			m_isHover = false;  // ȣ�� ����
		}
	}

	if (IsMouseDown())
	{
		m_isSelected = true;
		GET_SINGLE(GamePlayManager)->CurrentGamePlayer()->selectecIndex = GetIndex();

	}

	if (IsMouseUp())
	{

	}
	if (IsMouseHold())
	{

	}
	else
	{

	}

	if (m_isSelected)
	{
		//GET_SINGLE(TimeManager)->AddDelayedTask(aa, 3.0f);
	}
}

void Panel::Render(HDC _hdc)
{
	RenderSelectedPanel(_hdc);
	RenderPanel(_hdc);
	RenderText(_hdc);
	RenderTexture(_hdc);
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

	::GetTextExtentPoint32(_hdc, m_text.c_str(), m_text.length(), &m_textSize);

	// �ؽ�Ʈ�� ���� ��ǥ 
	float textX = m_vPos.x - m_textSize.cx / 2;
	float textY = m_vPos.y - m_textSize.cy / 2;

	::TextOut(_hdc, textX, textY, m_text.c_str(), m_text.length());

	::SelectObject(_hdc, oldFont);
	::DeleteObject(myFont);
}

void Panel::RenderSelectedPanel(HDC _hdc)
{
	if (m_isSelected)
	{
		Utils::RenderRectColor(_hdc, m_vPos, m_vSize.x + 10, m_vSize.y + 10, RGB(255, 0, 0));
	}
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
	m_isTexture = true;
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(name, _texture);
	//m_pTex = 	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Granade", L"Texture\\ShinGranade.bmp");;
}

void Panel::SetHasPanel(bool _isHas)
{
	m_hasPanel = _isHas;
}

void Panel::SetIndex(int _index)
{
	m_index = _index;
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



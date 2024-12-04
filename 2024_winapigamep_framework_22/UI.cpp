#include "pch.h"
#include "InputManager.h"
#include "UI.h"

UI::UI()
	: m_vPos{}
	, m_vSize{}
	, m_isActive{ false }
	, m_parent{ nullptr }
	, m_text{ L"" }
{

}

UI::~UI()
{
}

void UI::Init()
{
}

void UI::Update()
{

}

void UI::Render(HDC _hdc)
{
	// �θ� ������
	DrawUI(_hdc);

	// �ڽ� ������
	for (auto& child : m_children)
	{
		if (child && child->GetActive()) // Ȱ��ȭ�� �ڽĸ�
		{
			child->Render(_hdc);
		}
	}
}

void UI::RenderText(HDC _hdc)
{

}


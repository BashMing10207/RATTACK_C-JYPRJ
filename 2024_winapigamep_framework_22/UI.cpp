#include "pch.h"
#include "InputManager.h"
#include "UI.h"
#include "TimeManager.h"

UI::UI()
	: m_vPos{}
	, m_vSize{}
	, m_isActive{ false }
	, m_parent{ nullptr }
	, m_text{ L"" }
	, m_isMoveing{ false }
	, m_currentTime{ 0.f }
	, m_moveTime{ 0.f }
	, m_isMoved{ true }
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
	for (auto& child : m_children)
	{
		if (child && child->GetActive())
		{
			child->Render(_hdc);
		}
	}
}

void UI::RenderText(HDC _hdc)
{

}

void UI::SetPosLerp(Vec2 _targetPos, float _moveTime)
{
	m_isMoveing = true;
	m_targetPos = _targetPos;  // 목표 위치 설정
	m_moveTime = _moveTime;    // 이동 시간 설정
	m_currentTime = 0.0f;     // 경과 시간 초기화
	m_isMoved = false;
}

float UI::Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

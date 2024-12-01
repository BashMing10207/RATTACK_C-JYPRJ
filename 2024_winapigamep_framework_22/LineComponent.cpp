#include "pch.h"
#include "LineComponent.h"
#include "Object.h"
#include "InputManager.h"

LineComponent::LineComponent()
	: m_isDrawing(false), m_startPos(Vec2()), m_endPos(Vec2())
{
}

LineComponent::~LineComponent()
{
}

void LineComponent::LateUpdate()
{

	if (IsMouseOverObject() == true) // 마우스가 오브젝트 위에 있을 때
	{
		if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::DOWN)
		{
			// 마우스를 클릭한 상태에서 선 그리기 시작
			StartDrawing(GetOwner()->GetPos());
		}

	}

	if (m_isDrawing)
	{
		if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::PRESS)
		{
			// 드래그 중일 때 선 업데이트
			UpdateDrawing(INPUT->GetMousePos());
		}
		else if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::UP)
		{
			// 드래그 종료
			StopDrawing();
		}
	}
}

bool LineComponent::IsMouseOverObject()
{
	Object* owner = GetOwner();
	Vec2 ownerPos = owner->GetPos();
	Vec2 ownerSize = owner->GetSize();

	// 원 중심 좌표
	Vec2 center = ownerPos;
	float radius = ownerSize.x * 0.5f; // 가로 크기의 절반을 반지름으로 사용

	Vec2 mousePos = INPUT->GetMousePos();

	// 원 중심과 마우스 사이의 거리 계산
	float distance = sqrt(pow(mousePos.x - center.x, 2) + pow(mousePos.y - center.y, 2));

	// 거리가 반지름보다 작거나 같으면 마우스가 원 내부에 있음
	return distance <= radius;
}

void LineComponent::StartDrawing(Vec2 startPos)
{
	m_isDrawing = true;
	m_startPos = startPos;

}
void LineComponent::UpdateDrawing(Vec2 mousePos)
{
	m_endPos = mousePos;
}

void LineComponent::StopDrawing()
{
	m_isDrawing = false;  // 선 그리기 종료
}

Vec2 LineComponent::GetDistance()
{
	return m_startPos - m_endPos;
}

void LineComponent::Render(HDC _hdc)
{
	if (m_isDrawing)
	{
		MoveToEx(_hdc, m_startPos.x, m_startPos.y, NULL);
		LineTo(_hdc, m_endPos.x, m_endPos.y);  // 선을 그린다
	}
}

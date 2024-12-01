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

	if (IsMouseOverObject() == true) // ���콺�� ������Ʈ ���� ���� ��
	{
		if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::DOWN)
		{
			// ���콺�� Ŭ���� ���¿��� �� �׸��� ����
			StartDrawing(GetOwner()->GetPos());
		}

	}

	if (m_isDrawing)
	{
		if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::PRESS)
		{
			// �巡�� ���� �� �� ������Ʈ
			UpdateDrawing(INPUT->GetMousePos());
		}
		else if (INPUT->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::UP)
		{
			// �巡�� ����
			StopDrawing();
		}
	}
}

bool LineComponent::IsMouseOverObject()
{
	Object* owner = GetOwner();
	Vec2 ownerPos = owner->GetPos();
	Vec2 ownerSize = owner->GetSize();

	// �� �߽� ��ǥ
	Vec2 center = ownerPos;
	float radius = ownerSize.x * 0.5f; // ���� ũ���� ������ ���������� ���

	Vec2 mousePos = INPUT->GetMousePos();

	// �� �߽ɰ� ���콺 ������ �Ÿ� ���
	float distance = sqrt(pow(mousePos.x - center.x, 2) + pow(mousePos.y - center.y, 2));

	// �Ÿ��� ���������� �۰ų� ������ ���콺�� �� ���ο� ����
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
	m_isDrawing = false;  // �� �׸��� ����
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
		LineTo(_hdc, m_endPos.x, m_endPos.y);  // ���� �׸���
	}
}

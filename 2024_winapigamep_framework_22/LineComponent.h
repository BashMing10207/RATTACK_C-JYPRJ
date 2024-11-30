#pragma once
#include "Component.h"

class LineComponent : public Component
{

public:
    LineComponent();
    ~LineComponent();

    void StartDrawing(Vec2 startPos);  // �� �׸��� ����
    void UpdateDrawing(Vec2 mousePos); // �� �׸��� ������Ʈ
    void StopDrawing();                // �� �׸��� ����
    void LateUpdate() override;
    void Render(HDC _hdc) override;    // �� �׸��� ������
    bool IsMouseOverObject();

private:
    bool m_isDrawing;  // ���� �׸��� �ִ�?
    Vec2 m_startPos;   // ���� ���� ��ġ
    Vec2 m_endPos;     // ���� �� ��ġ(���콺�� ��ġ)
};
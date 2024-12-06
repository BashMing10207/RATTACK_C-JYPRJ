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
    Vec2 GetDistance();                // ���� ���콺�� �Ÿ�
    void LateUpdate2();
    void LateUpdate() override;
    void Render(HDC _hdc) override;    // �� �׸��� ������
    void DoAction();
    bool IsMouseInStone();

private:
    bool m_isDrawing;  // ���� �׸��� �ִ�?
    Vec2 m_startPos;   // ���� ���� ��ġ
    Vec2 m_endPos;     // ���� �� ��ġ(���콺�� ��ġ)


};
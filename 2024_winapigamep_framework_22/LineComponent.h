#pragma once
#include "Component.h"

class LineComponent : public Component
{

public:
    LineComponent();
    ~LineComponent();

    void StartDrawing(Vec2 startPos);  // 선 그리기 시작
    void UpdateDrawing(Vec2 mousePos); // 선 그리기 업데이트
    void StopDrawing();                // 선 그리기 종료
    Vec2 GetDistance();                // 돌과 마우스의 거리
    void LateUpdate2();
    void LateUpdate() override;
    void Render(HDC _hdc) override;    // 선 그리기 렌더링
    void DoAction();
    bool IsMouseInStone();

private:
    bool m_isDrawing;  // 선을 그리고 있니?
    Vec2 m_startPos;   // 선의 시작 위치
    Vec2 m_endPos;     // 선의 끝 위치(마우스의 위치)


};
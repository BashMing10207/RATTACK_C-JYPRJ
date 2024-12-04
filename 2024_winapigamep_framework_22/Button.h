#pragma once
#include "UI.h"
class Button :
	public UI
{
public:
	// UI을(를) 통해 상속됨
	void Update() override;
	void Test();
	void Render(HDC _hdc) override;
	void DrawUI(HDC _hdc) override;
	bool IsMouseHover();	//마우스가 Ui 위에 있는지
	bool IsMouseUp();		//UI가 눌린게 끝났는지
	bool IsMouseDown();		//UI를 누르기 시작했는지
	bool IsMouseHold();		//UI를 누르고 있는지

	bool IsMouseAction(KEY_STATE _state);
public:
	void SetClicked(bool _isClicked) { m_isClick = _isClicked; }
	void SetHover(bool _isHover) { m_isHover = _isHover; }
	const bool& GetClicked() const { return m_isClick; }
	const bool& GetHovered() const { return m_isHover; }

	// UI을(를) 통해 상속됨
	void Init() override;
	void RenderText(HDC _hdc) override;

private:
	bool m_isClick;
	bool m_isHover;
	SIZE textSize;
};
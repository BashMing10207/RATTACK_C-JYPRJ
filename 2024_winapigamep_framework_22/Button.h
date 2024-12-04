#pragma once
#include "UI.h"
class Button :
	public UI
{
public:
	// UI��(��) ���� ��ӵ�
	void Update() override;
	void Test();
	void Render(HDC _hdc) override;
	void DrawUI(HDC _hdc) override;
	bool IsMouseHover();	//���콺�� Ui ���� �ִ���
	bool IsMouseUp();		//UI�� ������ ��������
	bool IsMouseDown();		//UI�� ������ �����ߴ���
	bool IsMouseHold();		//UI�� ������ �ִ���

	bool IsMouseAction(KEY_STATE _state);
public:
	void SetClicked(bool _isClicked) { m_isClick = _isClicked; }
	void SetHover(bool _isHover) { m_isHover = _isHover; }
	const bool& GetClicked() const { return m_isClick; }
	const bool& GetHovered() const { return m_isHover; }

	// UI��(��) ���� ��ӵ�
	void Init() override;
	void RenderText(HDC _hdc) override;

private:
	bool m_isClick;
	bool m_isHover;
	SIZE textSize;
};
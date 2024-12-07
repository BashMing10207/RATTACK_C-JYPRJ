#pragma once
#include "InputManager.h"
class UI
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC _hdc) abstract;
	virtual void RenderText(HDC _hdc) abstract;
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetPosLerp(Vec2 targetPos, float moveTime);
	float Lerp(float a, float b, float t);
	void SetSize(Vec2 _vSize) { m_vSize = _vSize; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetSize() const { return m_vSize; }
public:
	void SetActive(bool _isActive) { m_isActive = _isActive; }
	const bool& GetActive() const { return m_isActive; }

	void SetText(wstring _text) { m_text = _text; }
	const wstring& GetText() { return m_text; }

	void SetParent(UI* parent) { m_parent = parent; }
	UI* GetParent() const { return m_parent; }

	void AddChild(UI* child) {
		if (child == nullptr || child == this) return; // 자기 자신 방지
		m_children.push_back(child);
		child->m_parent = this; // 자식의 부모 설정
	}
	void RemoveChild(UI* child) {
		auto it = std::find(m_children.begin(), m_children.end(), child);
		if (it != m_children.end()) {
			m_children.erase(it);
			child->m_parent = nullptr; // 부모 정보 제거
		}
	}

	const std::vector<UI*>& GetChildren() const { return m_children; }

protected:
	bool m_isActive;
	Vec2 m_vPos;
	Vec2 m_vSize;
	wstring m_text;

	Vec2 m_targetPos;   // 목표 위치
	float m_moveTime;    // 이동 시간
	float m_currentTime; // 경과 시간
	bool m_isMoveing; //움직이고있는 중인지
	bool m_isMoved; //다 움직였니?

	UI* m_parent;                // 부모 UI
	std::vector<UI*> m_children; // 자식 UI 리스트
};
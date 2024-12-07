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
		if (child == nullptr || child == this) return; // �ڱ� �ڽ� ����
		m_children.push_back(child);
		child->m_parent = this; // �ڽ��� �θ� ����
	}
	void RemoveChild(UI* child) {
		auto it = std::find(m_children.begin(), m_children.end(), child);
		if (it != m_children.end()) {
			m_children.erase(it);
			child->m_parent = nullptr; // �θ� ���� ����
		}
	}

	const std::vector<UI*>& GetChildren() const { return m_children; }

protected:
	bool m_isActive;
	Vec2 m_vPos;
	Vec2 m_vSize;
	wstring m_text;

	Vec2 m_targetPos;   // ��ǥ ��ġ
	float m_moveTime;    // �̵� �ð�
	float m_currentTime; // ��� �ð�
	bool m_isMoveing; //�����̰��ִ� ������
	bool m_isMoved; //�� ��������?

	UI* m_parent;                // �θ� UI
	std::vector<UI*> m_children; // �ڽ� UI ����Ʈ
};
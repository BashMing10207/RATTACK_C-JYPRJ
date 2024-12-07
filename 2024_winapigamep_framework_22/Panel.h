#pragma once
#include "UI.h"
#include "Texture.h"
#include "ResourceManager.h"
class Panel :
    public UI
{
public:
    Panel()
    {
        Init();
    }
    ~Panel();
public:
    // UI��(��) ���� ��ӵ�
    void Init() override;
    void Update() override;
    void Render(HDC _hdc) override;
    void RenderText(HDC _hdc) override;
    void RenderSelectedPanel(HDC _hdc);
    void RenderTexture(HDC _hdc);
    void RenderPanel(HDC _hdc);
    void SetTexture(wstring name, wstring _texture);
    void SetHasPanel(bool _isHas);
public:
    bool IsMouseHover();	//���콺�� Ui ���� �ִ���
    bool IsMouseUp();		//UI�� ������ ��������
    bool IsMouseDown();		//UI�� ������ �����ߴ���
    bool IsMouseHold();		//UI�� ������ �ִ���

    bool IsMouseAction(KEY_STATE _state);
public:
    void SetClicked(bool _isClicked) { m_isSelected = _isClicked; }
    void SetHover(bool _isHover) { m_isHover = _isHover; }
    const bool& GetClicked() const { return m_isSelected; }
    const bool& GetHovered() const { return m_isHover; }


private:
    bool m_isSelected;
    bool m_isHover;
    SIZE m_textSize;
    Texture* m_pTex;
    bool m_isTexture;
    bool m_hasPanel;

    Vec2 m_initPos;

};


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
    // UI을(를) 통해 상속됨
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
    bool IsMouseHover();	//마우스가 Ui 위에 있는지
    bool IsMouseUp();		//UI가 눌린게 끝났는지
    bool IsMouseDown();		//UI를 누르기 시작했는지
    bool IsMouseHold();		//UI를 누르고 있는지

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


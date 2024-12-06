#include "pch.h"
#include "BackGroundObject.h"
#include "ResourceManager.h"
BackGroundObject::BackGroundObject(wstring str,bool isTrans)
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(str, str);
	isTransfer = isTrans;
}

void BackGroundObject::Init()
{

}

void BackGroundObject::Update()
{
}

void BackGroundObject::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	//RECT_RENDER(_hdc, vPos.x, vPos.y
	//	, vSize.x, vSize.y);
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	//::BitBlt(_hdc
	//	, (int)(vPos.x - vSize.x / 2)
	//	, (int)(vPos.y - vSize.y / 2)
	//	, width, height,
	//	m_pTex->GetTexDC()
	//	,0,0,SRCCOPY
	//);
	if (isTransfer)
	{
		TransparentBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width, height,
			m_pTex->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	else
	{
		::BitBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width, height,
			m_pTex->GetTexDC(),
			0, 0, SRCCOPY);
	}

	ComponentRender(_hdc);
}

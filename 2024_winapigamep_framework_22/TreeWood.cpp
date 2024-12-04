#include "pch.h"
#include "TreeWood.h"
#include "Texture.h"
#include "ResourceManager.h"



void TreeWood::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Tree2", L"Texture\\Tree2.bmp");
}

void TreeWood::Render(HDC hdc)
{
	Vec2 vPos = GetPos();

	Vec2 vSize = GetSize();

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	::TransparentBlt(hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width, height,
		m_pTex->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));

	ComponentRender(hdc);
}

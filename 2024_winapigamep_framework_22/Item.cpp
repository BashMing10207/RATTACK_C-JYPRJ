#include "pch.h"
#include "Item.h"

Item::Item(ItemType a)
{
	_itemType = a;
}

void Item::Init()
{
}

void Item::Update()
{
}

void Item::Render(HDC hdc, Vec2 pos)
{
	switch (ItemType())
	{
	case Move:

		break;
	case Grenade:

		break;
	case OilGrenade:

		break;
	case ThrowMagnet:

		break;
	case Magnet:

		break;
	case Boom:

		break;
	case Potal:

		break;
	case Seed:

		break;
	case Joo:

		break;
	default:
		break;
	}
}

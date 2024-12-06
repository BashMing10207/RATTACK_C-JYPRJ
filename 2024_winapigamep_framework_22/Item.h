#pragma once
enum ItemType
{
	//Move,
	Move,
	Grenade,
	OilGrenade,
	ThrowMagnet,
	Magnet,
	Boom,
	Potal,
	Seed,
	Gun,
	Joo,
	End

};
struct Item
{
public:
	Item(ItemType);

	ItemType _itemType;

public:
	ItemType GetItemType() { return _itemType; }

public:
	void Init();
	void Update();
	void Render(HDC hdc, Vec2 pos);
};
#pragma once
enum ItemType
{
	None,
	Move,
	Grenade,
	OilGrenade,
	ThrowMagnet,
	Magnet,
	Boom,
	Potal,
	Seed,
	Joo,
	Gun,
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
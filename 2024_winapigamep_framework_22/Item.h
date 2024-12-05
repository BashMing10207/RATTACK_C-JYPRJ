#pragma once
enum ItemType
{
	Move,
	Grenade,
	OilGrenade,
	ThrowMagnet,
	Magnet,
	Boom,
	Potal,
	Seed,
	Joo

};
class Item
{
public:
	
public:

	ItemType _itemType;

protected:
	ItemType GetItemType() { return _itemType; }

public:
	void Init();
	void Update();
	void Render();
};
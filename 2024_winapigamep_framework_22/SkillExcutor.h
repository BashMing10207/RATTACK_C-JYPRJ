#pragma once
#include "Item.h"
#include "Component.h"
class SkillExcutor :
	public Component
{
	void Teleport(Vec2 direction);
public:
    void LateUpdate() override;
    void Render(HDC hdc) override;

    void GetAction(ItemType item,Vec2 direction);
    void Move(Vec2 direction);
    void Gun(Vec2 direction);
    void Grenade(Vec2 direction);
    void OilGrenade(Vec2 direction);
    void ThrowMagnet(Vec2 direction);
    void ThrowSeed(Vec2 direction);
    void Magnet(Vec2 direction);
    void ExplosionSkill(Vec2 direction);
    void JooMing(Vec2 direction);
    void BeWater(Vec2 direction);
    void Tetkkai(Vec2 direction);
};



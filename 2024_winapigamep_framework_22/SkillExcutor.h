#pragma once
#include "Item.h"
#include "Component.h"
class SkillExcutor :
    public Component
{
    void GetAction(Item item,Vec2 direction);
    void Move(Vec2 direction);
    void Gun(Vec2 direction);
    void Grenade(Vec2 direction);
    void OilGrenade(Vec2 direction);
    void ThrowMagnet(Vec2 direction);
    void ThrowSeed(Vec2 direction);
    void Magnet(Vec2 direction);
    void ExplosionSkill(Vec2 direction);
    void JooYoung(Vec2 direction);
    void BeWater(Vec2 direction);
    void Tetkkai(Vec2 direction);
};



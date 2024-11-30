#include "pch.h"
#include "RigidBody.h"
#include "Object.h"
#include "TimeManager.h"
#include "GDISelector.h"
UINT RigidBody::m_sNextID = 0;
RigidBody::RigidBody()
    :m_vSize(30.f, 30.f)
, m_vLatePos(0.f, 0.f)
, m_vOffsetPos(0.f, 0.f)
{
    velocity = Vec2(0, 0);
}

RigidBody::~RigidBody()
{
}


void RigidBody::LateUpdate()
{
    Vec2 pos = GetOwner()->GetPos();
    pos += velocity * fDT;
    GetOwner()->SetPos(pos);

    // 감속 처리
    velocity *= 1.f - min(max((float)fDT * friction, 0.f), 1.f);

    // 매우 작은 값 제거
    if (velocity.LengthSquared() < 0.001f) {
        velocity = Vec2(0.f, 0.f);
    }
}

void RigidBody::AddForce(Vec2 dir)
{
        //if (dir.x == NULL)
        //    return;
        //accelation = dir;//물리 적용
        velocity += dir;// 임시 물리
}

void RigidBody::Render(HDC _hdc)
{
}

void RigidBody::EnterCollision(Collider* _other)
{
}

void RigidBody::StayCollision(Collider* _other)
{
}

void RigidBody::ExitCollision(Collider* _other)
{
}


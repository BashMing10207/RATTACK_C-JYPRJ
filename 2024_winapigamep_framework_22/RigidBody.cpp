#include "pch.h"
#include "RigidBody.h"
#include "Object.h"
#include "TimeManager.h"
UINT RigidBody::m_sNextID = 0;
RigidBody::RigidBody() : m_vSize(30.f, 30.f)
, m_vLatePos(0.f, 0.f)
, m_vOffsetPos(0.f, 0.f)
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::LateUpdate()
{
	//°¨¼Ó
	velocity = Vec2::Lerpv(velocity,Vec2(0,0), fDT);
	
	GetOwner()->SetPos(velocity * fDT + GetOwner()->GetPos());
}

#include "DXUT.h"
#include "BossBullet.h"

BossBullet::BossBullet(Vector2 dir)
	: dir(dir), num(1)
{
}

	int BossBullet::Speed = 400;

void BossBullet::Init()
{

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);
}

void BossBullet::Update()
{
	collider->SetRange(vPos, 8, 8);
	vPos += dir * Speed * D_TIME;
}

void BossBullet::Render()
{
	//collider->Draw(255, 0, 0);
	IMAGE->FindImage("Boss_Bullet")->CenterRender(vPos, 0, Vector2(1.5, 1.5));
}

void BossBullet::Release()
{
	SAFE_DELETE(collider);
}

void BossBullet::onCollisionStay(Object* obj)
{
}

void BossBullet::onCollisionExit(Object* obj)
{
}

#include "DXUT.h"
#include "S_Enemy_Bullet.h"

int S_Enemy_Bullet::Speed = 325;

S_Enemy_Bullet::S_Enemy_Bullet(Vector2 dir)
	: dir(dir)
{
}
void S_Enemy_Bullet::Init()
{

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);
}

void S_Enemy_Bullet::Update()
{
	collider->SetRange(vPos, 5, 5);
	vPos += dir * Speed * D_TIME;
}

void S_Enemy_Bullet::Render()
{
	//collider->Draw(255, 0, 0);
	IMAGE->FindImage("S_Enemy_Bullet")->CenterRender(vPos, 0, Vector2(2, 2));
}

void S_Enemy_Bullet::Release()
{
	SAFE_DELETE(collider);
}

void S_Enemy_Bullet::onCollisionStay(Object* obj)
{
}

void S_Enemy_Bullet::onCollisionExit(Object* obj)
{
}

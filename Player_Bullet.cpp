#include "DXUT.h"
#include "Player_Bullet.h"

int Player_Bullet::Speed = 400;

void Player_Bullet::Init()
{

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);
}

void Player_Bullet::Update()
{
	collider->SetRange(vPos, 8,8);
	vPos.y -= Speed * D_TIME;
}

void Player_Bullet::Render()
{
	//collider->Draw(0, 255, 255);
	IMAGE->FindImage("Player_Bullet")->CenterRender(vPos, 0,Vector2(1.8,1.8));
}

void Player_Bullet::Release()
{
	SAFE_DELETE(collider);
}

void Player_Bullet::onCollisionStay(Object* obj)
{

}

void Player_Bullet::onCollisionExit(Object* obj)
{
}

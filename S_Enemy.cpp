#include "DXUT.h"
#include "S_Enemy.h"
#include "Player.h"
#include "S_Enemy_Bullet.h"

void S_Enemy::Init()
{
	Hp = 30;
	Speed = 80;

	ex_Index = 0;

	Enemy_Attack = new Timer;
	Enemy_Attack->setTimer(2);

	ex_Timer = new Timer;
	ex_Timer->setTimer(0.5);

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);

	explosion = IMAGE->ADDVECIMAGE("Boom", "Boom", 5);
}

void S_Enemy::Update()
{
	vPos.y += Speed * D_TIME;
	collider->SetRange(vPos, 30,30);
	if (Enemy_Attack->Update())
	{
		OBJECT->AddObject("S_Enemy_Bullet", new S_Enemy_Bullet({0,1}), Vector2(vPos.x, vPos.y + 10), ENEMY_BULLET);
	}
	if (Hp <= 0)
	{
		isDestroy = true;
		Player::Exp += 12;
		Player::PlayerScore += 50;
	}
	if (ex_Timer->Update())
	{
		ex_Index++;
		if (ex_Index >= 5)
		{
			ex_Index = 0;
		}
	}
}

void S_Enemy::Render()
{
	collider->Draw(255,0,100);
	IMAGE->FindImage("S_Enemy")->CenterRender(vPos, 0, Vector2(2, 2));

	if (Hp <= 0)
		explosion->FINDIMAGE(ex_Index)->CenterRender(vPos, 0, { 2,2 });
}

void S_Enemy::Release()
{
	SAFE_DELETE(Enemy_Attack);
	SAFE_DELETE(ex_Timer);
	SAFE_DELETE(collider);
}

void S_Enemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER_BULLET:
		Hp -= 10;
		obj->isDestroy = true;
		break;
	}
}

void S_Enemy::onCollisionExit(Object* obj)
{
}

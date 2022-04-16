#include "DXUT.h"
#include "M_Enemy.h"
#include "Player.h"
#include "S_Enemy_Bullet.h"

void M_Enemy::Init()
{
	Hp = 50;
	Speed = 150;

	ex_Index = 0;

	ex_Timer = new Timer;
	ex_Timer->setTimer(0.5);

	Enemy_Attack = new Timer;
	Enemy_Attack->setTimer(1);

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);

	explosion = IMAGE->ADDVECIMAGE("Boom", "Boom", 5);
}

void M_Enemy::Update()
{
	//if (ex_Timer->Update())
	//{
	//	ex_Index++;
	//	if (ex_Index >= 5)
	//	{
	//		ex_Index = 0;
	//	}
	//}
	vPos.y += Speed * D_TIME;
	collider->SetRange(vPos, 45, 30);

	if (Enemy_Attack->Update())
	{
		for (float i = -0.3; i < 0.3; i += 0.3)
			OBJECT->AddObject("S_Enemy_Bullet", new S_Enemy_Bullet(Vector2(i, 1)),vPos, ENEMY_BULLET);
	}

	if (ex_Timer->Update())
	{
}
			ex_Index++;
			if (ex_Index >= 5)
			{
				ex_Index = 0;
			}
		if (Hp <= 0)
		{
			Player::Exp += 20;
			Player::PlayerScore += 150;
			isDestroy = true;
		}
	}

void M_Enemy::Render()
{
	collider->Draw(255, 0, 100);
	IMAGE->FindImage("M_Enemy")->CenterRender(vPos, 0, Vector2(2, 2));

	if (Hp <= 0)
	{
		explosion->FINDIMAGE(ex_Index)->CenterRender(vPos, 0, { 2,2 });
	}
}

void M_Enemy::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(Enemy_Attack);
	SAFE_DELETE(ex_Timer);
}

void M_Enemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER_BULLET:
		Hp -= 10;
		obj->isDestroy = true;
		break;
	}
}

void M_Enemy::onCollisionExit(Object* obj)
{
}

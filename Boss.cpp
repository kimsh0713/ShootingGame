#include "DXUT.h"
#include "Boss.h"
#include "Stage.h"
#include "Player.h"
#include "BossBullet.h"
#include "S_Enemy_Bullet.h"

void Boss::Init()
{
	Attack = false;
	Anim_Index = 0;
	i = 1;
	Speed = 0;
	Count = 0;

	isMove = true;

	Hp = 10000;

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);

	Idle_Timer = new Timer;
	Idle_Timer->setTimer(0.15);

	Move_Timer = new Timer;
	Move_Timer->setTimer(2);

	Attack_Timer = new Timer;
	Attack_Timer->setTimer(5);

	Around_Attack = new Timer;
	Around_Attack->setTimer(4.5);

	Pattern_1_Timer = new Timer;
	Pattern_1_Timer->setTimer(0.1);

	srand(time(NULL));

	Idle = IMAGE->ADDVECIMAGE("Idle", "Boss",3);

	num = 1;
}

void Boss::Update()
{
	vPos.y += Speed * D_TIME;
	if (Idle_Timer->Update())
	{
		Anim_Index++;
		if (Anim_Index >= 3)
		{
			Anim_Index = 0;
		}
	}
	if (Move_Timer->Update())
	{
		if (Count <= 2)
			Count++;
	}
	if (Around_Attack->Update())
	{
		switch (i)
		{
		case 1:
			for (int i = 0; i <= 360; i += 5)
			{
				OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(cos(D3DXToRadian(i)), sin(D3DXToRadian(i)))), Vector2(vPos.x, vPos.y), ENEMY_BULLET);
			}
			i++;
			Around_Attack->setTimer(1.3);
			break;
		case 2:
			for (int i = 3; i <= 360; i += 5)
			{
				OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(cos(D3DXToRadian(i)), sin(D3DXToRadian(i)))), Vector2(vPos.x, vPos.y), ENEMY_BULLET);
			}
			i++;
			break;
		case 3:
			for (int i = 6; i <= 365; i += 5)
			{
				OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(cos(D3DXToRadian(i)), sin(D3DXToRadian(i)))), Vector2(vPos.x, vPos.y), ENEMY_BULLET);
			}
			i = 1;
			break;
		}
	}

	Vector2 Ppos = OBJECT->FindObject("Player")->vPos;
	Vector2 pos = Ppos - vPos;
	D3DXVec2Normalize(&pos, &pos);

	if (isMove == false)
	{
		if (Attack_Timer->Update())
		{
			num = rand() % 3;
			switch (num)
			{
			case 0:
				for (int i = 0; i < 5; i++)
				{
					BossPattern_1();
				}
				break;
			case 1:
				BossPattern_1();
				break;
			case 2:
				BossPattern_1();
				break;
			}
		}
	}


	{if (Count == 1)
		Speed = 100;
	if (Count == 2)
	{
		Speed = 0;
		isMove = false;
		collider->SetRange(vPos, 150, 160);
	}
	if (Hp <= 0)
	{
		isDestroy = true;
		S_Enemy_Bullet::Speed = 325;
		Stage::isSpawn = true;
	}
	}
}

void Boss::Render()
{
	collider->Draw(255, 0, 0);
	Idle->FINDIMAGE(Anim_Index)->CenterRender(vPos, 0, Vector2(2.5, 2.5));

	char HP[20];
	sprintf(HP, "HP : %d", Hp);
	IMAGE->drawText(HP, Vector2(vPos.x,vPos.y + 100), 20, D3DCOLOR_XRGB(255, 0, 0), true);
}

void Boss::Release()
{
	SAFE_DELETE(Idle_Timer);
	SAFE_DELETE(Move_Timer);
	SAFE_DELETE(Attack_Timer);
	SAFE_DELETE(Around_Attack);
	SAFE_DELETE(Pattern_1_Timer);
	SAFE_DELETE(collider);
}

void Boss::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER_BULLET:
		Hp -= Player::Damage;
		obj->isDestroy = true;
		break;
	}
}

void Boss::onCollisionExit(Object* obj)
{

}

void Boss::BossPattern_1()
{
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.075, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.05, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.025, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.025, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.05, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.075, 1)), Vector2(vPos.x - 40, vPos.y), ENEMY_BULLET);

	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.075, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.05, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0.025, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(0, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.025, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.05, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
	OBJECT->AddObject("Boss_Bullet", new BossBullet(Vector2(-0.075, 1)), Vector2(vPos.x + 40, vPos.y), ENEMY_BULLET);
}

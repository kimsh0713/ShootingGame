#include "DXUT.h"
#include "Player.h"
#include "Player_Bullet.h"
#include "Player_Homing.h"

float Player::Hp = 200;
float Player::MaxHp = 200;
float Player::Speed = 275;
float Player::Exp = 0;
float Player::MaxExp = 100;
int Player::Lv = 1;
int Player::Damage = 10;
int Player::PlayerScore = 0;

void Player::Init()
{
	Lv = 1;
	hp = IMAGE->FindImage("hp");
	exp = IMAGE->FindImage("exp");

	Attack_Timer = new Timer;
	Attack_Timer->setTimer(0.5);

	Homing_Bullet_Timer = new Timer;
	Homing_Bullet_Timer->setTimer(1);

	Score = new Timer;
	Score->setTimer(0.25);

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);
}

void Player::Update()
{
	if (Score->Update())
	{
		PlayerScore += 10;
	}

	collider->SetRange(vPos,12,12);
	if (INPUT->KeyPress('W') || INPUT->KeyPress(VK_UP))
	{
		vPos.y -= Speed * D_TIME;
		if (vPos.y <= 20)
			vPos.y += Speed * D_TIME;
	}
	if (INPUT->KeyPress('A') || INPUT->KeyPress(VK_LEFT))
	{
		vPos.x -= Speed * D_TIME;
		if (vPos.x <= 15)
			vPos.x += Speed * D_TIME;
	}
	if (INPUT->KeyPress('S') || INPUT->KeyPress(VK_DOWN))
	{
		vPos.y += Speed * D_TIME;
		if (vPos.y >= WINSIZEY - 20)
			vPos.y -= Speed * D_TIME;
	}
	if (INPUT->KeyPress('D') || INPUT->KeyPress(VK_RIGHT))
	{
		vPos.x += Speed * D_TIME;
		if(vPos.x >= WINSIZEX - 15)
			vPos.x -= Speed * D_TIME;
	}

	if (INPUT->KeyDown('K'))
	{
		Exp += 100;
	}

	if (Attack_Timer->Update())
	{
		switch (Lv)
		{
		case 1:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x, vPos.y - 10), PLAYER_BULLET);
			Damage = 10;
			break;
		case 2:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 4, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 4, vPos.y - 10), PLAYER_BULLET);
			Damage = 12;
			Attack_Timer->setTimer(0.35);
			break;
		case 3:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 6, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 6, vPos.y - 10), PLAYER_BULLET);
			Damage = 10;
			Attack_Timer->setTimer(0.3);
			Player_Bullet::Speed == 425;
			break;
		case 4:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 6, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 6, vPos.y - 10), PLAYER_BULLET);
			Damage = 12;
			Attack_Timer->setTimer(0.275);
			break;
		case 5:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 7, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 7, vPos.y - 10), PLAYER_BULLET);
			Damage = 12;
			Attack_Timer->setTimer(0.2);
			Speed = 300;
			break;
		case 6:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 7, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 7, vPos.y - 10), PLAYER_BULLET);

			Damage = 12;
			Attack_Timer->setTimer(0.2);
			Speed = 300;
			break;
		default:
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 7, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x - 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 3, vPos.y - 10), PLAYER_BULLET);
			OBJECT->AddObject("Player_Bullet", new Player_Bullet, Vector2(vPos.x + 7, vPos.y - 10), PLAYER_BULLET);
			Damage = 12;
			Attack_Timer->setTimer(0.2);
			Speed = 300;
			break;
		}
	}
		if (Homing_Bullet_Timer->Update())
		{
			if (Lv >= 5)
			{
				OBJECT->AddObject("Homing_Bullet", new Player_Homing, Vector2(vPos.x - 20, vPos.y+3), PLAYER_BULLET);
				OBJECT->AddObject("Homing_Bullet", new Player_Homing, Vector2(vPos.x + 20, vPos.y+3), PLAYER_BULLET);
			}
		}
	if (Hp <= 0)
	{
		//PostQuitMessage(0);
		SCENE->ChangeScene("GameOver");
	}
	if (Lv < 6)
	{
		if (Exp >= MaxExp)
		{
			Hp = 200;
			Exp = 0;
			Lv++;
			MaxExp += (MaxExp - (MaxExp / 2.3));
		}
	}
}

void Player::Render()
{
	IMAGE->FindImage("Player")->CenterRender(vPos, 0, Vector2(1.8, 1.8));

	hp->Render(Vector2(0, WINSIZEY - 18), 0, Vector2( Hp / MaxHp, 1), { -240,-6,240,6 });
	exp->Render(Vector2(0, WINSIZEY - 6), 0, Vector2( Exp / MaxExp, 1), { -240,-3,240,3 });

	collider->Draw(0, 255, 150);

	char HP[20];
	sprintf(HP, "HP : %.0f", Hp);
	IMAGE->drawText(HP, Vector2(WINSIZEX / 2, WINSIZEY - 28), 20, D3DCOLOR_XRGB(255, 255, 255), true);

	char SCORE[20];
	sprintf(SCORE, "Score:%d", PlayerScore);
	IMAGE->drawText(SCORE, Vector2(420, WINSIZEY - 28), 20, D3DCOLOR_XRGB(255, 255, 255), true);

	if (Lv < 6)
	{
		char LV[20];
		sprintf(LV, "Lv:%d", Lv);
		IMAGE->drawText(LV, Vector2(25, WINSIZEY - 28), 20, D3DCOLOR_XRGB(255, 255, 255), true);
	}
	else if(Lv >= 6)
	{
		char LV[20];
		sprintf(LV, "Lv:Max");
		IMAGE->drawText(LV, Vector2(33, WINSIZEY - 28), 20, D3DCOLOR_XRGB(255, 255, 255), true);
	}
}

void Player::Release()
{
	SAFE_DELETE(Attack_Timer);
	SAFE_DELETE(Homing_Bullet_Timer);
	SAFE_DELETE(Score);
	SAFE_DELETE(collider);
}

void Player::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case ENEMY_BULLET:
		Hp -= 10;
		obj->isDestroy = true;
		break;
	case BOSS:
		Hp -= 1;
		break;
	}
}

void Player::onCollisionExit(Object* obj)
{
}

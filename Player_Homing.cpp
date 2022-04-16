#include "DXUT.h"
#include "Player_Homing.h"
#include "Player.h"
#include "Object.h"

int Player_Homing::Damage = 1000;

void Player_Homing::Init()
{
	Speed = 700;
	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollsion(collider);
}

void Player_Homing::Update()
{
	map<int, Object*> m;

	//(*m.begin()).second(make_pair(,));

	collider->SetRange(vPos, 10, 10);
	if (OBJECT->ObjList[ENEMY].size() == 0)
	{
		vPos.y -= Speed * D_TIME;
	}
	if (OBJECT->ObjList[ENEMY].size() > 0)
	{
		Object* temp = OBJECT->ObjList[ENEMY].front();
		Vector2 pos = temp->vPos - vPos;
		D3DXVec2Normalize(&pos, &pos);
		vPos += pos * Speed * D_TIME;
	}

	//for (auto iter : OBJECT->ObjList[ENEMY])
	//{
	//	int length;
	//	length = D3DXVec2Length(&(vPos - iter->vPos));
	//}
}

void Player_Homing::Render()
{
	IMAGE->FindImage("Homing_Bullet")->CenterRender(vPos, 0, Vector2(1, 1));
}

void Player_Homing::Release()
{
	SAFE_DELETE(collider);
}

void Player_Homing::onCollisionStay(Object* obj)
{
}

void Player_Homing::onCollisionExit(Object* obj)
{
}

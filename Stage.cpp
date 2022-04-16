#include "DXUT.h"
#include "Stage.h"
#include "ScrollMap.h"
#include "Player.h"
#include "Player_Bullet.h"
#include "S_Enemy.h"
#include "M_Enemy.h"
#include "Boss.h"
#include "Mouse.h"

bool Stage::isSpawn = true;
bool Stage::isBoss = false;

void Stage::Init()
{
	Map = new ScrollMap;
	srand(time(NULL));

	Enemy_Count = 0;

	Enemy_Spawn = new Timer; 
	Enemy_Spawn->setTimer(2.5);

	OBJECT->AddObject("Player", new Player, Vector2(WINSIZEX / 2, 600), PLAYER);
	//OBJECT->AddObject("Boss", new Boss, Vector2(WINSIZEX / 2, -100), BOSS);
}

void Stage::Update()
{
	if (Player::Lv >= 3)
	{
		Enemy_Spawn->setTimer(1.5);
	}
	if (Enemy_Spawn->Update())
	{
		if (isSpawn)
		{
			int SpawnPoint = ((rand() % 460));
			if (SpawnPoint <= 30)
				SpawnPoint += 30;

			int num = (rand() % 2);
			if (num == 0)
				OBJECT->AddObject("S_Enemy", new S_Enemy, Vector2(SpawnPoint, -20), ENEMY);
			if(num == 1)
				OBJECT->AddObject("M_Enemy", new M_Enemy, Vector2(SpawnPoint, -20), ENEMY);
			Enemy_Count++;
		}
	}
	if (Player::Lv >= 5)
	{
		if (isBoss == false)
		{
			OBJECT->AddObject("Boss", new Boss, Vector2(WINSIZEX / 2, -100), BOSS);
			isBoss = true;
			isSpawn = false;
		}
	}
	Map->Update(40);
}

void Stage::Render()
{
	Map->Render();
}

void Stage::Release()
{
	SAFE_DELETE(Map);
	SAFE_DELETE(Enemy_Spawn);
}

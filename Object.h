#pragma once
#include "Collider.h"

enum ObjectTag :char
{
	NONE,				// 1
	UI,					// 2
	MOUSE,				// 3
	PLAYER,				// 4
	PLAYER_BULLET,		// 5
	ENEMY,				// 6
	ENEMY_BULLET,		// 7
	BOSS,				// 8
	MAP,				// 9
	END,				// 10
}typedef Tag;

class Object
{
public:
	Object();
	virtual ~Object();

	Vector2 vPos = {0,0};
	Collider* collider = nullptr;
	Collider* collider2 = nullptr;
	Collider* collider3 = nullptr;
	Collider* collider4 = nullptr;
	Collider* collider5 = nullptr;
	Tag m_Tag;
	string m_Key;
	texture * image = nullptr;


	bool isDestroy = false;

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void onCollisionStay(Object* obj) PURE;
	virtual void onCollisionExit(Object* obj) PURE;

	bool CheckDestroy() { return isDestroy; }
};


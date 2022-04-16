#include "DXUT.h"
#include "GameOver.h"

void GameOver::Init()
{
	img = IMAGE->FindImage("Background");
	img2 = IMAGE->FindImage("GAMEOVER");
}

void GameOver::Update()
{
}

void GameOver::Render()
{
	img->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, {2,2});
	img2->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 - 200));
}

void GameOver::Release()
{
}

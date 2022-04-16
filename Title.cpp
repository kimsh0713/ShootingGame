#include "DXUT.h"
#include "Title.h"
#include "Mouse.h"

void Title::Init()
{
	img = IMAGE->FindImage("Title");

	OBJECT->AddObject("MousePoint", new Mouse, Vector2(0, 0), MOUSE);
}

void Title::Update()
{
	if (INPUT->KeyDown(VK_SPACE))
	{
		SCENE->ChangeScene("Stage");
	}
}

void Title::Render()
{
	img->CenterRender(Vector2(WINSIZEX / 2,WINSIZEY / 2));

	char A[20];
	sprintf(A, "Push Space");
	IMAGE->drawText(A,Vector2(WINSIZEX / 2, WINSIZEY - 40), 30, D3DCOLOR_XRGB(255, 255, 255), true);
}

void Title::Release()
{
}

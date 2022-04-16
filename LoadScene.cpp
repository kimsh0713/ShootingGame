#include "DXUT.h"
#include "LoadScene.h"
#include "Mouse.h"
#define maxcount 1

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::Init()
{
	CAMERA->Reset();

	OBJECT->AddObject("MousePoint", new Mouse, Vector2(0,0),MOUSE);

#pragma region FirstLoading // 로딩씬 리소스 로딩
#pragma endregion
	//이미지 로드 
#pragma region SecondLoading // 게임 리소스 로딩
	ImageLoad("MousePoint", "Ui/Mouse");
	ImageLoad("Player", "Player/Idle");
	ImageLoad("Player_Bullet", "Bullet/P_Bullet");
	ImageLoad("Homing_Bullet", "Bullet/P_Homing");
	ImageLoad("S_Enemy", "Enemy/S_Enemy/Enemy");
	ImageLoad("M_Enemy", "Enemy/M_Enemy/Enemy");
	ImageLoad("S_Enemy_Bullet", "Bullet/E_Bullet");
	ImageLoad("Boss_Bullet", "Bullet/B_Bullet");
	ImageLoad("Background", "BackGround/Bg");
	ImageLoad("GAMEOVER", "BackGround/GameOver");
	ImageLoad("Title", "BackGround/Title");
	ImageLoad("hp", "Ui/hp");
	ImageLoad("exp", "Ui/exp");
#pragma endregion
}

void LoadScene::Update()
{


	if (!Imagelist.empty())
	{
		auto info = Imagelist.front();
		IMAGE->AddImage(info.m_Key, info.m_Path);
		Imagelist.pop_front();
		ImageCount++;
	}
	if (!Anilist.empty())
	{
		auto info = Anilist.front();
		IMAGE->ADDVECIMAGE(info.m_Key, info.m_Path, info.m_Size);
		Anilist.pop_front();
		ImageCount++;
	}
	if (Anilist.empty() && Imagelist.empty())
	{
		SCENE->ChangeScene("Title"); //로딩 끝났을때 하는 행동
		//PostQuitMessage(0);
	}

}

void LoadScene::Render()
{
	//IMAGE->FindImage("LoadingBar")->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, Vector2(ImageCount / maxImageCount, 1));
}

void LoadScene::Release()
{
}

void LoadScene::ImageLoad(const string & _Key, const string & _Path, int size)
{
	if (size == 0)
	{
		Imagelist.push_back(Load(_Key, _Path));
		maxImageCount++;
	}
	else
	{
		Anilist.push_back(Load(_Key, _Path, size));
		maxImageCount++;
	}
}

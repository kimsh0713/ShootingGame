#pragma once
class ScrollMap
{
public:
	ScrollMap();
	virtual ~ScrollMap();
	texture* Bg;

	float scroll;
	void Update(float speed);
	void Render();
};
	//int num;


	//texture* Bg2;
	//texture* Bg3;
	//texture* Bg4;
	//texture* Bg5;

	//float scroll2;
	//float scroll3;
	//float scroll4;
	//float scroll5;
#include "DXUT.h"
#include "Collider.h"


Collider::Collider()
{
}


Collider::~Collider()
{
}

void Collider::Init()
{

}

void Collider::SetRange(Vector2 pos,float width, float height)
{
	left = pos.x - width / 2;
	right = pos.x + width / 2;
	top = pos.y - height / 2;
	bottom = pos.y + height / 2;
}

void Collider::Draw(char r, char g, char b)
{
    LPD3DXLINE line;

    D3DXCreateLine(g_device, &line);

    line->SetWidth(1);
    line->SetAntialias(true);
    line->Begin();

    Vector2* ver = new Vector2[5];
    ver[0] = Vector2((float)right, (float)top);
    ver[1] = Vector2((float)right, (float)bottom);
    ver[2] = Vector2((float)left, (float)bottom);
    ver[3] = Vector2((float)left, (float)top);
    ver[4] = Vector2((float)right, (float)top);

    line->Draw(ver, 5, D3DCOLOR_XRGB(r, g, b));

    SAFE_DELETE_ARRAY(ver);

    line->End();
    line->OnLostDevice();
    line->Release();
}

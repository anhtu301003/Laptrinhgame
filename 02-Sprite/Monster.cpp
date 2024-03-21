#include "Game.h"
#include "Mario.h"

CMonster::CMonster(float x, float y, float vx) :CGameObject(x, y)
{
	this->vx = vx;
};

void CMonster::Update(DWORD dt)
{
	x += vx * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MONSTER_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MONSTER_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

void CMonster::Render()
{
	LPANIMATION ani;

	if (vx > 0) ani = CAnimations::GetInstance()->Get(520);
	else ani = CAnimations::GetInstance()->Get(501);

	ani->Render(x, y);
}

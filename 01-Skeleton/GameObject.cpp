#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

/*
	Initialize game object 
*/
CGameObject::CGameObject(float x, float y, LPTEXTURE tex)
{
	this->x = x;
	this->y = y;
	this->texture = tex;
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}

CGameObject::~CGameObject()
{
	if (texture != NULL) delete texture;
}

#define MARIO_VX 0.1f
#define MARIO_WIDTH 14
#define BRICK_VX 0.1f
#define BRICK_WIDTH 14

void CMario::Update(DWORD dt)
{
	x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {
		
		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

void CBrick::Update(DWORD dt)
{
	y += vy*dt;
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();
	if (y <= 0 || y >= BackBufferHeight - BRICK_WIDTH) {

		vy = -vy;

		if (y <= 0)
		{
			y = 0;
		}
		else if (y >= BackBufferHeight - BRICK_WIDTH)
		{
			y = (float)(BackBufferHeight - BRICK_WIDTH);
		}
	}
}

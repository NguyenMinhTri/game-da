#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
class CSprite
{
private:
	// Variables
	LPD3DXSPRITE m_spriteHandler;
	D3DXIMAGE_INFO m_info;
	LPDIRECT3DTEXTURE9 m_texture;
public:
	// constructors & destructor
	CSprite(void);
	~CSprite(void);
	CSprite(LPDIRECT3DDEVICE9 d3ddev, char* fileName, D3DCOLOR color);
	// Methods
	void Render(float fX, float fY);
	void Render(float fX, float fY, D3DCOLOR color);
	void Render(float fX, float fY, RECT rect, D3DCOLOR color);
	void Render(float fX, float fY, RECT rect, D3DCOLOR color, float rotate);
	void Render(float fX, float fY, RECT rect, D3DCOLOR color, float rotate, float Xscaling, float yScaling);
};
//////////////////////////////////////////////////////////////////////////
// Sprites' Collection
//////////////////////////////////////////////////////////////////////////
class AllSprite
{
public:

	// Constructors
	AllSprite(LPDIRECT3DDEVICE9 d3ddev)
	{
		// load all sprites in here
	}
};


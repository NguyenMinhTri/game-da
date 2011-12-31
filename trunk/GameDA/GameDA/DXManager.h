#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include "Sprite.h"
class CDXManager
{
public:
	// variables
	LPDIRECT3D9 m_d3d;
	LPDIRECT3DDEVICE9 m_d3ddev;
	IDirect3DSurface9 *m_backBuffer;
	// constructors & destructor
	CDXManager(void);
	~CDXManager(void);
	// Methods
	bool Init(HWND hWnd);
	void BeginDraw();
	void EndDraw();
	void ClearScreen();
	void ReleaseDevice();
	IDirect3DSurface9* CreateSurfaceFromFile(char* fileName);
	CSprite* CreateSpriteFromFile(char* fileName, D3DCOLOR color);
	void ShowSurface(IDirect3DSurface9* surface,const RECT* sourceRect,const RECT* destinationRect);
};


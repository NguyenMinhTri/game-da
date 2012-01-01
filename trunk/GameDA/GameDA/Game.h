#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <stdlib.h>
#include "Information.h"
#include "DXManager.h"
#include "SoundPlayer.h"
#include "Input.h"
#include "Sprite.h"
#include "Camera.h"
#include "GObject.h"
#include "Position.h"
class CGame
{
public:
	// Variables
	HWND m_hWnd;
	ID3DXFont* m_font;
	CInput* m_input;
	CDXManager* m_dxManager;
	char m_keys[256];
	char m_lastKey[256];
	UINT64 m_currentTime;
	UINT64 m_lastTime;
	char m_fps[30];
	int m_frame;
	// Constructors & Destructor
	CGame(void);
	~CGame(void);
	CGame(HINSTANCE hInst);
	//////////////////////////////////////////////////////////////////////////
	/////							WINDOW								//////
	//////////////////////////////////////////////////////////////////////////
	bool InitWindow(HINSTANCE hInst);
	static LRESULT CALLBACK WinProc(HWND, UINT, LPARAM, WPARAM);
	void ShowWin();
	//////////////////////////////////////////////////////////////////////////
	/////							GAME								//////
	//////////////////////////////////////////////////////////////////////////
	void InitObject();
	int GameInit(HINSTANCE);
	void GameRun();
	void Render();
	void Update();
	void UpdateGamePlay();
	void RenderGamePlay();
	void RenderDeath();
	void CreateText(char* s);
};


#include "Game.h"

#pragma region Constructors & Destructor
//////////////////////////////////////////////////////////////////////////
CGame::CGame(void)
{
}
//////////////////////////////////////////////////////////////////////////
CGame::~CGame(void)
{
}
//////////////////////////////////////////////////////////////////////////
CGame::CGame(HINSTANCE hInst)
{
	m_dxManager = new CDXManager();
	m_input = new CInput(m_hWnd,hInst);
	m_frame = 0;
	m_lastTime = 0;
	m_currentTime = 0;
}
#pragma endregion 

#pragma region Methods
//////////////////////////////////////////////////////////////////////////
//////////////////////		 WINDOW		//////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// Init Window
//////////////////////////////////////////////////////////////////////////
bool CGame::InitWindow(HINSTANCE hInst)
{
	// Register window
	WNDCLASSEX wc;
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	/*wc.hIcon = LoadIcon(hInst,(LPCTSTR)IDI_ICON1);*/
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = m_hInst;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.lpszClassName = "Prinny";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	if(!RegisterClassEx(&wc))
	{
		return false;
	}
	// Init Window
	m_hWnd = CreateWindow("Prinny",
						  "Prinny",
						   WS_OVERLAPPEDWINDOW,
						   CW_USEDEFAULT,
						   CW_USEDEFAULT,
						   GAME_WIDTH,
						   GAME_HEIGHT,
						   NULL,
						   NULL,
						   hInst,
						   NULL);
	if(m_hWnd == NULL)
	{
		return false;
	}
	// Show Window
	ShowWindow(m_hWnd,SW_SHOW);
	UpdateWindow(m_hWnd);
	return true;
}
//////////////////////////////////////////////////////////////////////////
/// Process window event
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CGame::WinProc(HWND hWnd, UINT msg, LPARAM lParam, WPARAM wParam)
{
	switch(msg)
	{
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_ESCAPE:
			int e = MessageBox(NULL,"Quit program ?","",MB_YESNO | MB_ICONQUESTION);
			if(e==IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		}
		return 0;
	case WM_QUIT:
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:
		//m_dxManager->ReleaseDevice();
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////		 Game		//////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// Init Objects
//////////////////////////////////////////////////////////////////////////
void CGame::InitObject()
{

}
//////////////////////////////////////////////////////////////////////////
/// Game Initialization
//////////////////////////////////////////////////////////////////////////
int CGame::GameInit(HINSTANCE hInst)
{
	if(!InitWindow(hInst))
	{
		MessageBox(m_hWnd,"Cannot initialize window","Error",MB_OK | MB_ICONERROR);
		return 0;
	}
	if(!m_dxManager->Init(m_hWnd))
	{
		MessageBox(m_hWnd,"Cannot initialize DirectX","Error",MB_OK | MB_ICONERROR);
		return 0;
	}
	return 1;
}
//////////////////////////////////////////////////////////////////////////
/// Run Game
//////////////////////////////////////////////////////////////////////////
void CGame::GameRun()
{
	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));
	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			m_currentTime = GetTickCount();
			if(m_currentTime - m_lastTime > 14)
			{
				Update();
				m_dxManager->ClearScreen();
				m_dxManager->BeginDraw();
				Render();
				if(m_frame == 10)
				{
					float temp = (float)(1000/(m_currentTime - m_lastTime));
					sprintf(m_fps,"%s%d","FPS: ",temp);
					m_frame = 0;
				}
				m_frame++;
				CreateText(m_fps);
				m_dxManager->EndDraw();
				m_lastTime = m_currentTime;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
/// Render images, sprites,etc
//////////////////////////////////////////////////////////////////////////
void CGame::Render()
{

}
//////////////////////////////////////////////////////////////////////////
/// Update sprite, collisions, quad tree, images
//////////////////////////////////////////////////////////////////////////
void CGame::Update()
{

}
//////////////////////////////////////////////////////////////////////////
/// Update game play
//////////////////////////////////////////////////////////////////////////
void CGame::UpdateGamePlay()
{

}
//////////////////////////////////////////////////////////////////////////
/// Render game play
//////////////////////////////////////////////////////////////////////////
void CGame::RenderGamePlay()
{

}
//////////////////////////////////////////////////////////////////////////
/// Render images, sprites,etc
//////////////////////////////////////////////////////////////////////////
void CGame::RenderDeath()
{

}
//////////////////////////////////////////////////////////////////////////
/// Create a string in Window 
//////////////////////////////////////////////////////////////////////////
void CGame::CreateText(char* s)
{
	D3DXCreateFont(
		m_dxManager->m_d3ddev,
		20,
		0,
		FW_BOLD,
		0,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		TEXT("Arial"),
		&m_font);
	D3DCOLOR fontColor = D3DCOLOR_ARGB(255,255,255,255);
	// Create a rectangle indicate where on the screen it should be drawn
	RECT rect;
	rect.left = 2;
	rect.right = 450;
	rect.top = 10;
	rect.bottom = rect.top + 20;
	// Draw some text
	m_font->DrawTextA(NULL,s,-1,&rect,0,fontColor);
	
}
#pragma endregion 

#include "Input.h"

#pragma region Constructor & Destructor

CInput::CInput(void)
{
}


CInput::~CInput(void)
{
}

CInput::CInput(HWND hWnd, HINSTANCE hInst)
{
	m_input = NULL;
	m_keyboardDevice = NULL;
	// Init keyboard
	if(!InitKeyboard(hWnd,hInst))
	{
		MessageBox(hWnd,"Cannot initialize keyboard device","Error",MB_OK | MB_ICONERROR);
	}
	// Init mouse
	if(!InitMouse(hWnd,hInst))
	{
		MessageBox(hWnd,"Cannot initialize mouse device","Error",MB_OK | MB_ICONERROR);
	}
}

#pragma endregion

#pragma region Methods

bool CInput::InitKeyboard(HWND hWnd, HINSTANCE hInst)
{
	HRESULT result;
	LPDIRECTINPUT8 DI_Object;
	result = DirectInput8Create(hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&DI_Object,
		NULL);
	if(result != D3D_OK)
	{
		return false;
	}
	result = DI_Object->CreateDevice(
		GUID_SysKeyboard,
		&m_keyboard,
		NULL);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_keyboard->SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_keyboard->Acquire();
	if(result != D3D_OK)
	{
		return false;
	}
	return true;
}

bool CInput::InitMouse(HWND hWnd, HINSTANCE hInst)
{
	HRESULT result;
	LPDIRECTINPUT8 DI_Object;
	result = DirectInput8Create(hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&DI_Object,
		NULL);
	if(result != D3D_OK)
	{
		return false;
	}
	result = DI_Object->CreateDevice(
		GUID_SysMouse,
		&m_mouse,
		NULL);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_mouse->SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(result != D3D_OK)
	{
		return false;
	}
	result = m_mouse->Acquire();
	if(result != D3D_OK)
	{
		return false;
	}
	return true;
}

#pragma endregion 
#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <Windows.h>

class CInput
{
private:
	// private variables
	LPDIRECTINPUT m_input;
	LPDIRECTINPUTDEVICE8 m_keyboard;
	LPDIRECTINPUTDEVICE8 m_mouse;
	LPDIRECTINPUTDEVICE m_keyboardDevice;
public:
	// constructor & destructor
	CInput(void);
	~CInput(void);
	CInput(HWND hWnd, HINSTANCE hInst);
	// methods
	bool InitMouse(HWND hWnd, HINSTANCE hInst);
	bool InitKeyboard(HWND hWnd, HINSTANCE hInst);
};


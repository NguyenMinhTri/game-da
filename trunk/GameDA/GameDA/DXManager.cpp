#include "DXManager.h"

#pragma region Constructors & Destructor
//////////////////////////////////////////////////////////////////////////
CDXManager::CDXManager(void)
{
	m_d3d = NULL;
	m_d3ddev = NULL;
	m_backBuffer = NULL;
}
//////////////////////////////////////////////////////////////////////////
CDXManager::~CDXManager(void)
{
	ReleaseDevice();
}
//////////////////////////////////////////////////////////////////////////
#pragma endregion 

#pragma region Methods
//////////////////////////////////////////////////////////////////////////
/// Initialize devices
//////////////////////////////////////////////////////////////////////////
bool CDXManager::Init(HWND hWnd)
{
	HRESULT result;
	// Create Direct9
	Direct3DCreate9(D3D_SDK_VERSION);
	// Create D3DPP
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp,sizeof(d3dpp));
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;
	d3dpp.hDeviceWindow = hWnd;
	// Create Device
	if(FAILED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT,
								D3DDEVTYPE_REF,
								hWnd,
								D3DCREATE_HARDWARE_VERTEXPROCESSING,
								&d3dpp,
								&m_d3ddev)))
	{
		if(FAILED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT,
										D3DDEVTYPE_REF,
										hWnd,
										D3DCREATE_SOFTWARE_VERTEXPROCESSING,
										&d3dpp,
										&m_d3ddev)))
		{
			return false;
		}
	}
	m_d3ddev->GetBackBuffer(0,
		0,
		D3DBACKBUFFER_TYPE_MONO,
		&m_backBuffer);
	return true;
}
//////////////////////////////////////////////////////////////////////////
/// Release All Devices
//////////////////////////////////////////////////////////////////////////
void CDXManager::ReleaseDevice()
{
	// Release D3D
	if(m_d3d != NULL)
	{
		m_d3d->Release();
	}
	// Release DirectX Device
	if(m_d3ddev != NULL)
	{
		m_d3ddev->Release();
	}
}
//////////////////////////////////////////////////////////////////////////
/// Begin draw 
//////////////////////////////////////////////////////////////////////////
void CDXManager::BeginDraw()
{
	if(m_d3ddev == NULL)
	{
		return;
	}
	m_d3ddev->BeginScene();
}
//////////////////////////////////////////////////////////////////////////
/// End Draw
//////////////////////////////////////////////////////////////////////////
void CDXManager::EndDraw()
{
	m_d3ddev->EndScene();
	m_d3ddev->Present(NULL,NULL,NULL,NULL);
}
//////////////////////////////////////////////////////////////////////////
/// Clear Screen
//////////////////////////////////////////////////////////////////////////
void CDXManager::ClearScreen()
{
	m_d3ddev->Clear(0,
		NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(255,255,255),
		1.0f,
		0);
}
//////////////////////////////////////////////////////////////////////////
/// Create a surface from a specific file
//////////////////////////////////////////////////////////////////////////
IDirect3DSurface9* CDXManager::CreateSurfaceFromFile(char* fileName)
{
	HRESULT result;
	IDirect3DSurface9* surface;
	D3DXIMAGE_INFO info;
	result = D3DXGetImageInfoFromFile(fileName,&info);
	if(result != D3D_OK)
	{
		return NULL;
	}
	result = m_d3ddev->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if(result != D3D_OK)
	{
		return NULL;
	}
	result = D3DXLoadSurfaceFromFile(
		surface,
		NULL,
		NULL,
		fileName,
		NULL,
		D3DX_DEFAULT,
		D3DCOLOR_ARGB(255,255,255,255),
		NULL);
	if(result != D3D_OK)
	{
		return NULL;
	}
	return surface;
}
//////////////////////////////////////////////////////////////////////////
/// Show surface to screen
//////////////////////////////////////////////////////////////////////////
void CDXManager::ShowSurface(IDirect3DSurface9* surface,const RECT* sourceRect,const RECT* destinationRect)
{
	m_d3ddev->StretchRect(
		surface,
		sourceRect,
		m_backBuffer,
		destinationRect,
		D3DTEXF_NONE);
}
///////////////////////////////////////////////////////////////////////////
/// Create a sprite from a specific file
//////////////////////////////////////////////////////////////////////////
CSprite* CDXManager::CreateSpriteFromFile(char* fileName, D3DCOLOR color)
{
	CSprite* sprite = new CSprite(m_d3ddev,fileName,color);
	return sprite;
}
#pragma endregion 
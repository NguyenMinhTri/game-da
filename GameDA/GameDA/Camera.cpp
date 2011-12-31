#include "Camera.h"

#pragma region Constructors & Destructor

CCamera::CCamera(void)
{
	m_viewport.m_fX = 0;
	m_viewport.m_fY = 0;
	m_fScale = 1.0f;
}


CCamera::~CCamera(void)
{
}

CCamera::CCamera(float fX, float fY,float fWidth, float fHeight)
	:CGObject(fX, fY,fWidth,fHeight)
{
	m_fScale = 1.0f;
	m_viewport.m_fX = fX;
	m_viewport.m_fY = fY;
}
#pragma endregion 

#pragma region Methods

void CCamera::SetViewPort(float fX,float fY)
{
	m_viewport.m_fX = fX;
	m_viewport.m_fY = fY;
}

#pragma endregion 
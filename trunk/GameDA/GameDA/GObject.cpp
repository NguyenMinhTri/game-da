#include "GObject.h"


CGObject::CGObject(void)
{
	m_pos.m_fX = 0;
	m_pos.m_fY = 0;
	m_iHeight = 0;
	m_iWidth = 0;
}


CGObject::~CGObject(void)
{
}

CGObject::CGObject(float fX, float fY, float Width, float Height)
{
	m_iWidth = (int)Width;
	m_iHeight = (int)Height;
	m_pos.m_fX = fX;
	m_pos.m_fY = fY;
}
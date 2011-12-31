#include "Position.h"


CPosition::CPosition(void)
{
	this->m_fX = 0;
	this->m_fY = 0;
}


CPosition::~CPosition(void)
{
}

CPosition::CPosition(float fX, float fY)
{
	m_fY = fY;
	m_fX = fX;
}

CPosition CPosition::operator+(CPosition p)
{
	CPosition r;
	r.m_fX = this->m_fX + p.m_fX;
	r.m_fY = this->m_fY + p.m_fY;
	return r;
}

CPosition CPosition::operator-(CPosition p)
{
	CPosition r;
	r.m_fX = this->m_fX - p.m_fX;
	r.m_fY = this->m_fY - p.m_fY;
	return r;
}
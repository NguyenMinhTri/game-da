#pragma once
#include "Position.h"
class CGObject
{
public:
	// variables
	CPosition m_pos;
	int m_iWidth;
	int m_iHeight;
	// Constructors & Destructor
	CGObject(void);
	~CGObject(void);
	CGObject(float fX, float fY, float Width, float Height);
};


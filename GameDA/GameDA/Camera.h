#pragma once
#include "GObject.h"
#include "Position.h"
class CCamera : CGObject
{
public:
	// variables
	CPosition m_viewport;
	float m_fScale;
	// constructors & destructor
	CCamera(void);
	~CCamera(void);
	CCamera(float fX, float fY,float fWidth, float fHeight);

	// methods
	void SetViewPort(float fX,float fY);
};


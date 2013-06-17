#pragma once
#include "Screen.h"
#include "..\Object\TextureObject.h"

class MenuScreen : public Screen
{
public:
	MenuScreen(void);
	virtual ~MenuScreen(void);

	virtual void Update();
    virtual void Render();
    virtual void Reset();

private:
	TextureObject* m_pBackTexObj;
};


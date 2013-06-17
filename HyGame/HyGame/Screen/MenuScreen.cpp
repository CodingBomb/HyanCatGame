#include "MenuScreen.h"
#include "..\Tool\Pool\TexturePool.h"

MenuScreen::MenuScreen(void)
{
	m_pBackTexObj = TexturePool::Instance()->Get("Menu-Background");
}


MenuScreen::~MenuScreen(void)
{
}

void MenuScreen::Update()
{
}

void MenuScreen::Render()
{
	if(m_pBackTexObj)
		m_pBackTexObj->Render(0, 0);
}

void MenuScreen::Reset()
{
}

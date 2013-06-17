#include "GraphicsEngine.h"

template<> GraphicsEngine* Singleton<GraphicsEngine>::m_pInst = NULL;

GraphicsEngine::GraphicsEngine()
{
	m_pGameEngine = GameEngine::Instance();
	m_HDC = ::GetDC(m_pGameEngine->GethWnd());
}

GraphicsEngine::~GraphicsEngine()
{
	if (m_HDC)
	{
		::ReleaseDC(m_pGameEngine->GethWnd(), m_HDC);
	}
}

void GraphicsEngine::SetClipping(int x, int y, int w, int h)
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_SetClipping(x, y, w, h);
}

void GraphicsEngine::SetClipping()
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_SetClipping();
}

HDC GraphicsEngine::WindowDC()
{
	return m_HDC;
}

void GraphicsEngine::BeginScene()
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_BeginScene();
}

void GraphicsEngine::EndScene()
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_EndScene();
}

void GraphicsEngine::Clear(DWORD color)
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_Clear(color);
}

void GraphicsEngine::RenderLine(float x1,
								float y1,
								float x2,
								float y2,
								DWORD color,
								float z)
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_RenderLine(x1, y1, x2, y2, color, z);
}

void GraphicsEngine::RenderQuad(const hgeQuad *quad)
{
	if (!m_pGameEngine)
	{
		return;
	}
	m_pGameEngine->PresentEngine()->Gfx_RenderQuad(quad);
}
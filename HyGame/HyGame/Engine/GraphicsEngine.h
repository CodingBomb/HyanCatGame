#ifndef GRAPHICSENGINE_
#define GRAPHICSENGINE_

#include "..\Helper\Singleton.h"
#include "..\..\Libs\hge\include\hge.h"
#include "GameEngine.h"

class GraphicsEngine : public Singleton<GraphicsEngine>
{
    friend class Singleton<GraphicsEngine>;

public:
    GraphicsEngine();
    virtual ~GraphicsEngine();

    bool Initialize() { return false;}

public:
    void BeginScene();
    void EndScene();
    HDC WindowDC();
    void Clear(DWORD color);

    void RenderLine(float x1,
					float y1,
					float x2,
					float y2,
					DWORD color = 0xFFFFFFFF,
					float z = 0.5f);

    void SetClipping(int x, int y, int w, int h);
    void SetClipping();

    void RenderQuad(const hgeQuad *quad);

private:
    GameEngine* m_pGameEngine;
    HDC m_HDC;
};

#endif
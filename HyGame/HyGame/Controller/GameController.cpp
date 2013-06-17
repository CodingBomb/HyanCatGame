#include "GameController.h"
#include "..\Define.h"
#include "..\Engine\GraphicsEngine.h"
#include "..\Screen\MenuScreen.h"

GameController* Singleton<GameController>::m_pInst = NULL;

GameController::GameController(void)
{
}

GameController::~GameController(void)
{
}

void GameController::Start()
{
	pScreenEngine->Push(new MenuScreen);
}

bool GameController::Update()
{
    return pScreenEngine->Update();
}

bool GameController::Render()
{
    GraphicsEngine::Instance()->BeginScene();
    pScreenEngine->Render();
    GraphicsEngine::Instance()->EndScene();
    return true;
}

bool GameController::Initialize()
{
    return true;
}

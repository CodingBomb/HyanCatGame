#include "Define.h"
#include "Engine\GameEngine.h"
#include "Engine\ScreenEngine.h"
#include "Controller\GameController.h"
#include "..\Libs\tinyxml\tinyxml.h"
#include "Tool\XML\XMLList.h"
#include "Tool\XML\XMLTextureParse.h"
#include <Shlwapi.h>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "../libs/hge/lib/hge.lib")
#pragma comment(lib, "../libs/hge/lib/hgehelp.lib")

ScreenEngine *pScreenEngine = NULL;
GameController *pGameController = NULL;

void InitializeWindow(GameEngine* _pEngine);
void InitializeEngine();
void InitializeResource();

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameEngine* pEngine = GameEngine::Instance();
	InitializeWindow(pEngine);
	InitializeEngine();
	InitializeResource();

	if (pEngine->Initialize())
	{
		pGameController->Start();
		pEngine->Start();
	}
	else
	{
		MessageBox(NULL, "´°¿Ú´´½¨Ê§°Ü£¡", NULL, MB_OK);
	}


	return 0;
}

bool Update()
{
	return pGameController->Update();
}

bool Render()
{
	return pGameController->Render();
}

void InitializeWindow(GameEngine* _pEngine)
{
	_pEngine->State(Func_Frame, Update);
	_pEngine->State(Func_Render, Render);
	_pEngine->State(Attribute_Width, WINDOW_WIDTH);
	_pEngine->State(Attribute_Height, WINDOW_HEIGHT);
	_pEngine->State(Attribute_Fps, 60);
	_pEngine->State(Attribute_Title, _T("HyGameTest"));
	_pEngine->State(Attribute_LogPath, _T("HyGameTest.log"));
}

void InitializeEngine()
{
	pScreenEngine = ScreenEngine::Instance();
	pGameController = GameController::Instance();
	pScreenEngine->Initialize();
}

void InitializeResource()
{
	char filePath[MAX_PATH] = {0};
	::GetModuleFileNameA(0, filePath, MAX_PATH);
	::PathRemoveFileSpecA(filePath);
	::PathAppendA(filePath, "Config\\XML\\XMLList.xml");
	XMLList::Instance()->LoadXML(filePath);
	memset(filePath, 0, MAX_PATH);

	for (auto it = XMLList::Instance()->Begin();
		it != XMLList::Instance()->End();
		it++)
	{
		::GetModuleFileNameA(0, filePath, MAX_PATH);
		::PathRemoveFileSpecA(filePath);
		::PathAppendA(filePath, it->second->Path.c_str());
		if (it->first == "TextureResource")
		{
			XMLTextureParse::Instance()->LoadXML(filePath);
		}
	}
}
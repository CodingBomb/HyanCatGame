#ifndef TEXTUREENGINE_
#define TEXTUREENGINE_

#include <string>
#include "..\Helper\Singleton.h"
#include "GameEngine.h"

class TextureEngine : public Singleton<TextureEngine>
{
	friend class Singleton<TextureEngine>;

public:
	TextureEngine();
	virtual ~TextureEngine();

	bool Initialize() { return false; }

public:
	GameTexture Load(const std::string& path);

	GameTexture Create(float x, float y);

	int GetWidth(GameTexture tex);

	int GetHeight(GameTexture tex);

	void Release(GameTexture tex);

	DWORD* Lock(GameTexture tex,
				bool bReadOnly = true,
				int left = 0,
				int top = 0,
				int width = 0,
				int height = 0);
	void Unlock(GameTexture tex);

private:
	GameEngine* m_pGameEngine;
};


#endif
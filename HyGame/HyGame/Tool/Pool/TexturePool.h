#ifndef TEXTUREPOOL_
#define TEXTUREPOOL_

#include <map>
#include "..\..\Helper\Singleton.h"
#include "..\..\Object\TextureObject.h"
#include "..\XML\XMLTextureParse.h"

typedef std::map<std::string, TextureObject*> MapPool;

class TexturePool :	public Singleton <TexturePool>
{
	friend class Singleton <TexturePool>;
public:
	TexturePool(void);
	virtual ~TexturePool(void);

	bool Initialize();

    TextureObject* Get(const std::string& _strId);

    void Release();

private:
	XMLTextureParse* m_pXMLTexPar;
	MapPool m_Pool;
};

#endif
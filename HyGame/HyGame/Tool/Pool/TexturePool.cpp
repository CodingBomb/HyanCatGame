#include "TexturePool.h"


TexturePool* Singleton<TexturePool>::m_pInst = NULL;

TexturePool::TexturePool()
{
	for (auto it = XMLTextureParse::Instance()->Begin();
        it != XMLTextureParse::Instance()->End();
        it++)
    {
        TextureObject* pObject = new TextureObject;
		pObject->Load(it->second->TexturePath.c_str());
        m_Pool[it->first] = pObject;
    }
}

TexturePool::~TexturePool()
{
    Release();
}

bool TexturePool::Initialize()
{
    return false;
}

TextureObject* TexturePool::Get(const std::string& _strId)
{
    auto it = m_Pool.find(_strId);
    if (it != m_Pool.end())
    {
        return it->second;
    }
    return NULL;
}

void TexturePool::Release()
{
    for (auto it = m_Pool.begin();
        it != m_Pool.end();
        it++)
    {
        if (it->second)
        {
            delete it->second;
            it->second = NULL;
        }
    }
}

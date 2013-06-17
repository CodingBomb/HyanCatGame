#include "XMLTextureParse.h"

XMLTextureParse* Singleton<XMLTextureParse>::m_pInst = NULL;

XMLTextureParse::XMLTextureParse()
{
}

XMLTextureParse::~XMLTextureParse()
{
	_Close();
}

void XMLTextureParse::_Close()
{
	if (!m_mapPiture.empty())
	{
		for (auto it = m_mapPiture.begin(); it != m_mapPiture.end(); it++)
		{
			delete it->second;
		}
	}
}

int XMLTextureParse::Size() const
{
	return m_mapPiture.size();
}

bool XMLTextureParse::Empty() const
{
	return m_mapPiture.empty();
}

bool XMLTextureParse::LoadXML(const std::string& _strPath)
{
	TiXmlDocument XmlParse;

	if (_strPath.empty())
	{
		return false;
	}

	if (XmlParse.LoadFile(_strPath.c_str()))
	{
		return _Parse(XmlParse);
	}
	return true;
}

bool XMLTextureParse::_Parse(TiXmlDocument& _xmlDoc)
{
	TiXmlElement* tiRoot = _xmlDoc.RootElement();
	if (!tiRoot)
	{
		return false;
	}
	std::string sRootName = tiRoot->Value();
	if (sRootName != PICTURE_ROOT_GAME)
	{
		return false;
	}
	TiXmlNode* tiFirst = tiRoot->FirstChild(PICTURE_GAME);
	if (tiFirst == NULL)
	{
		return false;
	}

	for (TiXmlElement* tiPicture = tiFirst->ToElement();
		tiPicture != NULL;
		tiPicture = tiPicture->NextSiblingElement())//读取当下元素中的所有属性
	{
		XMLTextureObject* pPicture = new XMLTextureObject;
		if(Helper::GetXmlStrAttributeA(tiPicture, ID_OBJECT, pPicture->TextureId)
			&& Helper::GetXmlStrAttributeA(tiPicture, PICTURE_PATH, pPicture->TexturePath))
		{
			Helper::GetXmlIntAttribute(tiPicture, PICTURE_POSX, pPicture->Posx);
			Helper::GetXmlIntAttribute(tiPicture, PICTURE_POSY, pPicture->Posy);
			m_mapPiture[pPicture->TextureId] = pPicture;
		}
	}
	return true;
}


XMLTextureObject* XMLTextureParse::Get(std::string _nId) const
{
	auto it = m_mapPiture.find(_nId);
	if (it == m_mapPiture.end())
	{
		return NULL;
	}
	return it->second;
}

const MapPitureList::const_iterator XMLTextureParse::Begin() const
{
	return m_mapPiture.begin();
}

const MapPitureList::const_iterator XMLTextureParse::End() const
{
	return m_mapPiture.end();
}
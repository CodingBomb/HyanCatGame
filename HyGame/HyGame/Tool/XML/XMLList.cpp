#include "XMLList.h"
#include "XMLParseDef.h"

XMLList* Singleton<XMLList>::m_pInst = NULL;

XMLList::XMLList()
{
}

XMLList::~XMLList()
{
}

bool XMLList::Initialize()
{
    return true;
}

bool XMLList::LoadXML(const std::string& _strPath)
{
    TiXmlDocument XmlDoc;

    if (_strPath.empty())
    {
        return false;
    }

    if (XmlDoc.LoadFile(_strPath.c_str()))
    {
        return _Parse(XmlDoc);
    }
    return true;
}


bool XMLList::_Parse(TiXmlDocument& _xmlDoc)
{
    TiXmlElement* tiRoot = _xmlDoc.RootElement();
    if (!tiRoot)
    {
        return false;
    }
    std::string sRootName = tiRoot->Value();
    if (sRootName != XMLLIST_ROOT )
    {
        return false;
    }

    TiXmlNode * tiFirst = tiRoot->FirstChild(XMLLIST_XML);
    if(tiFirst == NULL)
    {
        return false;
    }
    for (TiXmlElement* indexElement = tiFirst->ToElement();
        indexElement != NULL;
        indexElement = indexElement->NextSiblingElement())
    {
        XMLFileObject* pXML = new XMLFileObject;
        if(Helper::GetXmlStrAttributeA(indexElement, ID_OBJECT, pXML->Id)
            && Helper::GetXmlStrAttributeA(indexElement, TYPE_OBJECT, pXML->Type)
            && Helper::GetXmlStrAttributeA(indexElement, XMLLIST_PATH, pXML->Path))
        {
            m_mapXMLList[pXML->Id] = pXML;
        }
    }
    return true;
}


const mapXMLList::const_iterator XMLList::Begin() const
{
    return m_mapXMLList.begin();
}

const mapXMLList::const_iterator XMLList::End() const
{
    return m_mapXMLList.end();
}

int XMLList::Size() const
{
    return m_mapXMLList.size();
}
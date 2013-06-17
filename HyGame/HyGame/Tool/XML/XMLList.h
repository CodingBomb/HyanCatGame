#ifndef XMLLIST_
#define XMLLIST_

#include <map>
#include "..\..\Helper\Singleton.h"
#include "..\..\Helper\Helper.h"
#include "..\..\..\Libs\tinyxml\tinyxml.h"
#include "XMLListDef.h"

typedef std::map<std::string, XMLFileObject*> mapXMLList;

class XMLList : public Singleton<XMLList>
{
    friend Singleton<XMLList>;

public:
    virtual ~XMLList();

    bool LoadXML(const std::string& _strPath);

    virtual bool Initialize();

    const mapXMLList::const_iterator Begin() const;

    const mapXMLList::const_iterator End() const;

    int Size() const;

private:
    XMLList();

    bool _Parse(TiXmlDocument& _xmlDoc);

    mapXMLList m_mapXMLList;
};

#endif
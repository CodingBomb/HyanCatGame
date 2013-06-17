#ifndef XMLTEXTUREPARSE_
#define XMLTEXTUREPARSE_

#include <map>
#include "XMLParseDef.h"
#include "XMLTextureDef.h"
#include "..\..\Helper\Singleton.h"
#include "..\..\Helper\Helper.h"
#include "..\..\..\Libs\tinyxml\tinyxml.h"

typedef std::map<std::string, XMLTextureObject*> MapPitureList;

class XMLTextureParse : public Singleton<XMLTextureParse>
{
    friend class Singleton<XMLTextureParse>;
public:
    ~XMLTextureParse();

    bool LoadXML(const std::string& _strPath);
    XMLTextureObject* Get(std::string _nId) const;

    const MapPitureList::const_iterator Begin() const;
    const MapPitureList::const_iterator End() const;

    int Size() const;
    bool Empty() const;

private:
    void _Close();
    bool _Parse(TiXmlDocument& _xmlDoc);
 
private:
    XMLTextureParse();
    XMLTextureParse( XMLTextureParse& );
    XMLTextureParse& operator = (XMLTextureParse&);

private:
    MapPitureList m_mapPiture;
};

#endif
#ifndef XMLTEXTUREDEF_
#define XMLTEXTUREDEF_

#include "XMLParseDef.h"
#include <map>


struct XMLTextureObject
{
    XMLTextureObject()
    {
        Posx = 0;
        Posy = 0;
    }
    std::string TextureId;
    std::string TexturePath;
    int Posx;
    int Posy;
};

#endif
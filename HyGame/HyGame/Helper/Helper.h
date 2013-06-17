#pragma once

#include <string>
#include <Windows.h>
#include "..\..\Libs\tinyxml\tinyxml.h"

namespace Helper
{
    bool GetXmlStrAttributeA( TiXmlElement *pElement, char *pName, std::string &strData );
    bool GetXmlIntAttribute( TiXmlElement *pElement, char *pName, int &nData );
    bool InstallFont(const std::string path);
    bool UninstallFont(const std::string path);
    void ErrorMessage(const std::string text);
}
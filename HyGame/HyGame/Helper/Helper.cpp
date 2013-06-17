#include "Helper.h"


namespace Helper
{

	bool Helper::GetXmlStrAttributeA( TiXmlElement *pElement, char *pName, std::string &strData )
	{
		if (pElement)
		{
			const char *pStr = pElement->Attribute(pName);
			if (pStr)
			{
				strData = std::string(pStr);
				return true;
			}
		}
		return false;
	}

	bool Helper::GetXmlIntAttribute( TiXmlElement *pElement, char *pName, int &nData )
	{
		if (pElement)
		{
			const char *pStr = pElement->Attribute(pName);
			if (pStr)
			{
				nData = atoi(pStr);
				return true;
			}
		}
		return false;
	}

	bool Helper::InstallFont(const std::string path)
	{
		return AddFontResource(path.c_str()) != 0;
	}
	
	bool Helper::UninstallFont(const std::string path)
	{
		return RemoveFontResource(path.c_str()) != 0;
	}

	void Helper::ErrorMessage(const std::string text)
	{
		MessageBox(NULL, text.c_str(), NULL, MB_OK);
	}

}
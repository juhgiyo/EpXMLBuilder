#ifndef __EP_XML_UTIL_H__
#define __EP_XML_UTIL_H__

#include "epl.h"
using namespace epl;
#include "epXMLValidateResult.h"

typedef enum _xmlSearchType{
	XML_SEARCH_TYPE_ALL=0,
	XML_SEARCH_TYPE_NODE,
	XML_SEARCH_TYPE_ATTRIBUTE,

}XMLSearchType;

typedef enum _validState{
	VALID_STATE_VALID=0,
	VALID_STATE_INVALID,
	VALID_STATE_WARNING,
}ValidState;

class XMLUtil{
public:
	static CString NodeFormat(CString nodeName, CString nodeValue);
	static CString AttrFormat(CString nodeName, CString nodeValue);
	static CString SearchKeyFormat(XMLSearchType searchType,CString name,CString value,bool isMatchCase,bool isMatchWholeWord);

	static CString ResultFormat(CString name, CString value,bool isNode, XMLValidateType type);
	static ValidState ValidateName(CString name,CString &retMessage,bool isNode=true,XNode* parentNode=NULL,XAttr *checkAttr=NULL);

	

};
#endif //__EP_XML_UTIL_H__
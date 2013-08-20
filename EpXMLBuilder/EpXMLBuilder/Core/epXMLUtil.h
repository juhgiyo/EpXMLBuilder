/*! 
@file epXMLUtil.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief XML Util Interface
@version 1.0

@section LICENSE

The MIT License (MIT)

Copyright (c) 2013 Woong Gyu La <juhgiyo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

@section DESCRIPTION

An Interface for the XML Util.

*/
#ifndef __EP_XML_SEARCH_RESULT_H__
#define __EP_XML_SEARCH_RESULT_H__

#include "epl.h"
using namespace epl;



struct XMLSearchResult{
	CString m_textString;

	bool m_isRoot;
	bool m_isNode;
	CString m_name;
	CString m_value;
	XNode *m_parentNode;
	XNode *m_node;
	XAttr *m_attr;
	HTREEITEM m_treeItem;
};
#endif //__EP_XML_SEARCH_RESULT_H__
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

	static bool IsWinService();
	static void SetIsWinService(bool isWinService);
	

	

};
#endif //__EP_XML_UTIL_H__
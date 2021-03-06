/*! 
XMLUtil for the EpXMLBuilder

The MIT License (MIT)

Copyright (c) 2012-2013 Woong Gyu La <juhgiyo@gmail.com>

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
*/
#include "stdafx.h"
#include "epXMLUtil.h"
#include "epXMLValidatorProperties.h"

using namespace epl;
bool g_isWinService=false;

bool XMLUtil::IsWinService()
{
	return g_isWinService;
}
void XMLUtil::SetIsWinService(bool isWinService)
{
	g_isWinService=isWinService;
}
CString XMLUtil::NodeFormat(CString nodeName, CString nodeValue)
{
	nodeName=nodeName.Trim();
	nodeValue=nodeValue.Trim();
	CString treeElemString=_T("< name = ");
	treeElemString.Append(nodeName);
	if(nodeValue.GetLength()>0)
	{
		treeElemString.AppendFormat(_T(" value = "));
		treeElemString.Append(nodeValue);
	}
	treeElemString.AppendFormat(_T(" >"));
	return treeElemString;

}




CString XMLUtil::AttrFormat(CString attrName, CString attrValue)
{
	attrName=attrName.Trim();
	attrValue=attrValue.Trim();
	CString treeElemString=_T("< attrName = ");
	treeElemString.Append(attrName);
	if(attrValue.GetLength()>0)
	{
		treeElemString.AppendFormat(_T(" value = "));
		treeElemString.Append(attrValue);
	}
	treeElemString.AppendFormat(_T(" >"));
	return treeElemString;
}

CString XMLUtil::SearchKeyFormat(XMLSearchType searchType,CString name,CString value,bool isMatchCase,bool isMatchWholeWord)
{
	CString retString=_T("Search finished! < ");

	retString.Append(_T("Type: "));
	switch(searchType)
	{
	case XML_SEARCH_TYPE_ALL:
		retString.Append(_T("All (Node + Attribute)"));
		break;
	case XML_SEARCH_TYPE_NODE:
		retString.Append(_T("Nodes Only"));
		break;
	case XML_SEARCH_TYPE_ATTRIBUTE:
		retString.Append(_T("Attributes Only"));
		break;
	}

	if(name.GetLength())
	{
		retString.Append(_T("  /  Name: "));
		retString.Append(name);
	}
	
	if(value.GetLength())
	{
		retString.Append(_T("  /  Value: "));
		retString.Append(value);
	}
	
	if(isMatchCase)
	{
		retString.Append(_T("  /  Match case"));
	}
	if(isMatchWholeWord)
	{
		retString.Append(_T("  /  Match whole word"));
	}
	retString.Append(_T(" >"));
	return retString;
}
CString XMLUtil::ResultFormat(CString name, CString value,bool isNode, XMLValidateType type)
{
	CString retString;
	if(isNode)
	{
		retString=NodeFormat(name,value);
	}
	else
	{
		retString=AttrFormat(name,value);
	}
	if(type==XML_VALIDATE_TYPE_ERROR)
	{
		retString=CString(_T("Error: "))+retString;
	}
	else
	{
		retString=CString(_T("Warning: "))+retString;
	}
	return retString;
}

ValidState XMLUtil::ValidateName(CString name,CString &retMessage,bool isNode,XNode* parentNode,XAttr *checkAttr)
{
	retMessage=_T("");
	CString errMessage,warningMessage;
	errMessage=_T("");
	warningMessage=_T("");

	ValidState retVal=VALID_STATE_VALID;
	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckNumber())
	{
		TCHAR firstLetter=name.GetAt(0);
		if(Locale::IsPunct(firstLetter)||Locale::IsDigit(firstLetter))
		{
			errMessage.Append(_T("- Name cannot start with a number or a punctuation.\n"));
			retVal= VALID_STATE_INVALID;
		}
	}

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckStartWithXML())
	{
		CString firstThreeWord=name;
		firstThreeWord.Delete(3,firstThreeWord.GetLength()-3);
		firstThreeWord=firstThreeWord.MakeLower();
		if(firstThreeWord.Compare(_T("xml"))==0)
		{
			errMessage.Append(_T("- Name cannot start with \"xml\".\n"));
			retVal= VALID_STATE_INVALID;
		}
	}
	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckContainSpace())
	{
		if(name.Find(_T(" "))!=-1)
		{
			errMessage.Append(_T("- Name cannot contain \"Space ( )\".\n"));
			retVal= VALID_STATE_INVALID;
		}

	}

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckDuplicate() && !isNode && parentNode)
	{
		for(XAttrs::iterator iter=parentNode->m_attrs.begin();iter!=parentNode->m_attrs.end();iter++)
		{
			if(checkAttr && (*iter)==checkAttr)
				continue;
			if((*iter)->m_name.Compare(name)==0)
			{
				errMessage.Append(_T("- A node cannot have attributes with same name.\n"));
				retVal= VALID_STATE_INVALID;
				break;
			}
		}
	}

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainDash())
	{
		if(name.Find(_T("-"))!=-1)
		{
			warningMessage.Append(_T("- Name should not contain \"Dash (-)\".\n"));
			if(retVal==VALID_STATE_VALID)
				retVal=VALID_STATE_WARNING;
		}
	}

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainPeriod())
	{
		if(name.Find(_T("."))!=-1)
		{
			warningMessage.Append(_T("- Name should not contain \"Period (.)\".\n"));
			if(retVal==VALID_STATE_VALID)
				retVal=VALID_STATE_WARNING;
		}
	}

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainColon())
	{
		if(name.Find(_T(":"))!=-1)
		{
			warningMessage.Append(_T("- Name should not contain \"Colon(:)\".\n"));
			if(retVal==VALID_STATE_VALID)
				retVal=VALID_STATE_WARNING;
		}
	}

	if(errMessage.GetLength())
	{
		retMessage.Append(_T("Validation failed due to following:\n\n"));
		retMessage.Append(errMessage);
		retMessage.Append(_T("\n"));
	}
	if(warningMessage.GetLength())
	{
		retMessage.Append(_T("Warnings:\n\n"));
		retMessage.Append(warningMessage);
		retMessage.Append(_T("\n"));
	}
	return retVal;
}
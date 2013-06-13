#include "stdafx.h"
#include "epPreTextParser.h"

bool PreTestParser::Parse(TextFile &file,NodeStringMap &map,NodeStringMap &attrMap)
 {
	 EpTString curLine;
	 size_t startLine=0;
	 CString curNode=_T("");
	 NodeStringMap::iterator iter=map.end();

	while(file.GetLine(file.GetText(),startLine,curLine,&startLine))
	{
		curLine=Locale::Trim(curLine);
		CString cCurLine=curLine.c_str();

		if(cCurLine.Find(_T("===="))!=-1)
			break;
		if(cCurLine.GetLength()<=0 || cCurLine.GetAt(0)==_T('#')) // comment
			continue;
		if(cCurLine.GetAt(0)==_T('>')) // value choice
		{
			if(curNode.Compare(_T(""))==0 || iter==map.end())
			{
				return false;
			}
			cCurLine.Delete(0,1);
			iter->second.push_back(cCurLine);
		}
		else
		{
			curNode=cCurLine;
			iter=map.find(curNode);
			if(iter==map.end())
			{
				map.insert(std::pair<CString,vector<CString> >(curNode,vector<CString>()));
				iter=map.find(curNode);
			}
		}
	}

	curNode=_T("");
	iter=attrMap.end();
	while(file.GetLine(file.GetText(),startLine,curLine,&startLine))
	{
		curLine=Locale::Trim(curLine);
		CString cCurLine=curLine.c_str();

		if(cCurLine.GetLength()<=0 || cCurLine.GetAt(0)==_T('#')) // comment
			continue;

		if(cCurLine.GetAt(0)==_T('>')) // value choice
		{
			if(curNode.Compare(_T(""))==0||iter==attrMap.end())
			{
				return false;
			}
			cCurLine.Delete(0,1);
			iter->second.push_back(cCurLine);
		}
		else
		{
			curNode=cCurLine;
			iter=attrMap.find(curNode);
			if(iter==map.end())
			{
				attrMap.insert(std::pair<CString,vector<CString> >(curNode,vector<CString>()));
				iter=attrMap.find(curNode);
			}
			
		}
	}
	return true;
 }


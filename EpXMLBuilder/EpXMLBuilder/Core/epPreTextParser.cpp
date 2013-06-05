#include "stdafx.h"
#include "epPreTextParser.h"

bool PreTestParser::Parse(TextFile &file,NodeStringMap &map)
 {
	 EpTString curLine;
	 size_t startLine=0;
	 CString curNode=_T("");
	 NodeStringMap::iterator iter=map.end();

	while(file.GetLine(file.GetText(),startLine,curLine,&startLine))
	{
		curLine=Locale::Trim(curLine);
		CString cCurLine=curLine.c_str();

		if(cCurLine.GetAt(0)==_T('>'))
		{
			if(curNode.Compare(_T(""))==0||iter==map.end())
			{
				return false;
			}
			cCurLine.Delete(0,1);
			iter->second.push_back(cCurLine);
		}
		else
		{
			curNode=cCurLine;
			map.insert(std::pair<CString,vector<CString> >(curNode,vector<CString>()));
			iter=map.find(curNode);
		}
	}
	return true;
 }
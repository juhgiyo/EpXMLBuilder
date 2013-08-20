/*! 
InitialCommandLineInfo for the EpXMLBuilder

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
#include "InitialCommandLineInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void InitialCommandLineInfo::ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast)
{
	if(0 == _tcscmp(pszParam, _T("winservice")))
	{
		m_isWinService = true;
	} 
// 	else if(0 == _tcscmp(pszParam, _T("norefresh")))
// 	{
// 		m_isRefresh = false;
// 	} 
// 	else if(0 == _tcscmp(pszParam, _T("e")))
// 	{
// 		m_bExport = TRUE;
// 	}
// 	else if(0 == _tcscmp(pszParam, _T("whatever")))
// 	{
// 		m_bWhatever = TRUE;
// 	}
}

#ifdef UNICODE
void InitialCommandLineInfo::ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
{
	if(0 == strcmp(pszParam, "winservice"))
	{
		m_isWinService = true;
	} 
// 	else if(0 == strcmp(pszParam, "norefresh"))
// 	{
// 		m_isRefresh = false;
// 	} 
}
#endif //UNICODE
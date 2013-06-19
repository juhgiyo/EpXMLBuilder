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
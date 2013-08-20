/*! 
CWinServiceCLIResultDlg for the EpXMLBuilder

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
#include "EpXMLBuilder.h"
#include "WinServiceCLIResultDlg.h"


// CWinServiceCLIResultDlg dialog

IMPLEMENT_DYNAMIC(CWinServiceCLIResultDlg, CDialog)

CWinServiceCLIResultDlg::CWinServiceCLIResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWinServiceCLIResultDlg::IDD, pParent)
{

}

CWinServiceCLIResultDlg::~CWinServiceCLIResultDlg()
{
}

void CWinServiceCLIResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_RESULT, m_tbResult);
}


BEGIN_MESSAGE_MAP(CWinServiceCLIResultDlg, CDialog)
	ON_BN_CLICKED(IDC_Export, &CWinServiceCLIResultDlg::OnBnClickedExport)
END_MESSAGE_MAP()


// CWinServiceCLIResultDlg message handlers
BOOL CWinServiceCLIResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	m_notifyWin.Create(this);
	m_notifyWin.SetSkin(IDB_BITMAP1);
	m_notifyWin.SetTextFont(_T("Arial"),90,TN_TEXT_NORMAL,TN_TEXT_UNDERLINE);
	m_notifyWin.SetTextColor(RGB(0,0,0),RGB(0,0,200));
	m_notifyWin.SetTextRect(CRect(10,40,m_notifyWin.m_nSkinWidth-10,m_notifyWin.m_nSkinHeight-25));

	XMLInfo info=XMLInfo::xmlDefault;
	info.m_isWriteComment=true;
	m_xmlFile=XMLFile(FILE_ENCODING_TYPE_UTF16LE,info);
	m_tbResult.SetWindowText(m_resultString.GetString());
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CWinServiceCLIResultDlg::OnBnClickedExport()
{
	// TODO: Add your control notification handler code here
	CString findString=_T("Building Result XML: Success");
	int findStringSize=findString.GetLength();
	CString tempResultString=m_resultString;
	int index=0;
	if((index=tempResultString.Find(findString))==-1)
	{
		MessageBox(_T("No result to export!"),_T("Error"),MB_OK);
		return;
	}
	tempResultString.Delete(0,index);
	tempResultString.Delete(0,findStringSize);
	
	SaveFileDialog saveFileDialog=SaveFileDialog(_T("xml"),_T("C:\\"),_T("XML Files (*.xml)|*.xml|All Files (*.*)|*.*||"),this);
	if(saveFileDialog.DoModal()!=IDCANCEL)
	{
		if(saveFileDialog.GetPathName().GetLength()<=0)
			return;
		
		m_xmlFile.Load(tempResultString.GetString());
		CString fileName=saveFileDialog.GetPathName();
		m_xmlFile.SaveToFile(fileName);
		m_notifyWin.Show(_T("XML is saved."));
	}
}

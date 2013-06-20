// WinServiceCLIResultDlg.cpp : implementation file
//

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

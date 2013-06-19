// XMLViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "XMLViewDlg.h"
#include "WinServiceCLIResultDlg.h"
#include "epXMLUtil.h"
#include "epl.h"
using namespace epl;

// CXMLViewDlg dialog

IMPLEMENT_DYNAMIC(CXMLViewDlg, CDialog)

CXMLViewDlg::CXMLViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXMLViewDlg::IDD, pParent)
{

}

CXMLViewDlg::~CXMLViewDlg()
{
}

void CXMLViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_tbXML);
	DDX_Control(pDX, IDC_CB_SINGLE, m_cbSingleLine);
	DDX_Control(pDX, IDC_BTN_WINSERVICE, m_btnWinServiceCLI);
}


BEGIN_MESSAGE_MAP(CXMLViewDlg, CDialog)
	ON_BN_CLICKED(IDC_CB_SINGLE, &CXMLViewDlg::OnBnClickedCbSingle)
	ON_BN_CLICKED(IDC_BTN_WINSERVICE, &CXMLViewDlg::OnBnClickedBtnWinservice)
END_MESSAGE_MAP()




// CXMLViewDlg message handlers
BOOL CXMLViewDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	if(XMLUtil::IsWinService())
		m_btnWinServiceCLI.ShowWindow(SW_SHOW);
	else
		m_btnWinServiceCLI.ShowWindow(SW_HIDE);

	m_tbXML.SetWindowText(m_xmlString.GetString());
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CXMLViewDlg::OnBnClickedCbSingle()
{
	// TODO: Add your control notification handler code here
	if(m_cbSingleLine.GetCheck()==BST_CHECKED)
	{
		m_tbXML.SetWindowText(m_xmlStringSingle.GetString());
		

	}
	else
	{
		m_tbXML.SetWindowText(m_xmlString.GetString());
	}
}

void CXMLViewDlg::OnBnClickedBtnWinservice()
{
	// TODO: Add your control notification handler code here
	CString path1=_T("EpWinServiceCLIU90.exe");
	CString path2=FolderHelper::GetModuleFileDirectory().c_str();
	path2.Append(path1);
	if(!FolderHelper::IsPathExist(path1.GetString()) &&
		!FolderHelper::IsPathExist(path2.GetString())
		)
	{
		MessageBox(_T("WinServiceCLI executable NOT exist!"),_T("Error"),MB_OK);
		return;
	}
	CString command=_T("EpWinServiceCLIU90.exe -xml \"");
	command.Append(m_xmlStringSingle);
	command.Append(_T("\""));
	EpTString result=ConsoleHelper::ExecuteConsoleCommand(command);
	CWinServiceCLIResultDlg winServiceDlg;
	CString cResultString=result.c_str();
	int idx=cResultString.Find(_T("EpWinServiceCLI: Started"));
	if(idx>=0)
	{
		cResultString.Delete(0,idx-1);
	}
	
	winServiceDlg.m_resultString=cResultString;
	winServiceDlg.DoModal();
}

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
END_MESSAGE_MAP()


// CWinServiceCLIResultDlg message handlers
BOOL CWinServiceCLIResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_tbResult.SetWindowText(m_resultString.GetString());
	return TRUE;  // return TRUE  unless you set the focus to a control
}
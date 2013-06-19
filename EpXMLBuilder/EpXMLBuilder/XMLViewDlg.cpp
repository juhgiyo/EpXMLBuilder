// XMLViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "XMLViewDlg.h"


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
}


BEGIN_MESSAGE_MAP(CXMLViewDlg, CDialog)
	ON_BN_CLICKED(IDC_CB_SINGLE, &CXMLViewDlg::OnBnClickedCbSingle)
END_MESSAGE_MAP()




// CXMLViewDlg message handlers
BOOL CXMLViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
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

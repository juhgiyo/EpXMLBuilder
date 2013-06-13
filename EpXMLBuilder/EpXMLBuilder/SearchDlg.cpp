// SearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "SearchDlg.h"


// CSearchDlg dialog

IMPLEMENT_DYNAMIC(CSearchDlg, CDialog)

CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDlg::IDD, pParent)
{

}

CSearchDlg::~CSearchDlg()
{
}

void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_NAME, m_tbName);
	DDX_Control(pDX, IDC_TB_VALUE, m_tbValue);
	DDX_Control(pDX, IDC_CBB_OPTION, m_cbbOption);
	DDX_Control(pDX, IDC_CB_MATCH_CASE, m_cbMatchCase);
	DDX_Control(pDX, IDC_CB_MATCH_WHOLE_WORD, m_cbMatchWholeWord);
}
BOOL CSearchDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_tbName.SetWindowText(m_name);
	m_tbValue.SetWindowText(m_value);

	if((int)m_searchType<0 || (int)m_searchType>2)
		m_searchType=XML_SEARCH_TYPE_ALL;
	
	m_cbbOption.AddString(_T("All"));
	m_cbbOption.AddString(_T("Nodes Only"));
	m_cbbOption.AddString(_T("Attributes Only"));
	m_cbbOption.SetCurSel((int)m_searchType);

	if(m_matchCase)
		m_cbMatchCase.SetCheck(BST_CHECKED);
	else
		m_cbMatchCase.SetCheck(BST_UNCHECKED);

	if(m_matchWholeWord)
		m_cbMatchWholeWord.SetCheck(BST_CHECKED);
	else
		m_cbMatchWholeWord.SetCheck(BST_UNCHECKED);

	m_tbName.SetFocus();
	m_tbName.SetSel(0,-1);
	return FALSE;
	return TRUE;
}

BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSearchDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSearchDlg message handlers

void CSearchDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_tbName.GetWindowText(m_name);
	m_tbValue.GetWindowText(m_value);
	m_searchType=(XMLSearchType)m_cbbOption.GetCurSel();

	m_matchCase=false;
	m_matchWholeWord=false;
	if(m_cbMatchCase.GetCheck()==BST_CHECKED)
		m_matchCase=true;
	if(m_cbMatchWholeWord.GetCheck()==BST_CHECKED)
		m_matchWholeWord=true;

	
	OnOK();
}

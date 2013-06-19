#pragma once
#include "afxwin.h"


// CXMLViewDlg dialog

class CXMLViewDlg : public CDialog
{
	DECLARE_DYNAMIC(CXMLViewDlg)

public:
	CXMLViewDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXMLViewDlg();

// Dialog Data
	enum { IDD = IDD_VIEW_XML };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_xmlString;
	CString m_xmlStringSingle;
	CEdit m_tbXML;
	afx_msg void OnBnClickedCbSingle();
	CButton m_cbSingleLine;
	afx_msg void OnBnClickedBtnWinservice();
	CButton m_btnWinServiceCLI;
};

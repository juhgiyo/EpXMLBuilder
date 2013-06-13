#pragma once
#include "afxwin.h"

#include "epXMLUtil.h"
// CSearchDlg dialog

class CSearchDlg : public CDialog
{
	DECLARE_DYNAMIC(CSearchDlg)

public:
	CSearchDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSearchDlg();

// Dialog Data
	enum { IDD = IDD_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_tbName;
	CEdit m_tbValue;
	CComboBox m_cbbOption;

	CString m_name;
	CString m_value;
	XMLSearchType m_searchType;
	bool m_matchCase;
	bool m_matchWholeWord;

	afx_msg void OnBnClickedOk();
	CButton m_cbMatchCase;
	CButton m_cbMatchWholeWord;
};

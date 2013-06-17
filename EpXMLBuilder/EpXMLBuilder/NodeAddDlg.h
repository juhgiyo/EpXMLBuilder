#pragma once
#include "afxwin.h"
#include "epPreTextParser.h"

// CNodeAddDlg dialog

class CNodeAddDlg : public CDialog
{
	DECLARE_DYNAMIC(CNodeAddDlg)

public:
	CNodeAddDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNodeAddDlg();

// Dialog Data
	enum { IDD = IDD_NODE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnEditchangeCbbName();
	afx_msg void OnCbnEditchangeCbbValue();

	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedButton1();

	CComboBox m_cbbName;
	CComboBox m_cbbValue;
	

	bool m_isNode;
	NodeStringMap m_nameMap;
	XNode *m_parentNode;

	CString m_nameString;
	CString m_valueString;

};

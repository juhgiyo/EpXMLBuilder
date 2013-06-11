#pragma once
#include "afxwin.h"
#include "epl.h"
using namespace epl;

// CNodeChangeDlg dialog

class CNodeChangeDlg : public CDialog
{
	DECLARE_DYNAMIC(CNodeChangeDlg)

public:
	CNodeChangeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNodeChangeDlg();

// Dialog Data
	enum { IDD = IDD_NODE_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_tbName;
	CEdit m_tbValue;
	CString m_nameString;
	CString m_valueString;
	XNode *m_parentNode;
	CWnd *m_mainDlg;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};

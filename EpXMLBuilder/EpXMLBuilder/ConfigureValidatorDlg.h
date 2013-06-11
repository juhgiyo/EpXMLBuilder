#pragma once
#include "afxwin.h"


// CConfigureValidatorDlg dialog

class CConfigureValidatorDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigureValidatorDlg)

public:
	CConfigureValidatorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConfigureValidatorDlg();

// Dialog Data
	enum { IDD = IDD_VALIDATOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_cbNumber;
	CButton m_cbXML;
	CButton m_cbSpace;
	CButton m_cbDash;
	CButton m_cbColon;
	CButton m_cbPeriod;

	afx_msg void OnBnClickedOk();
	CButton m_cbDuplicate;
};

#pragma once
#include "afxwin.h"
#include "epl.h"
using namespace epl;

// CWinServiceCLIResultDlg dialog

class CWinServiceCLIResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CWinServiceCLIResultDlg)

public:
	CWinServiceCLIResultDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWinServiceCLIResultDlg();

// Dialog Data
	enum { IDD = IDD_WINSERVICE_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_tbResult;
	CString m_resultString;
	XMLFile m_xmlFile;
	CTaskbarNotifier m_notifyWin;
	afx_msg void OnBnClickedExport();
};

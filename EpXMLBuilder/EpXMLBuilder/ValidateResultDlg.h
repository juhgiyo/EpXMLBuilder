#pragma once
#include "epXMLValidateResult.h"
#include <vector>
#include "afxcmn.h"
#include "afxwin.h"
#include "NodeChangeDlg.h"
using namespace std;
// CValidateResultDlg dialog

typedef enum _filterType{
FILTER_TYPE_ALL=0,
FILTER_TYPE_ERROR,
FILTER_TYPE_WARNING
}FilterType;

typedef map<XNode*,vector<XMLValidateResult> > ResultMap;

class CValidateResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CValidateResultDlg)

public:
	CValidateResultDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CValidateResultDlg();

// Dialog Data
	enum { IDD = IDD_VALIDATE_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnTvnSelchangedTreeResult(NMHDR *pNMHDR, LRESULT *pResult);

	void AddResultToTree(FilterType type);

	typedef map<HTREEITEM,XMLValidateResult> TreeResultMap;
	TreeResultMap m_treeResultMap;



	CTreeCtrl m_treeResult;

	ResultMap m_resultMap;

	
	CEdit m_tbMessage;

	HTREEITEM m_selectedTreeItem;
	
	CComboBox m_cbbFilter;

	CNodeChangeDlg m_nodeChangeDlg;
	CWnd *m_mainDlg;
	afx_msg void OnCbnSelchangeCbFilter();
	afx_msg void OnNMDblclkTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnRevalidate();
	afx_msg void OnBnClickedBtnConfigurevalidator();
	afx_msg void OnTvnKeydownTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
};

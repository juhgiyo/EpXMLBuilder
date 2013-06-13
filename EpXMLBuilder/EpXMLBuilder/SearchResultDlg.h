#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "epXMLSearchResult.h"
#include "epXMLUtil.h"
#include "NodeChangeDlg.h"
#include "SearchDlg.h"
// CSearchResultDlg dialog
typedef map<XNode*,vector<XMLSearchResult> > SearchResultMap;


class CSearchResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CSearchResultDlg)

public:
	CSearchResultDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSearchResultDlg();

// Dialog Data
	enum { IDD = IDD_SEARCH_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnConfigurevalidator();
	afx_msg void OnBnClickedBtnSearch();
	afx_msg void OnCbnSelchangeCbFilter();
	afx_msg void OnNMDblclkTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeResult(NMHDR *pNMHDR, LRESULT *pResult);

	void AddResultToTree(XMLSearchType type);
	CComboBox m_cbbFilter;
	CButton m_btnSearch;
	CTreeCtrl m_treeSearchResult;
	CStatic m_lblSearchKey;

	CNodeChangeDlg m_nodeChangeDlg;

	HTREEITEM m_selectedTreeItem;

	typedef map<HTREEITEM,XMLSearchResult> TreeSearchResultMap;
	TreeSearchResultMap m_treeSearchResultMap;

	SearchResultMap m_searchResultMap;
	CWnd *m_mainDlg;
	CSearchDlg m_searchDlg;

	CString m_searchName;
	CString m_searchValue;
	XMLSearchType m_searchType;
	bool m_searchMatchCase;
	bool m_searchMatchWholeWord;
	afx_msg void OnTvnKeydownTreeResult(NMHDR *pNMHDR, LRESULT *pResult);
};

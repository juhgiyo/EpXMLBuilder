/*! 
@file SearchResultDlg.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief Search Result Dialog Interface
@version 1.0

@section LICENSE

The MIT License (MIT)

Copyright (c) 2013 Woong Gyu La <juhgiyo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

@section DESCRIPTION

An Interface for the Search Result Dialog.

*/
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
	afx_msg void OnBnClickedBtnDelete();
};

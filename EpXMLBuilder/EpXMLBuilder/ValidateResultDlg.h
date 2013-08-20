/*! 
@file ValidateResultDlg.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief Validate Result Dialog Interface
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

An Interface for the Validate Result Dialog.

*/
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
	afx_msg void OnBnClickedBtnDelete();
};

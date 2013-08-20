/*! 
@file EpXMLBuilderDlg.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief XML Builder Dialog Interface
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

An Interface for the XML Builder Dialog.

*/
#pragma once

#include "epl.h"
#include "afxwin.h"
#include <map>
#include <vector>
#include "afxcmn.h"
#include "afxdtctl.h"

#include "epPreTextParser.h"
#include "epXMLValidatorProperties.h"
#include "epXMLUtil.h"

#include "ConfigureValidatorDlg.h"
#include "NodeChangeDlg.h"
#include "ValidateResultDlg.h"
#include "SearchResultDlg.h"
#include "SearchDlg.h"

#include "epXMLValidateResult.h"
#include "epXMLSearchResult.h"
using namespace epl;


// CEpXMLBuilderDlg dialog
class CEpXMLBuilderDlg : public CDialog
{
// Construction
public:
	CEpXMLBuilderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_EPXMLBUILDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	XMLFile m_xmlFile;

public:

	CButton m_btnNew;
	CButton m_btnLoad;
	CButton m_btnSave;
	CButton m_btnSaveAs;
	CComboBox m_cbNodeName;
	CComboBox m_cbNodeValue;
	CButton m_btnAdd;
	CButton m_btnDelete;
	CStatic m_lbFilename;
	CTreeCtrl m_treeXML;
	CEdit m_tbRoot;
	CButton m_btnLoadTextDB;
	CEdit m_tbRootValue;
	CComboBox m_cbAttrName;
	CComboBox m_cbAttrValue;
	CButton m_btnAddAttr;
	CComboBox m_cbEncoding;
	CButton m_btnChange;
	CButton m_btnConfigureValidator;

	CTaskbarNotifier m_notifyWin;
	
	afx_msg void OnBnClickedBtnNew();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnSaveAs();
	afx_msg void OnCbnEditchangeCbNode();
	afx_msg void OnCbnEditchangeCbValue();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnKeydownTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnLoadPreText();
	afx_msg void OnBnClickedBtnAddAttr();
	afx_msg void OnCbnEditchangeCbAttr();
	afx_msg void OnCbnEditchangeCbAttrValue();

	afx_msg void OnCbnSelchangeCbEncoding();

	afx_msg void OnEnSetfocusTbRoot();
	afx_msg void OnEnSetfocusTbRootvalue();
	afx_msg void OnCbnSetfocusCbNode();
	afx_msg void OnCbnSetfocusCbValue();
	afx_msg void OnCbnSetfocusCbAttr();
	afx_msg void OnCbnSetfocusCbAttrValue();
	afx_msg void OnBnSetfocusButton1();
	afx_msg void OnBnSetfocusBtnAdd();
	afx_msg void OnBnSetfocusBtnAddAttr();
	afx_msg void OnBnClickedBtnConfigureValidator();
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnBnClickedBtnSearch();

	bool continueOnChanged();
	HTREEITEM insertNode(CString nodeName, CString nodeValue,HTREEITEM insertUnder,XNode *node);
	void traverseXMLAndInsert();

	bool m_isChanged;

	typedef map<HTREEITEM,XNode*> TreeNodeMap;
	TreeNodeMap m_treeNodeMap;

	typedef map<HTREEITEM,XAttr*> TreeAttrMap;
	TreeAttrMap m_treeAttrMap;

	
	NodeStringMap m_nodeNameMap;
	NodeStringMap m_attrNameMap;
	HTREEITEM m_selectedTreeItem;

	CString m_rootName;
	TextFile m_textFile;

	WinResizer m_resizer;
	CSize m_minSize;
	CWnd *m_lastFocus;
	
	

	CConfigureValidatorDlg m_configureValidatorDlg;
	CNodeChangeDlg m_nodeChangeDlg;
	CValidateResultDlg m_validateResultDlg;
	CSearchResultDlg m_searchResultDlg;
	CSearchDlg m_searchDlg;

	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnValidate();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult);

	void NodeNameValueChange(HTREEITEM treeItem,CString name,CString value,bool isRoot,bool isNode,XNode* node, XAttr *attr);
	void ValidateXML(ResultMap & retResultMap);
	void SearchXML(XMLSearchType searchType,CString iName, CString iValue, bool isMatchCase,bool isMatchWholeWord,SearchResultMap & retResultMap);
	void DeleteTreeItem(HTREEITEM &treeItem);


	void AddNode();
	void AddAttribute();
	HTREEITEM GetNextItem(HTREEITEM item);
	
	afx_msg void OnBnClickedBtnXml();
};

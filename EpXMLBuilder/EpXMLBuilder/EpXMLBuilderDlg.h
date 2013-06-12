
// EpXMLBuilderDlg.h : header file
//

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
#include "epXMLValidateResult.h"

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
	

	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnValidate();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult);

	void NodeNameValueChange(HTREEITEM treeItem,CString name,CString value,bool isRoot,bool isNode,XNode* node, XAttr *attr);
	void ValidateXML(ResultMap & retResultMap);
};

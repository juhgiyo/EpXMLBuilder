// ValidateResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "ValidateResultDlg.h"
#include "EpXMLBuilderDlg.h"

// CValidateResultDlg dialog

IMPLEMENT_DYNAMIC(CValidateResultDlg, CDialog)

CValidateResultDlg::CValidateResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CValidateResultDlg::IDD, pParent)
{

}

CValidateResultDlg::~CValidateResultDlg()
{
}

void CValidateResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_RESULT, m_treeResult);
	DDX_Control(pDX, IDC_TB_MESSAGE, m_tbMessage);
	DDX_Control(pDX, IDC_CB_FILTER, m_cbbFilter);
}


BEGIN_MESSAGE_MAP(CValidateResultDlg, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_RESULT, &CValidateResultDlg::OnTvnSelchangedTreeResult)
	ON_CBN_SELCHANGE(IDC_CB_FILTER, &CValidateResultDlg::OnCbnSelchangeCbFilter)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_RESULT, &CValidateResultDlg::OnNMDblclkTreeResult)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_RESULT, &CValidateResultDlg::OnNMRClickTreeResult)
	ON_BN_CLICKED(IDOK, &CValidateResultDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_REVALIDATE, &CValidateResultDlg::OnBnClickedBtnRevalidate)
	ON_BN_CLICKED(IDC_BTN_CONFIGUREVALIDATOR, &CValidateResultDlg::OnBnClickedBtnConfigurevalidator)
	ON_NOTIFY(TVN_KEYDOWN, IDC_TREE_RESULT, &CValidateResultDlg::OnTvnKeydownTreeResult)
END_MESSAGE_MAP()


// CValidateResultDlg message handlers


BOOL CValidateResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cbbFilter.AddString(_T("All"));
	m_cbbFilter.AddString(_T("Error"));
	m_cbbFilter.AddString(_T("Warning"));
	m_cbbFilter.SetCurSel(0);
	AddResultToTree(FILTER_TYPE_ALL);
	m_treeResult.SetFocus();
	return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CValidateResultDlg::AddResultToTree(FilterType type)
{
	m_treeResult.DeleteAllItems();
	m_treeResultMap.clear();

	// TODO: Add extra initialization here
	for(ResultMap::iterator iter=m_resultMap.begin();iter!=m_resultMap.end();iter++)
	{
		CString parentString;
		if(iter->first)
		{
			CString parentNodeName=iter->first->m_name;
			parentNodeName=parentNodeName.Trim();
			CString parentNodeValue=iter->first->m_value;
			parentNodeValue=parentNodeValue.Trim();
			parentString=XMLUtil::NodeFormat(parentNodeName,parentNodeValue);
		}
		else
		{
			//parentString=XMLUtil::NodeFormat(_T("Root"),_T(""));
			parentString=_T("Root Element");
		}
		HTREEITEM treeItem=m_treeResult.InsertItem(parentString);
		for(vector<XMLValidateResult>::iterator listTrav=iter->second.begin();listTrav!=iter->second.end();listTrav++)
		{
			if(listTrav->m_type==XML_VALIDATE_TYPE_WARNING && type==FILTER_TYPE_ERROR)
				continue;
			if(listTrav->m_type==XML_VALIDATE_TYPE_ERROR && type==FILTER_TYPE_WARNING)
				continue;
			CString treeElemString=XMLUtil::ResultFormat(listTrav->m_name,listTrav->m_value,listTrav->m_isNode,listTrav->m_type);
			HTREEITEM insertedItem=m_treeResult.InsertItem(treeElemString.GetString(),treeItem,TVI_LAST);
			m_treeResultMap[insertedItem]=(*listTrav);
		}
		m_treeResult.Expand(treeItem,TVE_EXPAND);
		m_treeResult.SortChildren(treeItem);

	}
	HTREEITEM selectItem=m_treeResult.GetFirstVisibleItem();
	if(selectItem)
	{
		HTREEITEM childItem=m_treeResult.GetChildItem(selectItem);
		while(selectItem && childItem==NULL)
		{
			selectItem=m_treeResult.GetNextItem(selectItem,TVGN_NEXT);
			childItem=m_treeResult.GetChildItem(selectItem);
		}
		m_treeResult.SelectItem(childItem);
		m_selectedTreeItem=childItem;
	}
	

}
void CValidateResultDlg::OnTvnSelchangedTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	m_selectedTreeItem = m_treeResult.GetSelectedItem();
	if(m_selectedTreeItem!=NULL)
	{
		TreeResultMap::iterator iter=m_treeResultMap.find(m_selectedTreeItem);
		if(iter!=m_treeResultMap.end())
		{
			CString message=_T("\n");
			message.Append(iter->second.m_message);
			message.Replace(_T("\n"),_T("\r\n"));
			m_tbMessage.SetWindowText(message.GetString());
			return;
		}
	}
	m_tbMessage.SetWindowText(_T(""));
}

void CValidateResultDlg::OnCbnSelchangeCbFilter()
{
	// TODO: Add your control notification handler code here
	if(m_cbbFilter.GetCurSel()==0)
	{
		AddResultToTree(FILTER_TYPE_ALL);
	}
	else if(m_cbbFilter.GetCurSel()==1)
	{
		AddResultToTree(FILTER_TYPE_ERROR);
	}
	else
	{
		AddResultToTree(FILTER_TYPE_WARNING);
	}
}

void CValidateResultDlg::OnNMDblclkTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if(m_selectedTreeItem==NULL)
		return;
	TreeResultMap::iterator nodeIter=m_treeResultMap.find(m_selectedTreeItem);
	if(nodeIter==m_treeResultMap.end())
	{
		return;
	}

	m_nodeChangeDlg.m_nameString=nodeIter->second.m_name;
	m_nodeChangeDlg.m_valueString=nodeIter->second.m_value;
	m_nodeChangeDlg.m_parentNode=nodeIter->second.m_parentNode;
	m_nodeChangeDlg.m_isNode=nodeIter->second.m_isNode;
	m_nodeChangeDlg.m_attr=nodeIter->second.m_attr;
	if(m_nodeChangeDlg.DoModal()==IDOK)
	{
		nodeIter->second.m_name=m_nodeChangeDlg.m_nameString;
		nodeIter->second.m_value=m_nodeChangeDlg.m_valueString;
		((CEpXMLBuilderDlg*)m_mainDlg)->NodeNameValueChange(nodeIter->second.m_treeItem,nodeIter->second.m_name,nodeIter->second.m_value,nodeIter->second.m_isRoot,nodeIter->second.m_isNode,nodeIter->second.m_node,nodeIter->second.m_attr);
		
		m_treeResultMap.erase(nodeIter);
		HTREEITEM prevItem=m_treeResult.GetPrevVisibleItem(m_selectedTreeItem);
		m_treeResult.DeleteItem(m_selectedTreeItem);
		m_treeResult.SelectItem(prevItem);
		m_selectedTreeItem=prevItem;


		((CEpXMLBuilderDlg*)m_mainDlg)->ValidateXML(m_resultMap);
		AddResultToTree((FilterType)m_cbbFilter.GetCurSel());
	}
	
}

void CValidateResultDlg::OnNMRClickTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	DWORD dPos=GetMessagePos();
	POINTS points=MAKEPOINTS(dPos);
	POINT point;
	point.x=(LONG)points.x;
	point.y=(LONG)points.y;
	m_treeResult.ScreenToClient(&point);
	CPoint cPoint=CPoint(point);
	UINT uFlags;
	HTREEITEM item=m_treeResult.HitTest(cPoint, &uFlags);
	if ((item != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_treeResult.Select(item, TVGN_CARET);
		m_selectedTreeItem=item;
		m_treeResult.Expand(m_selectedTreeItem,TVE_TOGGLE);
	}
	else
		return;
}
BOOL CValidateResultDlg::PreTranslateMessage(MSG* pMsg)
{
	// ENTER key
	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == VK_RETURN))
	{
		if(m_treeResult.GetFirstVisibleItem())
		{

			LONG result;
			OnNMDblclkTreeResult(NULL,&result);
			return TRUE;
		}
	}

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x43)) //C
	{
		if((GetKeyState(VK_SHIFT) & 0x8000)&& (GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnConfigurevalidator();
			return TRUE;
		}

	}

// 	if((pMsg->message == WM_KEYDOWN) && 
// 		(pMsg->wParam == 0x51)) //Q
// 	{
// 		if((GetKeyState(VK_CONTROL) & 0x8000))
// 		{
// 			OnBnClickedBtnRevalidate();
// 			return TRUE;
// 		}
// 
// 	}

	return CDialog::PreTranslateMessage(pMsg);
}
void CValidateResultDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CValidateResultDlg::OnBnClickedBtnRevalidate()
{
	// TODO: Add your control notification handler code here
	((CEpXMLBuilderDlg*)m_mainDlg)->ValidateXML(m_resultMap);
	AddResultToTree((FilterType)m_cbbFilter.GetCurSel());
}

void CValidateResultDlg::OnBnClickedBtnConfigurevalidator()
{
	// TODO: Add your control notification handler code here
	CConfigureValidatorDlg configureValidatorDlg;
	if(configureValidatorDlg.DoModal()==IDOK)
	{
		OnBnClickedBtnRevalidate();
	}
}

void CValidateResultDlg::OnTvnKeydownTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	NMTVKEYDOWN * pKey = (NMTVKEYDOWN *)pNMHDR;

	HTREEITEM hSel = m_treeResult.GetSelectedItem();
	if (pKey->wVKey == VK_DELETE && hSel != NULL)
	{
		TreeResultMap::iterator iter=m_treeResultMap.find(hSel);
		if(iter!=m_treeResultMap.end())
		{
			((CEpXMLBuilderDlg*)m_mainDlg)->DeleteTreeItem(iter->second.m_treeItem);

			((CEpXMLBuilderDlg*)m_mainDlg)->ValidateXML(m_resultMap);
			AddResultToTree((FilterType)m_cbbFilter.GetCurSel());
		}
		
	}
}

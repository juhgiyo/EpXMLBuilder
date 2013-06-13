// SearchResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "SearchResultDlg.h"
#include "ConfigureValidatorDlg.h"
#include "SearchDlg.h"
#include "EpXMLBuilderDlg.h"
// CSearchResultDlg dialog

IMPLEMENT_DYNAMIC(CSearchResultDlg, CDialog)

CSearchResultDlg::CSearchResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchResultDlg::IDD, pParent)
{

}

CSearchResultDlg::~CSearchResultDlg()
{
}

void CSearchResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_FILTER, m_cbbFilter);
	DDX_Control(pDX, IDC_BTN_SEARCH, m_btnSearch);
	DDX_Control(pDX, IDC_TREE_RESULT, m_treeSearchResult);
	DDX_Control(pDX, IDC_LBL_SEARCHKEY, m_lblSearchKey);
}


BEGIN_MESSAGE_MAP(CSearchResultDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_CONFIGUREVALIDATOR, &CSearchResultDlg::OnBnClickedBtnConfigurevalidator)
	ON_BN_CLICKED(IDC_BTN_SEARCH, &CSearchResultDlg::OnBnClickedBtnSearch)
	ON_CBN_SELCHANGE(IDC_CB_FILTER, &CSearchResultDlg::OnCbnSelchangeCbFilter)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_RESULT, &CSearchResultDlg::OnNMDblclkTreeResult)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_RESULT, &CSearchResultDlg::OnNMRClickTreeResult)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_RESULT, &CSearchResultDlg::OnTvnSelchangedTreeResult)
	ON_NOTIFY(TVN_KEYDOWN, IDC_TREE_RESULT, &CSearchResultDlg::OnTvnKeydownTreeResult)
END_MESSAGE_MAP()


BOOL CSearchResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cbbFilter.AddString(_T("All"));
	m_cbbFilter.AddString(_T("Node"));
	m_cbbFilter.AddString(_T("Attribute"));
	m_cbbFilter.SetCurSel(0);
	AddResultToTree(XML_SEARCH_TYPE_ALL);


	m_treeSearchResult.SetFocus();
	CString searchKey=XMLUtil::SearchKeyFormat(m_searchType,m_searchName,m_searchValue,m_searchMatchCase,m_searchMatchWholeWord);
	m_lblSearchKey.SetWindowText(searchKey.GetString());

	m_searchDlg.m_searchType=m_searchType;
	m_searchDlg.m_value=m_searchValue;
	m_searchDlg.m_name=m_searchName;
	m_searchDlg.m_matchCase=m_searchMatchCase;
	m_searchDlg.m_matchWholeWord=m_searchMatchWholeWord;

	return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSearchResultDlg::AddResultToTree(XMLSearchType type)
{
	m_treeSearchResult.DeleteAllItems();
	m_treeSearchResultMap.clear();

	// TODO: Add extra initialization here
	for(SearchResultMap::iterator iter=m_searchResultMap.begin();iter!=m_searchResultMap.end();iter++)
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
		HTREEITEM treeItem=m_treeSearchResult.InsertItem(parentString);
		for(vector<XMLSearchResult>::iterator listTrav=iter->second.begin();listTrav!=iter->second.end();listTrav++)
		{
			if(type==XML_SEARCH_TYPE_NODE && !listTrav->m_isNode)
				continue;
			if( type==XML_SEARCH_TYPE_ATTRIBUTE && listTrav->m_isNode)
				continue;
			CString treeElemString;
			if(listTrav->m_isNode)
				treeElemString=XMLUtil::NodeFormat(listTrav->m_name,listTrav->m_value);
			else
				treeElemString=XMLUtil::AttrFormat(listTrav->m_name,listTrav->m_value);
			HTREEITEM insertedItem=m_treeSearchResult.InsertItem(treeElemString.GetString(),treeItem,TVI_LAST);
			m_treeSearchResultMap[insertedItem]=(*listTrav);
		}
		m_treeSearchResult.Expand(treeItem,TVE_EXPAND);
		m_treeSearchResult.SortChildren(treeItem);

	}
	HTREEITEM selectItem=m_treeSearchResult.GetFirstVisibleItem();
	if(selectItem)
	{
		HTREEITEM childItem=m_treeSearchResult.GetChildItem(selectItem);
		while(selectItem && childItem==NULL)
		{
			selectItem=m_treeSearchResult.GetNextItem(selectItem,TVGN_NEXT);
			childItem=m_treeSearchResult.GetChildItem(selectItem);
		}
		m_treeSearchResult.SelectItem(childItem);
		m_selectedTreeItem=childItem;
	}


}

// CSearchResultDlg message handlers

void CSearchResultDlg::OnBnClickedBtnConfigurevalidator()
{
	// TODO: Add your control notification handler code here
	CConfigureValidatorDlg configureValidatorDlg;
	configureValidatorDlg.DoModal();
}

void CSearchResultDlg::OnBnClickedBtnSearch()
{
	// TODO: Add your control notification handler code here

	if(m_searchDlg.DoModal()==IDOK)
	{
		m_searchName=m_searchDlg.m_name;
		m_searchValue=m_searchDlg.m_value;
		m_searchType=m_searchDlg.m_searchType;
		m_searchMatchCase=m_searchDlg.m_matchCase;
		m_searchMatchWholeWord=m_searchDlg.m_matchWholeWord;
		((CEpXMLBuilderDlg*)m_mainDlg)->SearchXML(m_searchType,m_searchName,m_searchValue,m_searchMatchCase,m_searchMatchWholeWord,m_searchResultMap);
		CString searchKey=XMLUtil::SearchKeyFormat(m_searchType,m_searchName,m_searchValue,m_searchMatchCase,m_searchMatchWholeWord);
		m_lblSearchKey.SetWindowText(searchKey.GetString());

		AddResultToTree((XMLSearchType)m_cbbFilter.GetCurSel());	
	}
}

void CSearchResultDlg::OnCbnSelchangeCbFilter()
{
	// TODO: Add your control notification handler code here
	if(m_cbbFilter.GetCurSel()==0)
	{
		AddResultToTree(XML_SEARCH_TYPE_ALL);
	}
	else if(m_cbbFilter.GetCurSel()==1)
	{
		AddResultToTree(XML_SEARCH_TYPE_NODE);
	}
	else
	{
		AddResultToTree(XML_SEARCH_TYPE_ATTRIBUTE);
	}
}

void CSearchResultDlg::OnNMDblclkTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if(m_selectedTreeItem==NULL)
		return;
	TreeSearchResultMap::iterator nodeIter=m_treeSearchResultMap.find(m_selectedTreeItem);
	if(nodeIter==m_treeSearchResultMap.end())
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

		m_treeSearchResultMap.erase(nodeIter);
		HTREEITEM prevItem=m_treeSearchResult.GetPrevVisibleItem(m_selectedTreeItem);
		m_treeSearchResult.DeleteItem(m_selectedTreeItem);
		m_treeSearchResult.SelectItem(prevItem);
		m_selectedTreeItem=prevItem;


		((CEpXMLBuilderDlg*)m_mainDlg)->SearchXML(m_searchType,m_searchName,m_searchValue,m_searchMatchCase,m_searchMatchWholeWord,m_searchResultMap);
		AddResultToTree((XMLSearchType)m_cbbFilter.GetCurSel());
	}

}

void CSearchResultDlg::OnNMRClickTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	DWORD dPos=GetMessagePos();
	POINTS points=MAKEPOINTS(dPos);
	POINT point;
	point.x=(LONG)points.x;
	point.y=(LONG)points.y;
	m_treeSearchResult.ScreenToClient(&point);
	CPoint cPoint=CPoint(point);
	UINT uFlags;
	HTREEITEM item=m_treeSearchResult.HitTest(cPoint, &uFlags);
	if ((item != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_treeSearchResult.Select(item, TVGN_CARET);
		m_selectedTreeItem=item;
		m_treeSearchResult.Expand(m_selectedTreeItem,TVE_TOGGLE);
	}
	else
		return;
}

void CSearchResultDlg::OnTvnSelchangedTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	m_selectedTreeItem = m_treeSearchResult.GetSelectedItem();
}

BOOL CSearchResultDlg::PreTranslateMessage(MSG* pMsg)
{
	// ENTER key
	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == VK_RETURN))
	{
		if(m_treeSearchResult.GetFirstVisibleItem())
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

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x45)) // E
	{
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnSearch();
			return TRUE;
		}

	}

	return CDialog::PreTranslateMessage(pMsg);
}
void CSearchResultDlg::OnTvnKeydownTreeResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	NMTVKEYDOWN * pKey = (NMTVKEYDOWN *)pNMHDR;

	HTREEITEM hSel = m_treeSearchResult.GetSelectedItem();
	if (pKey->wVKey == VK_DELETE && hSel != NULL)
	{
		TreeSearchResultMap::iterator iter=m_treeSearchResultMap.find(hSel);
		if(iter!=m_treeSearchResultMap.end())
		{
			((CEpXMLBuilderDlg*)m_mainDlg)->DeleteTreeItem(iter->second.m_treeItem);

			((CEpXMLBuilderDlg*)m_mainDlg)->SearchXML(m_searchType,m_searchName,m_searchValue,m_searchMatchCase,m_searchMatchWholeWord,m_searchResultMap);
			AddResultToTree((XMLSearchType)m_cbbFilter.GetCurSel());
		}

	}
}

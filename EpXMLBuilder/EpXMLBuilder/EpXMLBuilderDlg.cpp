
// EpXMLBuilderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "EpXMLBuilderDlg.h"

#include <queue>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CEpXMLBuilderDlg dialog




CEpXMLBuilderDlg::CEpXMLBuilderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEpXMLBuilderDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEpXMLBuilderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_NEW, m_btnNew);
	DDX_Control(pDX, IDC_BTN_LOAD, m_btnLoad);
	DDX_Control(pDX, IDC_BTN_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_BTN_SAVE_AS, m_btnSaveAs);
	DDX_Control(pDX, IDC_CB_NODE, m_cbNodeName);
	DDX_Control(pDX, IDC_CB_VALUE, m_cbNodeValue);
	DDX_Control(pDX, IDC_BTN_ADD, m_btnAdd);
	DDX_Control(pDX, IDC_BTN_DELETE, m_btnDelete);
	DDX_Control(pDX, IDC_LB_FILENAME, m_lbFilename);
	DDX_Control(pDX, IDC_TREE1, m_treeXML);
	DDX_Control(pDX, IDC_TB_ROOT, m_tbRoot);
	DDX_Control(pDX, IDC_BTN_LOAD_PRE_TEXT, m_btnLoadTextDB);
	DDX_Control(pDX, IDC_TB_ROOTVALUE, m_tbRootValue);
	DDX_Control(pDX, IDC_CB_ATTR, m_cbAttrName);
	DDX_Control(pDX, IDC_CB_ATTR_VALUE, m_cbAttrValue);
	DDX_Control(pDX, IDC_BTN_ADD_ATTR, m_btnAddAttr);
}

BEGIN_MESSAGE_MAP(CEpXMLBuilderDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BTN_NEW, &CEpXMLBuilderDlg::OnBnClickedBtnNew)
ON_BN_CLICKED(IDC_BTN_LOAD, &CEpXMLBuilderDlg::OnBnClickedBtnLoad)
ON_BN_CLICKED(IDC_BTN_SAVE, &CEpXMLBuilderDlg::OnBnClickedBtnSave)
ON_BN_CLICKED(IDC_BTN_SAVE_AS, &CEpXMLBuilderDlg::OnBnClickedBtnSaveAs)
ON_CBN_EDITCHANGE(IDC_CB_NODE, &CEpXMLBuilderDlg::OnCbnEditchangeCbNode)
ON_CBN_EDITCHANGE(IDC_CB_VALUE, &CEpXMLBuilderDlg::OnCbnEditchangeCbValue)
ON_BN_CLICKED(IDC_BTN_ADD, &CEpXMLBuilderDlg::OnBnClickedBtnAdd)
ON_BN_CLICKED(IDC_BTN_DELETE, &CEpXMLBuilderDlg::OnBnClickedBtnDelete)
ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CEpXMLBuilderDlg::OnTvnSelchangedTree1)
ON_NOTIFY(TVN_KEYDOWN, IDC_TREE1, &CEpXMLBuilderDlg::OnTvnKeydownTree1)
ON_BN_CLICKED(IDC_BUTTON1, &CEpXMLBuilderDlg::OnBnClickedButton1)
ON_WM_CLOSE()
ON_BN_CLICKED(IDCANCEL, &CEpXMLBuilderDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BTN_LOAD_PRE_TEXT, &CEpXMLBuilderDlg::OnBnClickedBtnLoadPreText)
ON_BN_CLICKED(IDC_BTN_ADD_ATTR, &CEpXMLBuilderDlg::OnBnClickedBtnAddAttr)
ON_CBN_EDITCHANGE(IDC_CB_ATTR, &CEpXMLBuilderDlg::OnCbnEditchangeCbAttr)
ON_CBN_EDITCHANGE(IDC_CB_ATTR_VALUE, &CEpXMLBuilderDlg::OnCbnEditchangeCbAttrValue)
END_MESSAGE_MAP()


// CEpXMLBuilderDlg message handlers

BOOL CEpXMLBuilderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Set Anchors
	m_resizer.Hook(this);

	m_resizer.SetAnchor(IDC_BTN_LOAD_PRE_TEXT,ANCHOR_LEFT|ANCHOR_TOP);

	m_resizer.SetAnchor(IDC_BTN_DELETE,ANCHOR_LEFT|ANCHOR_TOP);
	
	m_resizer.SetAnchor(IDC_TREE1,ANCHOR_RIGHT|ANCHOR_TOP|ANCHOR_LEFT|ANCHOR_BOTTOM);

	m_resizer.SetAnchor(IDC_BTN_NEW,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BTN_LOAD,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BTN_SAVE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BTN_SAVE_AS,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_LB_FILENAME,ANCHOR_RIGHT|ANCHOR_TOP);

	m_resizer.SetAnchor(IDC_ST_ROOT_GROUP,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_ROOTNAME,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_TB_ROOT,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_ROOTVALUE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_TB_ROOTVALUE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BUTTON1,ANCHOR_RIGHT|ANCHOR_TOP);


	m_resizer.SetAnchor(IDC_ST_NODE_GROUP,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_CB_NODE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_CB_VALUE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BTN_ADD,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_NODE_NAME,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_NODE_VALUE,ANCHOR_RIGHT|ANCHOR_TOP);

	m_resizer.SetAnchor(IDC_ST_ATTR_GROUP,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_CB_ATTR,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_CB_ATTR_VALUE,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_BTN_ADD_ATTR,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_ATTR_NAME,ANCHOR_RIGHT|ANCHOR_TOP);
	m_resizer.SetAnchor(IDC_ST_ATTR_VALUE,ANCHOR_RIGHT|ANCHOR_TOP);

	m_resizer.SetAnchor(IDCANCEL,ANCHOR_RIGHT|ANCHOR_BOTTOM);

	
	BOOL bOk = FALSE;
	m_resizer.SetShowResizeGrip(TRUE);

	bOk = m_resizer.InvokeOnResized();
	ASSERT( bOk);


	// Set Notification window
	m_notifyWin.Create(this);
	m_notifyWin.SetSkin(IDB_BITMAP1);
	m_notifyWin.SetTextFont(_T("Arial"),90,TN_TEXT_NORMAL,TN_TEXT_UNDERLINE);
	m_notifyWin.SetTextColor(RGB(0,0,0),RGB(0,0,200));
	m_notifyWin.SetTextRect(CRect(10,40,m_notifyWin.m_nSkinWidth-10,m_notifyWin.m_nSkinHeight-25));


	// Load Pre Text Database
	m_textFile=TextFile(FILE_ENCODING_TYPE_UTF8);

	CString iniFileName=FolderHelper::GetModuleFileName().c_str();
	iniFileName.Replace(_T(".exe"),_T(".ini"));

	if(m_textFile.LoadFromFile(iniFileName.GetString()))
	{
		PreTestParser::Parse(m_textFile,m_nodeNameMap,m_attrNameMap);
	}

	// Rest of Settings

	m_isChanged=false;
	m_lbFilename.SetWindowText(_T(""));
	XMLInfo info=XMLInfo::xmlDefault;
	info.m_isWriteComment=true;
	m_xmlFile=XMLFile(FILE_ENCODING_TYPE_UTF16LE,info);
	m_cbNodeName.SetFocus();

	m_tbRoot.SetWindowText(_T("Root"));
	m_rootName=nodeFormat(_T("Root"),_T(""));
	m_selectedTreeItem=m_treeXML.InsertItem(m_rootName.GetString());
	XNode *node= &m_xmlFile;
	node->m_name=_T("Root");
	node->m_value=_T("");
	m_treeXML.SelectItem(m_selectedTreeItem);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEpXMLBuilderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEpXMLBuilderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEpXMLBuilderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CEpXMLBuilderDlg::continueOnChanged()
{
	if(m_isChanged)
	{
		int result=MessageBox(_T("Current XML is not saved.\n\nDo you want to save current XML?"),_T("Notice"),MB_YESNOCANCEL);
		CString fileName;
		if(result==IDYES)
		{
			m_lbFilename.GetWindowText(fileName);
			if(fileName.GetLength()<=0)
			{
				CFileDialog saveDialog(FALSE, _T("xml"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("XML Files (*.xml)|*.xml|All Files (*.*)|*.*||"),this);
				int result =saveDialog.DoModal();
				if(result==IDCANCEL)
					return false;
				if(saveDialog.GetPathName().GetLength()<=0)
					return false;
				fileName=saveDialog.GetPathName();
			}
			m_xmlFile.SaveToFile(fileName);
		}
		else if(result==IDCANCEL )
		{
			return false;
		}
	}
	return true;
}
void CEpXMLBuilderDlg::OnBnClickedBtnNew()
{
	if(!continueOnChanged())
		return;
	m_xmlFile.Clear();
	m_treeXML.DeleteAllItems();
	m_rootName=nodeFormat(_T("Root"),_T(""));
	m_tbRoot.SetWindowText(_T("Root"));
	m_tbRootValue.SetWindowText(_T(""));

	m_selectedTreeItem=m_treeXML.InsertItem(m_rootName.GetString());
	m_treeXML.SelectItem(m_selectedTreeItem);
	XNode *node= &m_xmlFile;
	node->m_name=_T("Root");
	node->m_value=_T("");
	m_isChanged=false;
	m_lbFilename.SetWindowText(_T(""));
}

HTREEITEM CEpXMLBuilderDlg::insertNode(CString nodeName, CString nodeValue,HTREEITEM insertUnder,XNode *node)
{
	CString treeElemString=nodeFormat(nodeName,nodeValue);
	HTREEITEM insertedItem=m_treeXML.InsertItem(treeElemString.GetString(),insertUnder,TVI_LAST);
	m_treeNodeMap[insertedItem]=node;

	for (int attrTrav=0;attrTrav<node->m_attrs.size();attrTrav++)
	{
		CString treeElemString=attrFormat(node->m_attrs.at(attrTrav)->m_name,node->m_attrs.at(attrTrav)->m_value);
		HTREEITEM insertedAttrItem=m_treeXML.InsertItem(treeElemString.GetString(),insertedItem,TVI_LAST);
		m_treeAttrMap[insertedAttrItem]=node->m_attrs.at(attrTrav);
	}


	m_treeXML.Expand(insertUnder,TVE_EXPAND);
	return insertedItem;
}

struct InsertLoopStruct{
	HTREEITEM m_rootItem;
	vector<XNode*> m_childList;
};

void CEpXMLBuilderDlg::traverseXMLAndInsert()
{
	queue<InsertLoopStruct> traverseQueue;
	InsertLoopStruct newQueueNode;
	newQueueNode.m_rootItem=m_treeXML.GetFirstVisibleItem();
	XNode *curNode=&m_xmlFile;
	for(int childTrav=0;childTrav<curNode->GetChildCount();childTrav++)
	{
		XNode *childeNode=curNode->GetChild(childTrav);
		newQueueNode.m_childList.push_back(childeNode);
	}
	if(newQueueNode.m_childList.size())
		traverseQueue.push(newQueueNode);

	while(!traverseQueue.empty())
	{
		InsertLoopStruct curStruct=traverseQueue.front();
		traverseQueue.pop();
		for(int childTrav=0;childTrav<curStruct.m_childList.size();childTrav++)
		{
			curNode=curStruct.m_childList.at(childTrav);
			HTREEITEM insertedItem=insertNode(curNode->m_name,curNode->m_value,curStruct.m_rootItem,curNode);

			newQueueNode.m_rootItem=insertedItem;
			newQueueNode.m_childList.clear();
			for(int childTrav=0;childTrav<curNode->GetChildCount();childTrav++)
			{
				XNode *childeNode=curNode->GetChild(childTrav);
				newQueueNode.m_childList.push_back(childeNode);
			}
			if(newQueueNode.m_childList.size())
				traverseQueue.push(newQueueNode);
		}
		
	}
}
void CEpXMLBuilderDlg::OnBnClickedBtnLoad()
{
	if(!continueOnChanged())
		return;
	CString fileName;
	

	CFileDialog fileDialog(TRUE,_T("xml"),NULL,OFN_FILEMUSTEXIST,_T("XML Files (*.xml)|*.xml|All Files (*.*)|*.*||"),this );
	fileDialog.m_pOFN->lpstrTitle=_T("XML Data File");
	fileDialog.m_pOFN->lpstrInitialDir=_T("c:");
	int result = fileDialog.DoModal();
	if(result==IDOK && fileDialog.GetPathName().GetLength()>0)
	{
		fileName=fileDialog.GetPathName();
	}
	else
		return;
	
	m_xmlFile.Clear();
	m_treeXML.DeleteAllItems();
	m_xmlFile.LoadFromFile(fileName);

	XNode * node=&m_xmlFile;
	m_rootName=nodeFormat(node->m_name,node->m_value);
	m_selectedTreeItem=m_treeXML.InsertItem(m_rootName);
	m_treeXML.SelectItem(m_selectedTreeItem);
	m_tbRoot.SetWindowText(node->m_name.GetString());
	m_tbRootValue.SetWindowText(node->m_value.GetString());

	for (int attrTrav=0;attrTrav<node->m_attrs.size();attrTrav++)
	{
		CString treeElemString=attrFormat(node->m_attrs.at(attrTrav)->m_name,node->m_attrs.at(attrTrav)->m_value);
		HTREEITEM insertedItem=m_treeXML.InsertItem(treeElemString.GetString(),m_selectedTreeItem,TVI_LAST);
		m_treeAttrMap[insertedItem]=node->m_attrs.at(attrTrav);
	}

	traverseXMLAndInsert();


	m_isChanged=false;
	m_lbFilename.SetWindowText(fileName.GetString());
}

void CEpXMLBuilderDlg::OnBnClickedBtnSave()
{
	CString fileName;
	m_lbFilename.GetWindowText(fileName);
	if(fileName.GetLength()<=0)
	{
		
		CFileDialog saveDialog(FALSE, _T("xml"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("XML Files (*.xml)|*.xml|All Files (*.*)|*.*||"),this);
		int result =saveDialog.DoModal();
		if(result==IDCANCEL || saveDialog.GetPathName().GetLength()<=0)
			return;
		fileName=saveDialog.GetPathName();
		m_lbFilename.SetWindowText(fileName.GetString());
	}
	m_xmlFile.SaveToFile(fileName);
	m_isChanged=false;

	m_notifyWin.Show(_T("XML is saved."),POP_UP_TIME_TO_SHOW,POP_UP_TIME_TO_STAY,POP_UP_TIME_TO_HIDE);
}

void CEpXMLBuilderDlg::OnBnClickedBtnSaveAs()
{
	CString fileName;
	CFileDialog saveDialog(FALSE, _T("xml"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("XML Files (*.xml)|*.xml|All Files (*.*)|*.*||"),this);
	int result =saveDialog.DoModal();
	if(result==IDCANCEL || saveDialog.GetPathName().GetLength()<=0)
		return;
	fileName=saveDialog.GetPathName();
	m_xmlFile.SaveToFile(fileName);
	m_isChanged=false;
	m_lbFilename.SetWindowText(fileName.GetString());
	m_notifyWin.Show(_T("XML is saved."),POP_UP_TIME_TO_SHOW,POP_UP_TIME_TO_STAY,POP_UP_TIME_TO_HIDE);
}


void CEpXMLBuilderDlg::OnCbnEditchangeCbNode()
{
	int cbBoxCnt=m_cbNodeName.GetCount();
	for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
	{
		m_cbNodeName.DeleteString(cbTrav);
	}
	CString textString;
	m_cbNodeName.GetWindowText(textString);
	m_cbNodeName.AddString(textString);
	if(textString.GetLength()>0)
	{
		CString lowerTextString=textString;
		lowerTextString=lowerTextString.MakeLower();
		NodeStringMap::iterator iter;
		for(iter=m_nodeNameMap.begin();iter!=m_nodeNameMap.end();iter++)
		{
			CString lowerIterString=*const_cast<CString*>(&(iter->first));
			lowerIterString=lowerIterString.MakeLower();
			
			if( lowerIterString.Find(lowerTextString.GetString())!=-1)
			{
				m_cbNodeName.AddString(iter->first.GetString());
			}
		}
	}
	else
	{
		NodeStringMap::iterator iter;
		for(iter=m_nodeNameMap.begin();iter!=m_nodeNameMap.end();iter++)
		{
			m_cbNodeName.AddString(iter->first.GetString());
		}
	}
	if(m_cbNodeName.GetCount())
		m_cbNodeName.ShowDropDown(TRUE);
	else
		m_cbNodeName.ShowDropDown(FALSE);
	m_cbNodeName.SetEditSel(-1,textString.GetLength());
}

void CEpXMLBuilderDlg::OnCbnEditchangeCbValue()
{
	int cbBoxCnt=m_cbNodeValue.GetCount();
	for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
	{
		m_cbNodeValue.DeleteString(cbTrav);
	}
	CString nameTextString;
	CString valueTextString;
	m_cbNodeName.GetWindowText(nameTextString);
	m_cbNodeValue.GetWindowText(valueTextString);
	m_cbNodeValue.AddString(valueTextString);
	CString lowerValueTextString=valueTextString;
	lowerValueTextString=lowerValueTextString.MakeLower();
	if(nameTextString.GetLength()>0)
	{
		NodeStringMap::iterator iter=m_nodeNameMap.find(nameTextString);
		if(iter!=m_nodeNameMap.end())
		{
			if(valueTextString.GetLength()>0)
			{
				for(int trav=0;trav<iter->second.size();trav++)
				{
					CString lowerIterString=*const_cast<CString*>(&(iter->second.at(trav)));
					lowerIterString=lowerIterString.MakeLower();
					if(lowerIterString.Find(lowerValueTextString.GetString())!=-1)
					{
						m_cbNodeValue.AddString(iter->second.at(trav).GetString());
					}
				}
			}
			else
			{
				for(int trav=0;trav<iter->second.size();trav++)
				{
					m_cbNodeValue.AddString(iter->second.at(trav).GetString());
				}
			}
			
		}
		
	}
	if(m_cbNodeValue.GetCount())
		m_cbNodeValue.ShowDropDown(TRUE);
	else
		m_cbNodeValue.ShowDropDown(FALSE);
	m_cbNodeValue.SetEditSel(-1,valueTextString.GetLength());
}



void CEpXMLBuilderDlg::OnCbnEditchangeCbAttr()
{
	// TODO: Add your control notification handler code here

	int cbBoxCnt=m_cbAttrName.GetCount();
	for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
	{
		m_cbAttrName.DeleteString(cbTrav);
	}
	CString textString;
	m_cbAttrName.GetWindowText(textString);
	m_cbAttrName.AddString(textString);
	if(textString.GetLength()>0)
	{
		CString lowerTextString=textString;
		lowerTextString=lowerTextString.MakeLower();
		NodeStringMap::iterator iter;
		for(iter=m_attrNameMap.begin();iter!=m_attrNameMap.end();iter++)
		{
			CString lowerIterString=*const_cast<CString*>(&(iter->first));
			lowerIterString=lowerIterString.MakeLower();
			if( lowerIterString.Find(lowerTextString.GetString())!=-1)
			{
				m_cbAttrName.AddString(iter->first.GetString());
			}
		}
	}
	else
	{
		NodeStringMap::iterator iter;
		for(iter=m_attrNameMap.begin();iter!=m_attrNameMap.end();iter++)
		{
			m_cbAttrName.AddString(iter->first.GetString());
		}
	}
	if(m_cbAttrName.GetCount())
		m_cbAttrName.ShowDropDown(TRUE);
	else
		m_cbAttrName.ShowDropDown(FALSE);
	m_cbAttrName.SetEditSel(-1,textString.GetLength());
}

void CEpXMLBuilderDlg::OnCbnEditchangeCbAttrValue()
{
	// TODO: Add your control notification handler code here

	int cbBoxCnt=m_cbAttrValue.GetCount();
	for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
	{
		m_cbAttrValue.DeleteString(cbTrav);
	}

	CString nameTextString;
	CString valueTextString;
	m_cbAttrName.GetWindowText(nameTextString);
	m_cbAttrValue.GetWindowText(valueTextString);
	m_cbAttrValue.AddString(valueTextString);
	CString lowerValueTextString=valueTextString;
	lowerValueTextString=lowerValueTextString.MakeLower();
	if(nameTextString.GetLength()>0)
	{
		NodeStringMap::iterator iter=m_attrNameMap.find(nameTextString);
		if(iter!=m_attrNameMap.end())
		{
			if(valueTextString.GetLength()>0)
			{
				for(int trav=0;trav<iter->second.size();trav++)
				{
					CString lowerIterString=*const_cast<CString*>(&(iter->second.at(trav)));
					lowerIterString=lowerIterString.MakeLower();
					if(lowerIterString.Find(lowerValueTextString.GetString())!=-1)
					{
						m_cbAttrValue.AddString(iter->second.at(trav).GetString());
					}
				}
			}
			else
			{
				for(int trav=0;trav<iter->second.size();trav++)
				{
					m_cbAttrValue.AddString(iter->second.at(trav).GetString());
				}
			}

		}

	}
	if(m_cbAttrValue.GetCount())
		m_cbAttrValue.ShowDropDown(TRUE);
	else
		m_cbAttrValue.ShowDropDown(FALSE);
	m_cbAttrValue.SetEditSel(-1,valueTextString.GetLength());
}

CString CEpXMLBuilderDlg::nodeFormat(CString nodeName, CString nodeValue)
{
	CString treeElemString=_T("<name = ");
	treeElemString.Append(nodeName);
	if(nodeValue.GetLength()>0)
	{
		treeElemString.AppendFormat(_T(" value = "));
		treeElemString.Append(nodeValue);
	}
	treeElemString.AppendFormat(_T(" >"));
	return treeElemString;

}

CString CEpXMLBuilderDlg::attrFormat(CString attrName, CString attrValue)
{
	CString treeElemString=_T("<attrName = ");
	treeElemString.Append(attrName);
	if(attrValue.GetLength()>0)
	{
		treeElemString.AppendFormat(_T(" value = "));
		treeElemString.Append(attrValue);
	}
	treeElemString.AppendFormat(_T(" >"));
	return treeElemString;
}

void CEpXMLBuilderDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString rootName;
	CString rootValue;
	m_tbRoot.GetWindowText(rootName);
	m_tbRootValue.GetWindowText(rootValue);
	if(rootName.GetLength()<=0)
	{
		MessageBox(_T("Invalid Rootname!\n\nPlease try again."),_T("Error"),MB_OK);
		m_tbRoot.SetFocus();
		m_tbRoot.SetSel(0,-1);
	}

	m_rootName=nodeFormat(rootName,rootValue);
	XNode *node= &m_xmlFile;
	node->m_name=rootName;
	node->m_value=rootValue;

	HTREEITEM rootItem=m_treeXML.GetFirstVisibleItem();
	m_treeXML.SetItemText(rootItem,m_rootName.GetString());
	m_isChanged=true;

}

void CEpXMLBuilderDlg::OnBnClickedBtnAdd()
{
	if(m_selectedTreeItem==NULL)
	{
		MessageBox(_T("Node is not selected from the tree!\n\nPlease select a node to add the node under."),_T("Error"),MB_OK);
		return;
	}
	CString nodeName,nodeValue;
	m_cbNodeName.GetWindowText(nodeName);
	m_cbNodeValue.GetWindowText(nodeValue);
	if(nodeName.GetLength()<=0)
	{
		MessageBox(_T("Node Name is NULL!\n\nPlease input Node Name."),_T("Warning"),MB_OK);
		m_cbNodeName.SetFocus();
		m_cbNodeName.SetEditSel(0,-1);
		return;
	}

	
	CString treeElemString=nodeFormat(nodeName,nodeValue);

	TreeNodeMap::iterator nodeIter=m_treeNodeMap.find(m_selectedTreeItem);
	if(nodeIter==m_treeNodeMap.end() && m_treeXML.GetItemText(m_selectedTreeItem).Compare(m_rootName)!=0)
	{
		MessageBox(_T("Cannot attach the node/attribute to an Attibute element. Please select the node to insert under."),_T("Error"),MB_OK);
		return;
	}


	HTREEITEM insertedItem=m_treeXML.InsertItem(treeElemString.GetString(),m_selectedTreeItem,TVI_LAST);

	if(m_treeXML.GetItemText(m_selectedTreeItem).Compare(m_rootName)==0)
	{
		XNode* insertedNode=m_xmlFile.AppendChild(nodeName.GetString(),nodeValue.GetString());
		m_treeNodeMap[insertedItem]=insertedNode;
	}
	else
	{
		TreeNodeMap::iterator iter=m_treeNodeMap.find(m_selectedTreeItem);
		XNode* insertedNode=iter->second->AppendChild(nodeName.GetString(),nodeValue.GetString());
		m_treeNodeMap[insertedItem]=insertedNode;
	}
	m_treeXML.Expand(m_selectedTreeItem,TVE_EXPAND);
	
	m_isChanged=true;
	m_cbNodeName.SetFocus();
}




void CEpXMLBuilderDlg::OnBnClickedBtnAddAttr()
{
	// TODO: Add your control notification handler code here

	if(m_selectedTreeItem==NULL)
	{
		MessageBox(_T("Node is not selected from the tree!\n\nPlease select a node to add the attribute under."),_T("Error"),MB_OK);
		return;
	}
	CString attrName,attrValue;
	m_cbAttrName.GetWindowText(attrName);
	m_cbAttrValue.GetWindowText(attrValue);
	if(attrName.GetLength()<=0)
	{
		MessageBox(_T("Attribute Name is NULL!\n\nPlease input Attribute Name."),_T("Warning"),MB_OK);
		m_cbAttrName.SetFocus();
		m_cbAttrName.SetEditSel(0,-1);
		return;
	}


	TreeNodeMap::iterator nodeIter=m_treeNodeMap.find(m_selectedTreeItem);
	if(nodeIter==m_treeNodeMap.end() && m_treeXML.GetItemText(m_selectedTreeItem).Compare(m_rootName)!=0)
	{
		MessageBox(_T("Cannot attach the node/attribute to an Attibute element. Please select the node to insert under."),_T("Error"),MB_OK);
		return;
	}

	CString treeElemString=attrFormat(attrName,attrValue);
	HTREEITEM insertedItem=m_treeXML.InsertItem(treeElemString.GetString(),m_selectedTreeItem,TVI_LAST);

	if(m_treeXML.GetItemText(m_selectedTreeItem).Compare(m_rootName)==0)
	{
		XAttr* insertedAttr=m_xmlFile.AppendAttr(attrName.GetString(),attrValue.GetString());
		m_treeAttrMap[insertedItem]=insertedAttr;
	}
	else
	{
		XAttr* insertedAttr=nodeIter->second->AppendAttr(attrName.GetString(),attrValue.GetString());
		m_treeAttrMap[insertedItem]=insertedAttr;
	}
	m_treeXML.Expand(m_selectedTreeItem,TVE_EXPAND);

	m_isChanged=true;
	m_cbAttrName.SetFocus();
}

void CEpXMLBuilderDlg::OnBnClickedBtnDelete()
{
	if(m_selectedTreeItem==NULL)
	{
		MessageBox(_T("Node/Attribute is not selected from the tree!\n\nPlease select a node or an attribute to delete."),_T("Error"),MB_OK);
		return;
	}
	if(m_treeXML.GetItemText(m_selectedTreeItem).Compare(m_rootName)==0)
	{
		MessageBox(_T("Root node cannot be deleted!\n\nPlease select other node to delete."),_T("Error"),MB_OK);
		return;
	}
	if(MessageBox(_T("Do you really want to delete the node/attribute and its sub-nodes?"),_T("Warning"),MB_YESNO)==IDNO)
		return;
	TreeNodeMap::iterator iter=m_treeNodeMap.find(m_selectedTreeItem);
	if(iter!=m_treeNodeMap.end())
	{
		iter->second->m_parent->RemoveChild(iter->second);
		m_treeNodeMap.erase(iter);
	}
	else
	{
		TreeAttrMap::iterator attrIter=m_treeAttrMap.find(m_selectedTreeItem);
		if(attrIter!=m_treeAttrMap.end())
		{
			attrIter->second->m_parent->RemoveAttr(attrIter->second);
			m_treeAttrMap.erase(attrIter);
		}
		else
		{
			EP_ASSERT(0);
		}
	}
	

	HTREEITEM prevItem=m_treeXML.GetPrevVisibleItem(m_selectedTreeItem);
	m_treeXML.DeleteItem(m_selectedTreeItem);

	
	m_treeXML.SelectItem(prevItem);

	m_isChanged=true;
	m_selectedTreeItem=prevItem;

	m_treeXML.SetFocus();
}


void CEpXMLBuilderDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	m_selectedTreeItem = m_treeXML.GetSelectedItem();
}

void CEpXMLBuilderDlg::OnTvnKeydownTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
	*pResult = 0;
	NMTVKEYDOWN * pKey = (NMTVKEYDOWN *)pNMHDR;

	HTREEITEM hSel = m_treeXML.GetSelectedItem();
	if (pKey->wVKey == VK_DELETE && hSel != NULL)
	{
		OnBnClickedBtnDelete();
	}
}

BOOL CEpXMLBuilderDlg::PreTranslateMessage(MSG* pMsg)
{
	// ENTER key
	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == VK_RETURN))
	{
		// Enter key was hit -> do whatever you want
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnAddAttr();
			return TRUE;
		}
		else
		{
			OnBnClickedBtnAdd();
			return TRUE;
		}
		
	}
	
	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x53)) //S
	{
		if((GetKeyState(VK_SHIFT) & 0x8000)&& (GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnSaveAs();
			return TRUE;
		}

	}

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x53)) //S
	{
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnSave();
			return TRUE;
		}

	}

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x4C)) //L
	{
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnLoad();
			return TRUE;
		}

	}

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x4E)) //N
	{
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedBtnNew();
			return TRUE;
		}

	}

	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x43)) //C
	{
		if((GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedButton1();
			return TRUE;
		}

	}

	return CDialog::PreTranslateMessage(pMsg);
}




void CEpXMLBuilderDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnClose();
}

void CEpXMLBuilderDlg::OnBnClickedCancel()
{
	if(!continueOnChanged())
		return;
	// TODO: Add your control notification handler code here
	if(MessageBox(_T("Do you really want to exit the XML Builder?"),_T("Warning"),MB_YESNO)==IDNO)
	{
		return;
	}
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CEpXMLBuilderDlg::OnBnClickedBtnLoadPreText()
{
	// TODO: Add your control notification handler code here
	CString iniFileName;

	CFileDialog fileDialog(TRUE,_T("ini"),NULL,OFN_FILEMUSTEXIST,_T("INI Files (*.ini)|*.ini|All Files (*.*)|*.*||"),this );
	fileDialog.m_pOFN->lpstrTitle=_T("Pre Text Data File");
	fileDialog.m_pOFN->lpstrInitialDir=_T("c:");
	int result = fileDialog.DoModal();
	if(result==IDOK && fileDialog.GetPathName().GetLength()>0)
	{
		iniFileName=fileDialog.GetPathName();
	}
	else
		return;


	
	m_nodeNameMap.clear();
	m_attrNameMap.clear();

	iniFileName=fileDialog.GetPathName();
	if(m_textFile.LoadFromFile(iniFileName.GetString()))
	{
		PreTestParser::Parse(m_textFile,m_nodeNameMap, m_attrNameMap);
	}
}

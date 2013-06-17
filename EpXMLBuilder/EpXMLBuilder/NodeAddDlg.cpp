// NodeAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "NodeAddDlg.h"
#include "epXMLUtil.h"
#include "ConfigureValidatorDlg.h"

// CNodeAddDlg dialog

IMPLEMENT_DYNAMIC(CNodeAddDlg, CDialog)

CNodeAddDlg::CNodeAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNodeAddDlg::IDD, pParent)
{

}

CNodeAddDlg::~CNodeAddDlg()
{
}

void CNodeAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBB_NAME, m_cbbName);
	DDX_Control(pDX, IDC_CBB_VALUE, m_cbbValue);
}


BEGIN_MESSAGE_MAP(CNodeAddDlg, CDialog)
	ON_CBN_EDITCHANGE(IDC_CBB_NAME, &CNodeAddDlg::OnCbnEditchangeCbbName)
	ON_CBN_EDITCHANGE(IDC_CBB_VALUE, &CNodeAddDlg::OnCbnEditchangeCbbValue)
	ON_BN_CLICKED(IDC_BUTTON1, &CNodeAddDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CNodeAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CNodeAddDlg message handlers

BOOL CNodeAddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	if(m_isNode)
		this->SetWindowText(_T("Node Add"));
	else
		this->SetWindowText(_T("Attribute Add"));
	m_cbbName.SetFocus();
	return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNodeAddDlg::OnCbnEditchangeCbbName()
{
	// TODO: Add your control notification handler code here

	if(m_isNode)
	{
		int cbBoxCnt=m_cbbName.GetCount();
		for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
		{
			m_cbbName.DeleteString(cbTrav);
		}
		CString textString;
		m_cbbName.GetWindowText(textString);
		m_cbbName.AddString(textString);
		if(textString.GetLength()>0)
		{
			CString lowerTextString=textString;
			lowerTextString=lowerTextString.MakeLower();
			NodeStringMap::iterator iter;
			for(iter=m_nameMap.begin();iter!=m_nameMap.end();iter++)
			{
				CString lowerIterString=*const_cast<CString*>(&(iter->first));
				lowerIterString=lowerIterString.MakeLower();

				if( lowerIterString.Find(lowerTextString.GetString())!=-1)
				{
					m_cbbName.AddString(iter->first.GetString());
				}
			}
		}
		else
		{
			NodeStringMap::iterator iter;
			for(iter=m_nameMap.begin();iter!=m_nameMap.end();iter++)
			{
				m_cbbName.AddString(iter->first.GetString());
			}
		}
		if(m_cbbName.GetCount())
			m_cbbName.ShowDropDown(TRUE);
		else
			m_cbbName.ShowDropDown(FALSE);
		m_cbbName.SetEditSel(-1,textString.GetLength());
	}
	else
	{
		int cbBoxCnt=m_cbbName.GetCount();
		for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
		{
			m_cbbName.DeleteString(cbTrav);
		}
		CString textString;
		m_cbbName.GetWindowText(textString);
		m_cbbName.AddString(textString);
		if(textString.GetLength()>0)
		{
			CString lowerTextString=textString;
			lowerTextString=lowerTextString.MakeLower();
			NodeStringMap::iterator iter;
			for(iter=m_nameMap.begin();iter!=m_nameMap.end();iter++)
			{
				CString lowerIterString=*const_cast<CString*>(&(iter->first));
				lowerIterString=lowerIterString.MakeLower();
				if( lowerIterString.Find(lowerTextString.GetString())!=-1)
				{
					m_cbbName.AddString(iter->first.GetString());
				}
			}
		}
		else
		{
			NodeStringMap::iterator iter;
			for(iter=m_nameMap.begin();iter!=m_nameMap.end();iter++)
			{
				m_cbbName.AddString(iter->first.GetString());
			}
		}
		if(m_cbbName.GetCount())
			m_cbbName.ShowDropDown(TRUE);
		else
			m_cbbName.ShowDropDown(FALSE);
		m_cbbName.SetEditSel(-1,textString.GetLength());
	}
	
}

void CNodeAddDlg::OnCbnEditchangeCbbValue()
{
	// TODO: Add your control notification handler code here
	if(m_isNode)
	{
		int cbBoxCnt=m_cbbValue.GetCount();
		for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
		{
			m_cbbValue.DeleteString(cbTrav);
		}
		CString nameTextString;
		CString valueTextString;
		m_cbbName.GetWindowText(nameTextString);
		m_cbbValue.GetWindowText(valueTextString);
		m_cbbValue.AddString(valueTextString);
		CString lowerValueTextString=valueTextString;
		lowerValueTextString=lowerValueTextString.MakeLower();
		if(nameTextString.GetLength()>0)
		{
			NodeStringMap::iterator iter=m_nameMap.find(nameTextString);
			if(iter!=m_nameMap.end())
			{
				if(valueTextString.GetLength()>0)
				{
					for(int trav=0;trav<iter->second.size();trav++)
					{
						CString lowerIterString=*const_cast<CString*>(&(iter->second.at(trav)));
						lowerIterString=lowerIterString.MakeLower();
						if(lowerIterString.Find(lowerValueTextString.GetString())!=-1)
						{
							m_cbbValue.AddString(iter->second.at(trav).GetString());
						}
					}
				}
				else
				{
					for(int trav=0;trav<iter->second.size();trav++)
					{
						m_cbbValue.AddString(iter->second.at(trav).GetString());
					}
				}

			}

		}
		if(m_cbbValue.GetCount())
			m_cbbValue.ShowDropDown(TRUE);
		else
			m_cbbValue.ShowDropDown(FALSE);
		m_cbbValue.SetEditSel(-1,valueTextString.GetLength());
	}
	else
	{
		int cbBoxCnt=m_cbbValue.GetCount();
		for(int cbTrav=cbBoxCnt-1;cbTrav>=0;cbTrav--)
		{
			m_cbbValue.DeleteString(cbTrav);
		}

		CString nameTextString;
		CString valueTextString;
		m_cbbName.GetWindowText(nameTextString);
		m_cbbValue.GetWindowText(valueTextString);
		m_cbbValue.AddString(valueTextString);
		CString lowerValueTextString=valueTextString;
		lowerValueTextString=lowerValueTextString.MakeLower();
		if(nameTextString.GetLength()>0)
		{
			NodeStringMap::iterator iter=m_nameMap.find(nameTextString);
			if(iter!=m_nameMap.end())
			{
				if(valueTextString.GetLength()>0)
				{
					for(int trav=0;trav<iter->second.size();trav++)
					{
						CString lowerIterString=*const_cast<CString*>(&(iter->second.at(trav)));
						lowerIterString=lowerIterString.MakeLower();
						if(lowerIterString.Find(lowerValueTextString.GetString())!=-1)
						{
							m_cbbValue.AddString(iter->second.at(trav).GetString());
						}
					}
				}
				else
				{
					for(int trav=0;trav<iter->second.size();trav++)
					{
						m_cbbValue.AddString(iter->second.at(trav).GetString());
					}
				}

			}

		}
		if(m_cbbValue.GetCount())
			m_cbbValue.ShowDropDown(TRUE);
		else
			m_cbbValue.ShowDropDown(FALSE);
		m_cbbValue.SetEditSel(-1,valueTextString.GetLength());
	}
	
}

void CNodeAddDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CConfigureValidatorDlg configureValidatorDlg;
	configureValidatorDlg.DoModal();
}

void CNodeAddDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	m_cbbName.GetWindowText(m_nameString);
	m_cbbValue.GetWindowText(m_valueString);

	if(m_isNode)
	{
	

		CString message;
		ValidState state=XMLUtil::ValidateName(m_nameString,message);
		if(state==VALID_STATE_INVALID)
		{
			MessageBox(message,_T("Error"),MB_OK);
			m_cbbName.SetFocus();
			m_cbbName.SetEditSel(0,-1);
			return;
		}
		else if(state==VALID_STATE_WARNING)
		{
			message.Append(_T("Proceed?"));
			if(MessageBox(message,_T("Warning"),MB_YESNO)==IDNO)
			{
				m_cbbName.SetFocus();
				m_cbbName.SetEditSel(0,-1);
				return;
			}
		}
	}
	else
	{
		

		CString message;
		ValidState state;
		state=XMLUtil::ValidateName(m_nameString,message,false,m_parentNode);
		if(state==VALID_STATE_INVALID)
		{
			MessageBox(message,_T("Error"),MB_OK);
			m_cbbName.SetFocus();
			m_cbbName.SetEditSel(0,-1);
			return;
		}
		else if(state==VALID_STATE_WARNING)
		{
			message.Append(_T("Proceed?"));
			if(MessageBox(message,_T("Warning"),MB_YESNO)==IDNO)
			{
				m_cbbName.SetFocus();
				m_cbbName.SetEditSel(0,-1);
				return;
			}
		}
	}

		OnOK();
}

BOOL CNodeAddDlg::PreTranslateMessage(MSG* pMsg)
{
	if((pMsg->message == WM_KEYDOWN) && 
		(pMsg->wParam == 0x43)) //C
	{
		if((GetKeyState(VK_SHIFT) & 0x8000)&& (GetKeyState(VK_CONTROL) & 0x8000))
		{
			OnBnClickedButton1();
			return TRUE;
		}

	}


	return CDialog::PreTranslateMessage(pMsg);
}

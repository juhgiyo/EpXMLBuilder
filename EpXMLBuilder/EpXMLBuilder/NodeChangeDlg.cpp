/*! 
CNodeChangeDlg for the EpXMLBuilder

The MIT License (MIT)

Copyright (c) 2012-2013 Woong Gyu La <juhgiyo@gmail.com>

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
*/

#include "stdafx.h"
#include "EpXMLBuilder.h"
#include "NodeChangeDlg.h"
#include "EpXMLBuilderDlg.h"

// CNodeChangeDlg dialog

IMPLEMENT_DYNAMIC(CNodeChangeDlg, CDialog)

CNodeChangeDlg::CNodeChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNodeChangeDlg::IDD, pParent)
{

}

CNodeChangeDlg::~CNodeChangeDlg()
{
}

void CNodeChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_NAME, m_tbName);
	DDX_Control(pDX, IDC_TB_VALUE, m_tbValue);
}


BEGIN_MESSAGE_MAP(CNodeChangeDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CNodeChangeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CNodeChangeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNodeChangeDlg message handlers
BOOL CNodeChangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_tbName.SetWindowText(m_nameString.GetString());
	m_tbValue.SetWindowText(m_valueString.GetString());
	m_tbName.SetFocus();
	m_tbName.SetSel(0,-1);
	return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CNodeChangeDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_tbName.GetWindowText(m_nameString);
	m_tbValue.GetWindowText(m_valueString);
	m_nameString=m_nameString.Trim();
	m_valueString=m_valueString.Trim();
	CString retMessage;	
	ValidState state= XMLUtil::ValidateName(m_nameString,retMessage,m_isNode,m_parentNode,m_attr);
	if(state==VALID_STATE_INVALID)
	{
		MessageBox(retMessage,_T("Error"),MB_OK);
		m_tbName.SetFocus();
		m_tbName.SetSel(0,-1);
		return;
	}
	else if(state==VALID_STATE_WARNING)
	{
		retMessage.Append(_T("Proceed?"));
		if(MessageBox(retMessage,_T("Warning"),MB_YESNO)==IDNO)
		{
			m_tbName.SetFocus();
			m_tbName.SetSel(0,-1);
			return;
		}
	}

	OnOK();
}

void CNodeChangeDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CConfigureValidatorDlg configureValidatorDlg;
	configureValidatorDlg.DoModal();
}


BOOL CNodeChangeDlg::PreTranslateMessage(MSG* pMsg)
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
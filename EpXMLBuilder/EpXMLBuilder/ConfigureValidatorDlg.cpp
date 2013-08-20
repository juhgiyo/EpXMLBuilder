/*! 
CConfigureValidatorDlg for the EpXMLBuilder

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
#include "ConfigureValidatorDlg.h"
#include "epXMLValidatorProperties.h"

// CConfigureValidatorDlg dialog

IMPLEMENT_DYNAMIC(CConfigureValidatorDlg, CDialog)

CConfigureValidatorDlg::CConfigureValidatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigureValidatorDlg::IDD, pParent)
{

}

CConfigureValidatorDlg::~CConfigureValidatorDlg()
{
}

void CConfigureValidatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_NUMBER, m_cbNumber);
	DDX_Control(pDX, IDC_CB_XML, m_cbXML);
	DDX_Control(pDX, IDC_CB_SPACE, m_cbSpace);
	DDX_Control(pDX, IDC_CB_DASH, m_cbDash);
	DDX_Control(pDX, IDC_CB_COLON, m_cbColon);
	DDX_Control(pDX, IDC_CB_PERIOD, m_cbPeriod);
	DDX_Control(pDX, IDC_CB_DUPLICATE, m_cbDuplicate);
}



BEGIN_MESSAGE_MAP(CConfigureValidatorDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CConfigureValidatorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CConfigureValidatorDlg message handlers
BOOL CConfigureValidatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckNumber())
		m_cbNumber.SetCheck(BST_CHECKED);
	else
		m_cbNumber.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckStartWithXML())
		m_cbXML.SetCheck(BST_CHECKED);
	else
		m_cbXML.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckContainSpace())
		m_cbSpace.SetCheck(BST_CHECKED);
	else
		m_cbSpace.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldCheckDuplicate())
		m_cbDuplicate.SetCheck(BST_CHECKED);
	else
		m_cbDuplicate.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainDash())
		m_cbDash.SetCheck(BST_CHECKED);
	else
		m_cbDash.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainPeriod())
		m_cbPeriod.SetCheck(BST_CHECKED);
	else
		m_cbPeriod.SetCheck(BST_UNCHECKED);

	if(XML_VALIDATOR_PROPERTIES_INSTANCE.ShouldWarnContainColon())
		m_cbColon.SetCheck(BST_CHECKED);
	else
		m_cbColon.SetCheck(BST_UNCHECKED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CConfigureValidatorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldCheckNumber(m_cbNumber.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldCheckStartWithXML(m_cbXML.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldCheckContainSpace(m_cbSpace.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldCheckDuplicate(m_cbDuplicate.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldWarnContainDash(m_cbDash.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldWarnContainPeriod(m_cbPeriod.GetCheck()==BST_CHECKED);
	XML_VALIDATOR_PROPERTIES_INSTANCE.SetShouldWarnContainColon(m_cbColon.GetCheck()==BST_CHECKED);

	OnOK();
}

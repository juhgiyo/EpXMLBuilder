/*! 
@file ConfigureValidatorDlg.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief Configure Validator Dialog Interface
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

An Interface for the Configure Validator Dialog.

*/
#pragma once
#include "afxwin.h"


// CConfigureValidatorDlg dialog

class CConfigureValidatorDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigureValidatorDlg)

public:
	CConfigureValidatorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConfigureValidatorDlg();

// Dialog Data
	enum { IDD = IDD_VALIDATOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_cbNumber;
	CButton m_cbXML;
	CButton m_cbSpace;
	CButton m_cbDash;
	CButton m_cbColon;
	CButton m_cbPeriod;

	afx_msg void OnBnClickedOk();
	CButton m_cbDuplicate;
};

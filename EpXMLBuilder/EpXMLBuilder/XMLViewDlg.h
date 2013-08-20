/*! 
@file XMLViewDlg.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief XML View Dialog Interface
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

An Interface for the XML View Dialog.

*/
#pragma once
#include "afxwin.h"


// CXMLViewDlg dialog

class CXMLViewDlg : public CDialog
{
	DECLARE_DYNAMIC(CXMLViewDlg)

public:
	CXMLViewDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXMLViewDlg();

// Dialog Data
	enum { IDD = IDD_VIEW_XML };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_xmlString;
	CString m_xmlStringSingle;
	CEdit m_tbXML;
	afx_msg void OnBnClickedCbSingle();
	CButton m_cbSingleLine;
	afx_msg void OnBnClickedBtnWinservice();
	CButton m_btnWinServiceCLI;
};

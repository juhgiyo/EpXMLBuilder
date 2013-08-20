/*! 
@file InitialCommandLineInfo.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief Initial Command-Line Info Interface
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

An Interface for the Initial Command-Line Info.

*/
#ifndef __INITIAL_COMMAND_LINE_INFO_H__
#define __INITIAL_COMMAND_LINE_INFO_H__

/*! 
@class InitialCommandLineInfo InitialCommandLineInfo.h
@brief A class for Initial Command Line Info.
*/
class InitialCommandLineInfo : public CCommandLineInfo
{
	
public:
	/*!
	Default Constructor

	Initializes the Worker
	*/
	InitialCommandLineInfo():CCommandLineInfo()
	{
		m_isWinService=false;
	}

	/*!
	Parse the command line argument
	@param[in] pszParam the parameter string
	@param[in] bFlag the flag
	@param[in] bLast the last flag
	*/
	virtual void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);

#ifdef UNICODE
	/*!
	Parse the command line argument for Unicode
	@param[in] pszParam the parameter string
	@param[in] bFlag the flag
	@param[in] bLast the last flag
	*/
	virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
#endif 

	/*!
	Check if the server should auto-start
	@return true if the server should auto-start otherwise false
	*/
	bool IsWinService() {return m_isWinService;}

private:
	/// auto-start flag
	bool m_isWinService;
};
#endif //__INITIAL_COMMAND_LINE_INFO_H__
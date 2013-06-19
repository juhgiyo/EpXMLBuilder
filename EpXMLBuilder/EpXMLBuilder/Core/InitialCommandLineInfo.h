/*! 
@file InitialCommandLineInfo.h
@brief An Initial Command Line Info Interface

An Interface for Initial Command Line Info
@author Woong Gyu La a.k.a Chris.
@date February 13, 2012
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
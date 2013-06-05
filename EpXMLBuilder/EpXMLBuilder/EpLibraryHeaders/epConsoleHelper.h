/*! 
@file epConsoleHelper.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date October 01, 2011
@brief Console Processing Function Class Interface
@version 2.0

@section LICENSE

Copyright (C) 2012  Woong Gyu La <juhgiyo@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

@section DESCRIPTION

An Interface for the Console Processing Operation.

*/
#ifndef __EP_CONSOLE_HELPER_H__
#define __EP_CONSOLE_HELPER_H__
#include "epLib.h"
#include "epSystem.h"

namespace epl
{
	/*! 
	@class ConsoleHelper epConsoleHelper.h
	@brief This is a class for Console Processing Class

	Implements the Console Processing Functions.
	*/
	class EP_LIBRARY ConsoleHelper
	{
	public:
		/*!
		Execute the given command to the console and return the result

		** waitStruct is ignored when isWaitForTerminate is false.
		@param[in] command the command to execute
		@param[in] isDosCommand flag whether the command is standard DOS command or not
		@param[in] isWaitForTerminate flag for waiting for process to terminate or not
		@param[in] isShowWindow flag for whether to show console window
		@param[in] useStdOutput flag for whether console to print to console window or to pipe.<br/>
		                        true to print to pipe; false to print to console.
		@param[in] priority the priority of the process executing
		@param[out] retProcessHandle the handle to the process created
		@return the result of the console command
		@remark retProcessHandle will be NULL when the function exits.
		        This can be used when isWaitForTerminate is true, and you need to terminate the process while waiting.
				Terminate the process from the other thread using the given handle pointer.
		*/
		static EpTString ExecuteConsoleCommand(const TCHAR * command, bool isDosCommand=false, bool isWaitForTerminate=true, bool isShowWindow=false,bool useStdOutput=true,  ConsolePriority priority=CONSOLE_PRIORITY_NORMAL, HANDLE *retProcessHandle=NULL);

		/*!
		Execute the given executable file
		@param[in] execFilePath the program file path to execute
		@param[in] parameters the parameter variables for executing file
		*/
		static void ExecuteProgram(const TCHAR *execFilePath, const TCHAR *parameters=NULL);
	};
}


#endif //__EP_CONSOLE_HELPER_H__
/*! 
@file epWorkerThreadInfinite.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date July 07, 2010
@brief Worker Thread Class Interface with infinite loop.
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

A Interface for Infinite-looping Worker Thread Class.

*/
#ifndef __EP_WORKER_THREAD_INFINITE_H__
#define __EP_WORKER_THREAD_INFINITE_H__
#include "epLib.h"
#include "epWorkerThreadFactory.h"
#include "epCriticalSectionEx.h"
#include "epBaseJobProcessor.h"
#include "epEventEx.h"

namespace epl
{
	/*! 
	@class WorkerThreadInfinite epWorkerThreadInfinite.h
	@brief A class that implements infinite-looping Worker Thread Class.
	*/
	class EP_LIBRARY WorkerThreadInfinite:public BaseWorkerThread
	{
	public:
		/*!
		Default Constructor

		Initializes the thread class
		@param[in] policy the life policy of this worker thread.
		*/
		WorkerThreadInfinite(const ThreadLifePolicy policy);

		/*!
		Default Copy Constructor

		Initializes the Thread class
		@param[in] b the second object
		*/
		WorkerThreadInfinite(const WorkerThreadInfinite & b);

		/*!
		Default Destructor

		Destroy the Thread Class
		*/
		virtual ~WorkerThreadInfinite(){};

		/*!
		Assignment operator overloading
		@param[in] b the second object
		@return the new copied object
		*/
		WorkerThreadInfinite &operator=(const WorkerThreadInfinite & b)
		{
			if(this!=&b)
			{
				BaseWorkerThread::operator =(b);
			}
			return *this;
		}

		/*!
		Wait for worker thread to terminate, and if not terminated, then Terminate.
		@param[in] waitTimeInMilliSec the time-out interval, in milliseconds.
		@return the terminate result of the thread
		*/
		TerminateResult TerminateWorker(unsigned int waitTimeInMilliSec=WAITTIME_INIFINITE);

	protected:
		/*!
		Actual infinite-looping Thread Code.
		*/
		virtual void execute();

	private:
		/// Terminate Signal Event
		EventEx m_terminateEvent;

	};

}

#endif //__EP_WORKER_THREAD_INFINITE_H__
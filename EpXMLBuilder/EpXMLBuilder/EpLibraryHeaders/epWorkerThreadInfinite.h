/*! 
@file epWorkerThreadInfinite.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date July 07, 2010
@brief Worker Thread Class Interface with infinite loop.
@version 2.0

@section LICENSE

The MIT License (MIT)

Copyright (c) 2008-2013 Woong Gyu La <juhgiyo@gmail.com>

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
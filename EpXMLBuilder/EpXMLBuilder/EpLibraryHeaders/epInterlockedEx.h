/*! 
@file epInterlockedEx.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date August 04, 2012
@brief InterlockedEx Interface
@version 2.0

@section LICENSE

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

@section DESCRIPTION

An Interface for InterlockedEx Class.

*/
#ifndef __EP_INTERLOCKED_EX_H__
#define __EP_INTERLOCKED_EX_H__

#include "epLib.h"
#include "epSystem.h"
#include "epBaseLock.h"


namespace epl
{
	/*! 
	@class InterlockedEx epInterlockedEx.h
	@brief A class that handles the Interlocked functionality.
	*/
	class EP_LIBRARY InterlockedEx :public BaseLock
	{
	public:
		/*!
		Default Constructor

		Initializes the lock.
		*/
		InterlockedEx();

		/*!
		Default Copy Constructor

		Initializes the Semaphore
		@param[in] b the second object
		*/
		InterlockedEx(const InterlockedEx& b);

		/*!
		Default Destructor

		Deletes the lock
		*/
		virtual ~InterlockedEx();

		/*!
		Assignment operator overloading
		@param[in] b the second object
		@return the new copied object
		*/
		InterlockedEx & operator=(const InterlockedEx&b);

		/*!
		Locks the Critical Section
		@return true if locked, false otherwise
		*/
		virtual bool Lock();

		/*!
		Try to Lock the Critical Section

		If other thread is already in the Critical Section, it just returns false and continue, otherwise obtain the Critical Section.
		@return true if the lock is succeeded, otherwise false.
		*/
		virtual long TryLock();

		/*!
		Locks the Critical Section

		if other thread is already in the Critical Section,
		and if it fails to lock in given time, it returns false, otherwise lock and return true.
		@param[in] dwMilliSecond the wait time.
		@return true if the lock is succeeded, otherwise false.
		*/
		virtual long TryLockFor(const unsigned int dwMilliSecond);

		/*!
		Leave the Critical Section

		The Lock and Unlock has to be matched for each Critical Section.
		*/
		virtual void Unlock();

	private:
		/// Actual Semaphore		
		volatile long m_interLock;
#if defined(_DEBUG) && defined(ENABLE_POSSIBLE_DEADLOCK_CHECK)
		/// thread ID that currently holding this interlock
		unsigned long m_threadID;
		/// Semaphore Debug	
		volatile long m_interLockDebug;
#endif //defined(_DEBUG) && defined(ENABLE_POSSIBLE_DEADLOCK_CHECK)
	};

}

#endif //__EP_INTERLOCKED_EX_H__
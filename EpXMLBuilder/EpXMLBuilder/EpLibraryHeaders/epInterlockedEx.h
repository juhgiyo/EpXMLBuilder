/*! 
@file epInterlockedEx.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date August 04, 2012
@brief InterlockedEx Interface
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
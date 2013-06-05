/*! 
@file epDynamicArray.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date August 08, 2010
@brief Dynamic Array Data Structure Interface
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

An Interface for Dynamic Array Data Structure.

*/
#ifndef __EP_DYNAMIC_ARRAY_H__
#define __EP_DYNAMIC_ARRAY_H__

#include "epLib.h"
#include "epCriticalSectionEx.h"
#include "epMutex.h"
#include "epNoLock.h"
#include "epException.h"

namespace epl
{
	/*! 
	@class DynamicArray epDynamicArray.h
	@brief A template class for Dynamic Array.
	*/
	template <typename DataType>
	class DynamicArray
	{
	public:
		/*!
		Default Constructor

		Initializes the Dynamic Array
		@param[in] initialSize The initial size of the array
		@param[in] lockPolicyType The lock policy
		*/
		DynamicArray(size_t initialSize=0,LockPolicy lockPolicyType=EP_LOCK_POLICY);

		/*!
		Default Constructor

		Initializes the Dynamic Array with given array
		@param[in] dArr the Dynamic Array Object to copy from
		*/
		DynamicArray(const DynamicArray<DataType> &dArr);

		/*!
		Default Destructor

		Destroys the Dynamic Array
		*/
		virtual ~DynamicArray();

		/*!
		Delete the given array.
		(Frees the memory)
		*/
		void Delete();

		/*!
		Clear all the elements in the given array.
		(Does Not Free the memory)
		*/
		void Clear();

		/*!
		Check if the given array is empty.
		@return true if the array is empty, false otherwise.
		*/
		bool IsEmpty() const;

		/*!
		Return the number of elements using in the given array.
		@return the number of elements  using in the given array.
		*/
		size_t Size() const;

		/*!
		Resize the given array to given size.
		@param[in] newSize The new size to resize.
		*/
		bool Resize(size_t newSize);

		/*!
		Return the element at the given index of the given array.
		@param[in] idx The index to return the element.
		@return the element at the given index.
		*/
		DataType &At(size_t idx);

		/*!
		Append the element given to the dynamic array given.
		@param[in] data The data to append at the end.
		@return the result dynamic array
		*/
		DynamicArray<DataType> &Append(const DataType &data);

		/*!
		Append the given dynamic array to the this dynamic array.
		@param[in] dArr The dynamic array structure to append.
		@return the result dynamic array
		*/
		DynamicArray<DataType> &Append(const DynamicArray<DataType> &dArr);

		/*!
		Initialize this array to given array
		@param[in] b the dynamic array structure to initialize this array
		@return the result dynamic array
		*/
		DynamicArray<DataType> &operator=(const DynamicArray<DataType>& b);

		/*!
		Return the element at the given index of the given array.
		@param[in] idx The index to return the element.
		@return the element at the given index.
		*/
		DataType& operator[](size_t idx);


		/*!
		Return the element at the given index of the given array.
		@param[in] idx The index to return the element.
		@return the element at the given index.
		*/
		const DataType& operator[](size_t idx) const;


		/*!
		Append the given dynamic array to the this dynamic array.
		@param[in] b The dynamic array structure to append.
		@return the result dynamic array
		*/
		DynamicArray<DataType>& operator+=(const DynamicArray<DataType>& b);

		/*!
		Return new array by appending the given dynamic array to the this dynamic array.
		@param[in] b The dynamic array structure to append.
		@return the new result dynamic array
		*/
		DynamicArray<DataType> operator+(const DynamicArray<DataType>& b) const;

		/*!
		Append the given element to the this dynamic array.
		@param[in] b The element to append.
		@return the result dynamic array
		*/
		DynamicArray<DataType>& operator+=(const DataType& b);

		/*!
		Return new array by appending the given element to the this dynamic array.
		@param[in] b The element to append.
		@return the new result dynamic array
		*/
		DynamicArray<DataType> operator+(const DataType& b) const;
	private:
		/*!
		Actual resize the given array to given size.
		@param[in] newSize The new size to resize.
		*/
		bool resize(size_t newSize);

		/*!
		Actual append the element given to the dynamic array given.
		@param[in] data The data to append at the end.
		@return the result dynamic array
		*/
		DynamicArray<DataType> &append(const DataType &data);

		/*!
		Actual append the given dynamic array to the this dynamic array.
		@param[in] dArr The dynamic array structure to append.
		@return the result dynamic array
		*/
		DynamicArray<DataType> &append(const DynamicArray<DataType> &dArr);

		/*!
		Actual delete the given array.
		(Frees the memory)
		*/
		void deleteArr();

		/// the actual dynamic array
		DataType *m_head;
		/// the actual array size
		size_t m_actualSize;
		/// number of element
		size_t m_numOfElements;
		/// lock
		BaseLock *m_arrayLock;
		/// Lock Policy
		LockPolicy m_lockPolicy;

	};

	template <typename DataType>
	DynamicArray<DataType>::DynamicArray(size_t initialSize,LockPolicy lockPolicyType)
	{
		m_lockPolicy=lockPolicyType;
		switch(lockPolicyType)
		{
		case LOCK_POLICY_CRITICALSECTION:
			m_arrayLock=EP_NEW CriticalSectionEx();
			break;
		case LOCK_POLICY_MUTEX:
			m_arrayLock=EP_NEW Mutex();
			break;
		case LOCK_POLICY_NONE:
			m_arrayLock=EP_NEW NoLock();
			break;
		default:
			m_arrayLock=NULL;
			break;
		}
		m_actualSize=initialSize;
		m_numOfElements=initialSize;
		if(m_actualSize)
		{
			m_head=reinterpret_cast<DataType*>(EP_Malloc(sizeof(DataType)*m_actualSize));
			EP_ASSERT(m_head);
		}
		else
			m_head=NULL;
		
	}
	template <typename DataType>
	DynamicArray<DataType>::DynamicArray(const DynamicArray<DataType> &dArr)
	{
		m_lockPolicy=dArr.m_lockPolicy;
		switch(m_lockPolicy)
		{
		case LOCK_POLICY_CRITICALSECTION:
			m_arrayLock=EP_NEW CriticalSectionEx();
			break;
		case LOCK_POLICY_MUTEX:
			m_arrayLock=EP_NEW Mutex();
			break;
		case LOCK_POLICY_NONE:
			m_arrayLock=EP_NEW NoLock();
			break;
		default:
			m_arrayLock=NULL;
			break;
		}
		LockObj lock(dArr.m_arrayLock);
		m_actualSize=dArr.m_actualSize;
		m_numOfElements=dArr.m_numOfElements;
		if(m_actualSize)
		{
			m_head=reinterpret_cast<DataType*>(EP_Malloc(sizeof(DataType)*m_actualSize));
			EP_ASSERT(m_head);
			System::Memcpy(m_head,sizeof(DataType)*m_actualSize,dArr.m_head,sizeof(DataType)*m_actualSize);
		}
		else
			m_head=NULL;

	}

	template <typename DataType>
	DynamicArray<DataType>::~DynamicArray()
	{
		m_arrayLock->Lock();
		if(m_head)
			EP_Free(m_head);
		m_arrayLock->Unlock();
		if(m_arrayLock)
			EP_DELETE m_arrayLock;
	}

	template <typename DataType>
	void DynamicArray<DataType>::Delete()
	{
		LockObj lock(m_arrayLock);
		deleteArr();
	}

	template <typename DataType>
	void DynamicArray<DataType>::deleteArr()
	{
		if(m_head)
			EP_Free(m_head);
		m_head=NULL;
		m_actualSize=0;
		m_numOfElements=0;
	}

	template <typename DataType>
	void DynamicArray<DataType>::Clear()
	{
		LockObj lock(m_arrayLock);
		System::Memset(m_head,0,sizeof(DataType)*m_actualSize);
		m_numOfElements=0;
	}

	template <typename DataType>
	bool DynamicArray<DataType>::IsEmpty() const
	{
		LockObj lock(m_arrayLock);
		if(m_numOfElements)
			return true;
		return false;
	}

	template <typename DataType>
	size_t DynamicArray<DataType>::Size() const
	{
		LockObj lock(m_arrayLock);
		return m_numOfElements;
	}

	template <typename DataType>
	bool DynamicArray<DataType>::Resize(size_t newSize)
	{
		LockObj lock(m_arrayLock);
		return resize(newSize);
	}

	template <typename DataType>
	bool DynamicArray<DataType>::resize(size_t newSize)
	{
		if(m_actualSize>=newSize)
			return false;
		if(m_head)
		{
			m_head=reinterpret_cast<DataType*>(EP_Realloc(m_head,newSize*sizeof(DataType)));
			System::Memset(m_head+m_actualSize,0,(newSize-m_actualSize)*sizeof(DataType));
			m_actualSize=newSize;
		}
		else
		{
			m_head=reinterpret_cast<DataType*>(EP_Malloc(newSize*sizeof(DataType)));
			System::Memset(m_head,0,newSize*sizeof(DataType));
			m_actualSize=newSize;
		}
		EP_ASSERT(m_head);
		return true;
	}

	template <typename DataType>
	DataType &DynamicArray<DataType>::At(size_t idx)
	{
		LockObj lock(m_arrayLock);
		if(m_numOfElements<=idx)
		{
			resize(idx+1);
			m_numOfElements=idx+1;
		}
		return *(m_head+idx);
	}


	template <typename DataType>
	DynamicArray<DataType> &DynamicArray<DataType>::Append(const DataType &data)
	{
		LockObj lock(m_arrayLock);
		append(data);
	}

	template <typename DataType>
	DynamicArray<DataType> &DynamicArray<DataType>::Append(const DynamicArray<DataType> &dArr)
	{
		LockObj lock(m_arrayLock);
		return append(dArr);
	}

	template <typename DataType>
	DynamicArray<DataType> &DynamicArray<DataType>::append(const DataType &data)
	{
		if(m_actualSize<m_numOfElements+1)
		{
			resize(m_numOfElements+1);
		}
		*(m_head+m_numOfElements)=data;
		m_numOfElements++;
	}

	template <typename DataType>
	DynamicArray<DataType> &DynamicArray<DataType>::append(const DynamicArray<DataType> &dArr)
	{
		if(m_actualSize < m_numOfElements+dArr.m_numOfElements)
		{
			resize(m_numOfElements+dArr.m_numOfElements);
		}
		if(m_head && dArr.m_head && dArr.m_actualSize)
			System::Memcpy(m_head+m_numOfElements,dArr.m_numOfElements*sizeof(DataType),dArr.m_head,dArr.m_numOfElements*sizeof(DataType));
		m_numOfElements+=dArr.m_numOfElements;
		return *this;
	}

	template <typename DataType>
	DynamicArray<DataType> &DynamicArray<DataType>::operator=(const DynamicArray<DataType>& b)
	{
		if(this != &b)
		{
			m_arrayLock->Lock();
			if(m_head)
				EP_Free(m_head);
			m_head=NULL;
			m_arrayLock->Unlock();
			if(m_arrayLock)
				EP_DELETE m_arrayLock;
			m_arrayLock=NULL;

		
			m_lockPolicy=dArr.m_lockPolicy;
			switch(m_lockPolicy)
			{
			case LOCK_POLICY_CRITICALSECTION:
				m_arrayLock=EP_NEW CriticalSectionEx();
				break;
			case LOCK_POLICY_MUTEX:
				m_arrayLock=EP_NEW Mutex();
				break;
			case LOCK_POLICY_NONE:
				m_arrayLock=EP_NEW NoLock();
				break;
			default:
				m_arrayLock=NULL;
				break;
			}
			LockObj lock(dArr.m_arrayLock);
			m_actualSize=dArr.m_actualSize;
			m_numOfElements=dArr.m_numOfElements;
			if(m_actualSize)
				m_head=reinterpret_cast<DataType*>(EP_Malloc(sizeof(DataType)*m_actualSize));
			else
				m_head=NULL;
			EP_ASSERT(m_head);
			System::Memcpy(m_head,sizeof(DataType)*m_actualSize,dArr.m_head,sizeof(DataType)*m_actualSize);


		}
		return *this;
	}

	template <typename DataType>
	DataType& DynamicArray<DataType>::operator[](size_t idx)
	{
		return At(idx);
	}

	template <typename DataType>
	const DataType& DynamicArray<DataType>::operator[](size_t idx) const	
	{
		LockObj lock(m_arrayLock);
		EP_ASSERT(m_numOfElements>idx);
		return *(m_head+idx);
	}
	template <typename DataType>
	DynamicArray<DataType>& DynamicArray<DataType>::operator+=(const DynamicArray<DataType>& b)
	{
		LockObj lock(m_arrayLock);
		return append(b);
	}

	template <typename DataType>
	DynamicArray<DataType> DynamicArray<DataType>::operator+(const DynamicArray<DataType>& b) const
	{
		DynamicArray<DataType> retArr;
		retArr.Append(*this);
		retArr.Append(b);
		return retArr;
	}

	template <typename DataType>
	DynamicArray<DataType>& DynamicArray<DataType>::operator+=(const DataType& b)
	{
		LockObj lock(m_arrayLock);
		return append(b);
	}

	template <typename DataType>
	DynamicArray<DataType> DynamicArray<DataType>::operator+(const DataType& b) const
	{
		DynamicArray<DataType> retArr;
		retArr.Append(*this);
		retArr.Append(b);
		return retArr;				
	}
}
#endif //__EP_DYNAMIC_ARRAY_H__

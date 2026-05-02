#pragma once
#include <iostream>

template<class T>
class MyVector
{
private:
	T* ptr = nullptr;
	size_t sz = 0;
	class It 
	{
	private:
		T* current;
	public:
		It(T* ptr = nullptr) : current(ptr){}
		operator T*& ()
		{
			return current;
		}
	};
public:
	MyVector(size_t size = 0)
	{	
		if(size > 0)
			ptr = new T[size]{T()};
		sz = size;
	}
	MyVector(const MyVector& other)
	{
		delete[] ptr;
		ptr = new int[other.sz];
		sz = other.sz;
		for (int i = 0; i < sz; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		
	}
	MyVector& operator=(const MyVector& other)
	{
		delete[] ptr;
		ptr = new int[other.sz];
		sz = other.sz;
		for (int i = 0; i < sz; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		return *this;
	}
	virtual ~MyVector()
	{
		delete[] ptr;
		sz = 0;
	}
	
	void push_back(T value)
	{
		T* newArray = new T[sz + 1];
		for (int i = 0; i < sz; ++i)
		{
			newArray[i] = ptr[i];
		}
		newArray[sz] = value;
		delete [] ptr;
		ptr = newArray;
		sz++;
	}
	void push_front(T value)
	{
		T* newArray = new T[sz + 1];
		newArray[0] = value;
		for (int i = 0; i < sz; ++i)
		{
			newArray[i + 1] = ptr[i];
		}
		delete[] ptr;
		ptr = newArray;
		sz++;
	}
	void clear()
	{
		delete[] ptr;
		sz = 0;
	}
	void erase(size_t index)
	{
		T* newArray = new T[sz - 1];
		for (int i = 0; i < sz; ++i)
		{
			if (index != i)
			{
				int temp = 0;
				if (i > index)
					temp = -1;
				newArray[i + temp] = ptr[i];
			}
		}
		delete[] ptr;
		ptr = newArray;
		sz--;
	}
	void resize(size_t size)
	{
		if (size == sz)
			return;
		T* newArray = new T[size]{ T() };
		for (int i = 0; i < ((sz<size) ? sz : size); ++i)
		{
			newArray[i] = ptr[i];
		}		
		delete[] ptr;
		ptr = newArray;
		sz = size;
	}
	void insert(int index, T value)
	{
		T* newArray = new T[sz+1]{ T() };
		for (int i = 0; i < (sz+1); ++i)
		{
			if (index == i)
				newArray[i] = value;
			else {
				int temp = 0;
				if (i > index)
					temp = -1;
				newArray[i] = ptr[i+temp];
			}
		}
		delete[] ptr;
		ptr = newArray;
		sz++;
	}
	operator T* ()
	{
		return ptr;
	}
	It begin()
	{
		return It(ptr);
	}
	It end()
	{
		return It(ptr + sz);
	}
	size_t size() const
	{
		return sz;
	}
};
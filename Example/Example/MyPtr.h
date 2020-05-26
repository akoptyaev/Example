#pragma once

template <typename MyType>

class MyPtr
{
private:
	MyType * _ptr = nullptr;
	int* _countPtr = nullptr;

public:
	MyPtr();
	MyPtr(const MyType* ptr);
	//MyPtr(const MyPtr& ptr);
	~MyPtr();

	inline MyType* get() { return _ptr; }
	inline int& count() { return *_countPtr; }

	MyPtr& operator=(const MyPtr& myPtr);

	void make(MyType* ptr);
};

template <typename MyType>
MyPtr<MyType>::MyPtr() :
	_countPtr(new int(0))
{
}

template <typename MyType>
MyPtr<MyType>::MyPtr(const MyType* ptr) :
	_ptr(ptr),
	_countPtr(new int(1))
{
}

/*template <typename MyType>
MyPtr<MyType>::MyPtr(const MyPtr& ptr) :
	_ptr(ptr._ptr),
	_countPtr(new int(*ptr._countPtr))
{
	int& count = *_countPtr;
	++count;
}*/

template <typename MyType>
MyPtr<MyType>::~MyPtr()
{
	int& count = *_countPtr;
	--count;

	if (count == 0)
	{
		delete _ptr;
		delete _countPtr;
	}
}

template <typename MyType>
MyPtr<MyType>& MyPtr<MyType>::operator=(const MyPtr<MyType>& myPtr)
{
	if (!myPtr._ptr) {
		_ptr = new MyType();
	}

	*_ptr = *myPtr._ptr;

	if (!_countPtr) {
		_countPtr = new int();
	}

	*_countPtr = *myPtr._countPtr;

	int& count = *_countPtr;
	++count;

	return *this;
}

template <typename MyType>
void MyPtr<MyType>::make(MyType* ptr)
{
	_ptr = ptr;
	(*_countPtr) = 1;
}

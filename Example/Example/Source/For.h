#pragma once

#include "TestClass.h"
#include "MyPtr.h"

#include <iostream>
#include <memory>

using namespace std;

void funForInt(const int& count)
{
	int* arrayInt = new int[count];
	for (int i = 0; i < count; ++i) arrayInt[i] = 0;

	TestClass::startTime();

	for (int i = 0; i < count; ++i)
	{
		arrayInt[i] = i;
		//int& ip = arrayInt[i];
		//ip = i;
	}

	string time = TestClass::passedTimeStr();
	cout << " int: " << time.c_str() << endl;
}

void funForIntPtr(const int& count)
{
	typedef std::shared_ptr<int> IntPtr;

	IntPtr* arrayIntPtr = new IntPtr[count];
	for (int i = 0; i < count; ++i)
	{
		arrayIntPtr[i] = std::make_shared<int>(0);
	}

	TestClass::startTime();

	for (int i = 0; i < count; ++i)
	{
		*arrayIntPtr[i] = i;
	}

	string time = TestClass::passedTimeStr();
	cout << " intPtr: " << time.c_str() << endl;
}

void funForIntMyPtr(const int& count)
{
	typedef MyPtr<int> IntPtr;

	IntPtr* arrayIntPtr = new IntPtr[count];
	for (int i = 0; i < count; ++i)
	{
		arrayIntPtr[i].make(new int(0));
	}

	TestClass::startTime();

	for (int i = 0; i < count; ++i)
	{
		*(arrayIntPtr[i].get()) = i;
	}

	string time = TestClass::passedTimeStr();
	cout << " intPtr: " << time.c_str() << endl;
}

void funForIntPtrCopy(const int& count)
{
	typedef std::shared_ptr<int> IntPtr;

	IntPtr* arrayIntPtr = new IntPtr[count];
	IntPtr* arrayIntPtr2 = new IntPtr[count];
	for (int i = 0; i < count; ++i)
	{
		arrayIntPtr[i] = std::make_shared<int>(0);
	}

	TestClass::startTime();

	for (int i = 0; i < count; ++i)
	{
		IntPtr iPtr = arrayIntPtr2[i];
		arrayIntPtr2[i] = iPtr;
		*arrayIntPtr[i] = i;
	}

	string time = TestClass::passedTimeStr();
	cout << " intPtr: " << time.c_str() << endl;
}

void funFor()
{
	TestClass::line("funFor()");

	TestClass::lineShort("1000");
	funForInt(1000);
	funForIntPtr(1000);
	funForIntMyPtr(1000);

	TestClass::lineShort("1000000");
	funForInt(1000000);
	funForIntPtr(1000000);
	funForIntMyPtr(1000000);

	TestClass::lineShort("10000000");
	funForInt(10000000);
	funForIntPtr(10000000);
	funForIntMyPtr(10000000);
	//funForIntPtrCopy(10000000);
}

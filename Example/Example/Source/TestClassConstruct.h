#pragma once

#include "TestClass.h"

using namespace std;

class TestClassConstruct final : public TestClass
{
public:
	bool TestVar;

public:
	TestClassConstruct() :
		TestVar(0)
	{
		cout << "\t\t\tTestClassConstruct" << " _text = " << _text << endl;
	}

	TestClassConstruct(const string& text) :
		TestVar(0)
	{
		setText(text);
		cout << "\t\t\tTestClassConstruct" << " _text = " << _text << endl;
	}

	TestClassConstruct(const TestClassConstruct& item)
		: TestVar(item._number)
	{
		cout << "\t\t\tTestClassConstruct COPY" << " _text = " << _text << endl;
	}

	~TestClassConstruct() {
		cout << "\t\t\t~TestClassConstruct" << " _text = " << _text << endl;
	}

	/*TestClassConstruct operator=(const TestClassConstruct& item)
		: TestClass::_number(item._number)
		, TestClass::_time(item._time)
		TestClass::_text(item._text) {
	}*/
};
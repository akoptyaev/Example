#include "TestClass.h"

#include <functional>
#include <algorithm>
#include <vector>
#include <ctime>

long TestClass::_timeStart = clock();
int TestClass::_countGlobal = 0;

TestClass::TestClass()
{
	++_countGlobal;
	_number = _countGlobal;

	_text = "DEFAULT_TEXT";
	startTime();
};

TestClass::TestClass(const string& text)
{
	++_countGlobal;
	_number = _countGlobal;

	_text = text;
	startTime();
};

void TestClass::action() const
{
	cout << "TestClass::_text: " << _text << endl;
}

const TestClass& TestClass::operator=(const string& text)
{
	_text = text;
	return *this;
}

bool TestClass::operator==(const string& text)
{
	if (_text == text) return true;
	return false;
}

bool TestClass::operator!=(const string& text)
{
	if (_text != text) return true;
	return false;
}

bool TestClass::operator==(const TestClass& item)
{
	if (_text == item._text) return true;
	return false;
}

bool TestClass::operator!=(const TestClass& item)
{
	if (_text != item._text) return true;
	return false;
}

bool TestClass::operator<(const TestClass& item) const
{
	size_t l = _text.length();
	size_t il = item._text.length();

	if (l == il)
	{
		for (int i = 0; i < l; ++i)
		{
			if (_text[i] < item._text[i])
			{
				return true;
			}
		}
	}

	if (l < il)
	{
		return true;
	}

	return false;
}

bool TestClass::operator>(const TestClass& item) const
{
	bool res = *this < item;
	return !res;
}

const TestClass& TestClass::operator+(const TestClass& item)
{
	_text += item._text;
	return *this;
}

const TestClass& TestClass::operator+(const string& text)
{
	_text += text;
	return *this;
}

void TestClass::message(const string& text)
{
	cout << text << endl;
}

void TestClass::line(const string& text)
{
	if (text.empty())
	{
		cout << "\n--------------------------------- [" << passedTimeStr() << "] " << endl;
	}
	else
	{
		cout << "\n--------------------------------- (" << text << ") [" << passedTimeStr() << "] " << endl;
	}

	startTime();
}

void TestClass::lineShort(const string& text)
{
	if (text.empty())
	{
		cout << "\n------" << endl;
	}
	else
	{
		cout << "\n------ (" << text << ")" << endl;
	}
}

// Virtual

void TestClass::virtualMethod(float var)
{
	const string& text = to_string(var);
	cout << "virtual TestClass::virtualMethod(float " << text << ")" << endl;
}

void TestClass::virtualMethad(float var)
{
	const string& text = to_string(var);
	cout << "virtual TestClass::virtualMethad(float " << text << ")" << endl;
}


// static

void TestClass::startTime()
{
	_timeStart = clock();
}

long TestClass::passedTime()
{
	long timeEnd = clock();
	return timeEnd - _timeStart;
}

string TestClass::passedTimeStr()
{
	const long timePassed = passedTime();
	const long timePassedSec = timePassed / CLOCKS_PER_SEC;
	string timeText = "msec: " + to_string(timePassed) + " sec: " + to_string(timePassedSec);

	return timeText;
}

void funCopyClass()
{
	TestClass::line("funCopyClass");

	{
		TestCopyClass test(5);
		
		{
			TestCopyClass test2(8);
			test2.set();

			// Утечка, т.к. указатель _intArray в test переписался на _intArray из test2 и краш при вызове деструктора test
			//test = test2;
		}

		TestClass::lineShort();

		// Краш, т.к. _intArray удален в test2
		//test.showArray();
	}
}
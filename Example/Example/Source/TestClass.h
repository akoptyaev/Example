#pragma once

#include <string>
#include <iostream>

using namespace std;

class TestClass
{
public:
	int _number;
	int _time;
	string _text;

public:
	static int _countGlobal;
	static long _timeStart;

	TestClass();
	virtual ~TestClass() {};

	TestClass(const string& text);

	void action() const;
	const TestClass operator=(const string& text);
	bool operator==(const string& text);
	bool operator!=(const string& text);

	bool operator==(const TestClass& item);
	bool operator!=(const TestClass& item);

	// Обязательно для контейнера std::set
	bool operator<(const TestClass& item) const;

	bool operator>(const TestClass& item) const;

	const TestClass& operator+(const TestClass& item);
	const TestClass& operator+(const string& text);

	static void message(const string& text);
	static void line(const string& text = string());
	static void lineShort(const string& text = string());

protected:
	void setText(const string& text);

public:
	virtual void virtualMethod(float var);
	virtual void virtualMethad(float var);

public:
	static void startTime();
	static long passedTime();
	static string passedTimeStr();
	static const int var = 6;
};

class TestCopyClass
{
public:
	int _count = 10;
	int* _intArray = nullptr;

	TestCopyClass(int var)
	{
		cout << "\nCONSTRUCTOR";

		_intArray = new int[10];

		for (int i = 0; i < 10; ++i)
		{
			_intArray[i] = var;
		}

		showArray();
	}

	~TestCopyClass()
	{
		cout << "\nDESTRUCTOR()";

		showArray();

		if (_intArray)
		{
			delete[] _intArray;
			_intArray = nullptr;
			_count = 0;
		}
	}

	void set()
	{
		cout << "\nset()";

		if (_intArray)
		{
			for (int i = 0; i < 10; ++i)
			{
				_intArray[i] = 9 + i * i;
			}
		}

		showArray();
	}

	void showArray()
	{
		if (_intArray)
		{
			cout << " //" << endl;

			for (int i = 0; i < 10; ++i)
			{
				cout << _intArray[i] << " " << endl;
			}
		}
		else
		{
			cout << "\n_intArray == nullptr";
		}
	}
};

void funCopyClass();
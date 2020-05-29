#pragma once

#include "TestClass.h"

#include <set>
#include <algorithm>

using namespace std;

void funSet()
{
	TestClass::line("funSet()");

	{
		TestClass::lineShort("int");

		set<int> testSetInt;

		testSetInt.insert(int(2));
		testSetInt.insert(int(4));
		testSetInt.insert(int(5));
		testSetInt.insert(int(2));
		testSetInt.insert(int(6));
		testSetInt.insert(int(2));

		for (set<int>::iterator it = testSetInt.begin(); it != testSetInt.end(); ++it)
		{
			cout << *it << endl;
		}
	}

	{

		TestClass t1;
		TestClass t2("sdfdsfsf");

		if (t1 < t2)
		{

		}

		TestClass::lineShort("TestClass");
		
		set<TestClass> testSet;

		testSet.insert(TestClass("test_24"));
		testSet.insert(TestClass("test_2"));
		testSet.insert(TestClass("test_01"));
		testSet.insert(TestClass("test_00"));
		testSet.insert(TestClass("test_01"));
		testSet.insert(TestClass("test_24"));
		testSet.insert(TestClass("test_1323"));
		testSet.insert(TestClass("tesa_321"));

		for (set<TestClass>::iterator it = testSet.begin(); it != testSet.end(); ++it)
		{
			it->action();

			//const TestClass& item = *it;
			//item.action();
		}

		{
			TestClass::lineShort();

			{
				set<TestClass>::iterator it = testSet.find(TestClass("test_01"));
				it->action();

				const TestClass& item = *it;
				item.action();

				const TestClass* ptr = &*it;
				ptr->action();
			}

			{
				set<TestClass>::iterator it = testSet.find(TestClass("test_01")); // tAest_01 ERROR

				if (it != testSet.end())
				{
					it->action();
				}
				else
				{
					TestClass::message("nullptr");
				}
			}
		}

		{
			TestClass::lineShort();

			{
				set<TestClass>::iterator it = testSet.begin();
				it->action();
			}

			{
				set<TestClass>::iterator it = testSet.end();
				--it;
				it->action();
			}
		}
	}
}

void funMultiSet()
{
	TestClass::line("funMultiSet()");

	{
		TestClass::lineShort("int");

		multiset<int> testSetInt;

		testSetInt.insert(int(2));
		testSetInt.insert(int(4));
		testSetInt.insert(int(5));
		testSetInt.insert(int(2));
		testSetInt.insert(int(6));
		testSetInt.insert(int(2));

		for (multiset<int>::iterator it = testSetInt.begin(); it != testSetInt.end(); ++it)
		{
			cout << *it << endl;
		}
	}

	{

		TestClass t1;
		TestClass t2("sdfdsfsf");

		if (t1 < t2)
		{

		}

		TestClass::lineShort("TestClass");

		multiset<TestClass> testSet;

		testSet.insert(TestClass("test_24"));
		testSet.insert(TestClass("test_2"));
		testSet.insert(TestClass("test_01"));
		testSet.insert(TestClass("test_00"));
		testSet.insert(TestClass("test_01"));
		testSet.insert(TestClass("test_24"));
		testSet.insert(TestClass("test_1323"));
		testSet.insert(TestClass("tesa_321"));

		for (multiset<TestClass>::iterator it = testSet.begin(); it != testSet.end(); ++it)
		{
			it->action();

			//const TestClass& item = *it;
			//item.action();
		}

		{
			TestClass::lineShort();

			{
				multiset<TestClass>::iterator it = testSet.find(TestClass("test_01"));
				it->action();

				const TestClass& item = *it;
				item.action();

				const TestClass* ptr = &*it;
				ptr->action();
			}

			{
				multiset<TestClass>::iterator it = testSet.find(TestClass("test_01")); // ERROR tAest_01

				if (it != testSet.end())
				{
					it->action();
				}
				else
				{
					TestClass::message("nullptr");
				}
			}
		}

		{
			TestClass::lineShort();

			{
				multiset<TestClass>::iterator it = testSet.begin();
				it->action();
			}

			{
				multiset<TestClass>::iterator it = testSet.end();
				--it;
				it->action();
			}
		}
	}
}

void functionsSet()
{
	funSet();
	funMultiSet();
}

//	set	http://proginfo.ru/set/
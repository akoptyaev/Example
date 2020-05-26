#pragma once

#include "TestClass.h"
#include "Help.h"

#include <vector>
#include <functional>
#include <algorithm>

// Нельзя testArray.pop_front();

using namespace std;

void funVector2()
{
	TestClass::line("funVector2");
}

void funVector()
{
	TestClass::line("funVector");

	{
		TestClass::line("auto it");

		vector<TestClass> testArray;
		testArray.resize(5);
		string text;

		for (auto it : testArray)
		{
			text += "Q";
			it = text;
		}

		TestClass tempItem("push_back");
		testArray.push_back(tempItem);

		for (auto it : testArray)
		{
			it.action();
		}
	}

	{
		TestClass::line("vector<TestClass>::iterator i");

		vector<TestClass> testArray;
		testArray.resize(5);
		string text;

		for (vector<TestClass>::iterator it = testArray.begin(); it != testArray.end(); ++it)
		{
			it->action();
			text += "W";
			*it = text;
		}

		for (auto item : testArray)
		{
			item.action();
		}
	}

	{
		TestClass::line("auto& it");

		vector<TestClass> testArray;
		testArray.resize(5);
		string text;

		for (auto& item : testArray)
		{
			text += "E";
			item = text;
		}

		for (auto& item : testArray)
		{
			item.action();
		}
	}

	{
		TestClass::line("\tpush_back()");

		vector<TestClass> testArray;
		testArray.resize(2);

		TestClass item("new_item_0");
		testArray.push_back(item);

		testArray.push_back(TestClass("new_item_1"));
		testArray.push_back(TestClass("new_item_2"));

		testArray.resize(7);

		testArray.push_back(TestClass("new_item_3"));

		for (size_t i = 0; i < testArray.size(); ++i)
		{
			testArray[i].action();
		}

		TestClass::lineShort("pop_back()");
		testArray.pop_back();

		for (size_t i = 0; i < testArray.size(); ++i)
		{
			testArray[i].action();
		}

		TestClass::lineShort("insert");
		vector<TestClass>::const_iterator it3 = testArray.begin() + 3;
		testArray.insert(it3, TestClass("insert"));

		for (size_t i = 0; i < testArray.size(); ++i)
		{
			testArray[i].action();
		}

		TestClass::line("erase");

		{
			auto itDel = testArray.begin() + 1;
			testArray.erase(itDel);
		}

		{
			auto itDel = testArray.end() - 1;
			testArray.erase(itDel);
		}

		{
			for (vector<TestClass>::iterator it = testArray.begin(); it <testArray.end(); ++it)
			{
				if ((*it) == "insert")
				{
					testArray.erase(it);
					break;
				}

			}
		}

		for (size_t i = 0; i < testArray.size(); ++i)
		{
			testArray[i].action();
		}
	}
}

void funArray()
{
	TestClass::line("funArray");

	TestClass testArray[] = { TestClass("First"), TestClass("Second"), TestClass("Third") };
	for (TestClass item : testArray)
	{
		item.action();
	}

	for (auto& item : testArray)
	{
		item.action();
	}
}

void funArrayBeginEnd()
{
	TestClass::line("funArrayBeginEnd");

	int arr[] = { 1,2,3 };
	std::for_each(&arr[0], &arr[0] + sizeof(arr) / sizeof(arr[0]), [](int n) {std::cout << n << std::endl; });

	TestClass::lineShort("1");

	auto funL = [](TestClass& item) { item.action(); };

	TestClass testArray[5];
	for_each(&testArray[0], &testArray[0] + sizeof(testArray) / sizeof(testArray[0]), funL);

	TestClass::lineShort("2");
	for_each(begin(testArray), end(testArray), funL);

	TestClass::lineShort("3");
	TestClass* beginItem = &testArray[0];
	int count = sizeof(testArray) / sizeof(testArray[0]) + 1;
	TestClass* endItem = &testArray[count - 1];
	for_each(beginItem, endItem, funL);
}

void funVectorCoutInt(const int var)
{
	cout << var << ' ';
}

void funVectorSortInt()
{
	TestClass::line("funVectorSortInt");

	vector<int> testArray;

	testArray.push_back(5);
	testArray.push_back(8);
	testArray.push_back(9);
	testArray.push_back(2);
	testArray.push_back(5);

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	sort(begin(testArray), end(testArray));

	TestClass::message("\nafter sort");
	for_each(begin(testArray), end(testArray), funVectorCoutInt);
}

void funVectorSortTestClass()
{
	TestClass::line("funVectorFindTestClass");

	vector<TestClass> testArray;

	testArray.push_back(TestClass("test_5"));
	testArray.push_back(TestClass("aaa"));
	
	testArray.push_back(TestClass("test_8"));
	testArray[testArray.size() - 1] = "test_234";
	

	testArray.push_back(TestClass("test_9"));

	testArray.push_back(TestClass("test_88"));
	testArray.push_back(TestClass("test_23"));

	for_each(begin(testArray), end(testArray), [](const TestClass& item) { item.action(); });
	sort(begin(testArray), end(testArray));

	TestClass::message("\nafter sort");
	for_each(begin(testArray), end(testArray), [](const TestClass& item) { item.action(); });

	sort(begin(testArray), end(testArray), [](const TestClass& iA, const TestClass& iB)
	{
		if (iA._number < iB._number)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	);

	TestClass::message("\nafter lambda function sort");
	for_each(begin(testArray), end(testArray), [](const TestClass& item) { item.action(); });

	TestClass::lineShort("after erase");

	for (std::vector<TestClass>::iterator it = testArray.begin(); it != testArray.end(); ++it)
	{
		if (*it == "test_88")
		{
			testArray.erase(it);
			break;
		}
	}

	//testArray.pop_front(); Нельзя
	testArray.pop_back();

	for (std::vector<TestClass>::iterator it = testArray.begin(); it != testArray.end(); ++it)
	{
		it->action();
	}
}

void funVectorFindInt()
{
	TestClass::line("funVectorFindInt");

	vector<int> testArray;

	testArray.push_back(5);
	testArray.push_back(8);
	testArray.push_back(9);
	testArray.push_back(2);
	testArray.push_back(5);
	testArray.push_back(19);
	testArray.push_back(888);
	testArray.push_back(12);
	testArray.push_back(15);

	{
		auto it = testArray.insert(testArray.begin(), 12345);
		testArray.insert(it, 123456789);

		{
			auto it = testArray.insert(--testArray.end(), 54321);
		}
	}

	//---

	for_each(begin(testArray), end(testArray), funVectorCoutInt);

	//---

	std::vector<int>::iterator it = std::find(testArray.begin(), testArray.end(), 9);
	if (it != testArray.end())
	{
		cout << "find: *it & erase" << endl;
		testArray.erase(it);
	}

	TestClass::lineShort("after erase it");

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	//---
	std::remove(testArray.begin(), testArray.end(), 19);
	std::remove(testArray.begin(), testArray.end(), 2);
	std::remove(testArray.begin(), testArray.end(), 99);

	TestClass::lineShort("after remove 19, 2, 99(if has)");
	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	TestClass::lineShort("after resize");
	size_t size = testArray.size();
	size -= 2;
	testArray.resize(size);

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	TestClass::lineShort("after reserve less");
	size -= 1;
	testArray.reserve(size);
	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	TestClass::lineShort("after reserve greate");
	size += 5;
	testArray.reserve(size);
	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	//---

	size += 10;
	testArray.resize(size);

	it = std::find(testArray.begin(), testArray.end(), 888);
	if (it != testArray.end())
	{
		std::fill_n(it, 10, 999);

		std::fill(++it, (it + 7), 777);

		TestClass::lineShort("after std::fill_n & std::fill");
		for_each(begin(testArray), end(testArray), funVectorCoutInt);
		cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

		TestClass::lineShort("after std::generate");

		int iGen = 5;
		std::generate(++it, (it + 5), [&iGen]()
		{
			int newNumber = 10 * (iGen);
			++iGen;

			return newNumber;
		});
				
		for_each(begin(testArray), end(testArray), funVectorCoutInt);
		cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;
	}
}

int xform(int i) {
	return i * 1000; // квадрат исходного значения
}

struct FuncMultiple1000
{
	int operator()(int i)
	{
		i = i * 1000;
		return i;
	}
};

struct FuncMultiple1000R
{
	int operator()(int& i)
	{
		i = i * 1000;
		return i;
	}
};

void funVectorCopyEndInt()
{
	TestClass::line("funVectorCopyInt");

	vector<int> testArray;

	testArray.push_back(5);
	testArray.push_back(8);
	testArray.push_back(9);
	testArray.push_back(2);
	testArray.push_back(5);
	testArray.push_back(19);
	testArray.push_back(888);
	testArray.push_back(12);
	testArray.push_back(15);

	vector<int> testArray2;

	testArray2.push_back(1335);
	testArray2.push_back(2338);
	testArray2.push_back(3339);
	testArray2.push_back(4332);
	testArray2.push_back(5335);

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	TestClass::lineShort("after copy");

	std::copy(++testArray2.begin(), (testArray2.end() - 2), (testArray.begin() + 2));

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

	TestClass::lineShort("after reverse_copy");

	std::reverse_copy(++testArray2.begin(), (testArray2.end() - 2), (testArray.begin() + 2));

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;


	TestClass::lineShort("after transform");

	//std::transform(++testArray.begin(), --testArray.end(), ++testArray.begin(), FuncMultiple1000());
	//std::transform(++testArray.begin(), --testArray.end(), ++testArray.begin(), FuncMultiple1000());
	std::transform(++testArray.begin(), --testArray.end(), ++testArray.begin(), FuncMultiple1000R());

	for_each(begin(testArray), end(testArray), funVectorCoutInt);
	cout << "\t\t\t//size = " << testArray.size() << " max_size = " << testArray.max_size() << " capacity = " << testArray.capacity() << endl;

}

void funVectorAt()
{
	TestClass::line("funVectorAt");

	vector<TestClass> testArray;

	testArray.push_back(TestClass("111"));
	testArray.push_back(TestClass("222"));
	testArray.push_back(TestClass("333"));
	testArray.push_back(TestClass("444"));

	{
		TestClass item = testArray[1];
		item.action();
	}

	{
		TestClass item = testArray.at(1);
		item.action();
	}

	{
		try
		{
			TestClass item = testArray.at(10);
			item.action();
		}
		catch (const std::out_of_range& e)
		{
			const char* msg = e.what();
			cout << "ERROR: " << msg;
		}
		catch (...)
		{
			TestClass::message("ERROR");
		}
	}
}

void funIterators()
{
	TestClass::line("funIterators");

	vector<int> testArray;

	testArray.push_back(1);
	testArray.push_back(2);
	testArray.push_back(3);
	testArray.push_back(4);
	testArray.push_back(5);

	TestClass::lineShort("ri");
	{
		vector<int>::iterator i = find(testArray.begin(), testArray.end(), 3);
		vector<int>::reverse_iterator ri = find(testArray.rbegin(), testArray.rend(), 3);
		vector<int>::reverse_iterator ri2 = find(testArray.rbegin(), testArray.rend(), 4);

		cout << "i = " << (*i) << " ri = " << (*ri) << endl;

		i = ri.base();
		cout << "i (ri.base()) = " << (*i) << endl;

		testArray.insert(i, 999);
		for_each(begin(testArray), end(testArray), funVectorCoutInt);

		cout << endl;

		testArray.erase(--ri2.base()); // Удалится не 4 а 999
		for_each(begin(testArray), end(testArray), funVectorCoutInt);
	}

	TestClass::lineShort("==");
	{
		vector<int>::iterator i = testArray.begin();
		vector<int>::const_iterator ci;

		ci = i;
		*i = 222;

		int varI = *ci;

		cout << "varI = " << varI << endl;

		//i = ci;	// ERROR
	}

	for_each(begin(testArray), end(testArray), funVectorCoutInt);


}

void functionVector()
{
	//funVector();
	//funVector2();

	//funVectorSortInt();
	//funVectorSortTestClass();

	//funVectorFindInt();
	funVectorCopyEndInt();
	//funVectorAt();

	//funIterators();

}

// vetor, map ... http://proginfo.ru/vector/

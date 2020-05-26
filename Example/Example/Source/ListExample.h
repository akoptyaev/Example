#ifndef __LIST_H__
#define __LIST_H__

#include "TestClass.h"
#include <list>

// Нет std::sort(...)

void funList()
{
	TestClass::line("funList()");
	std::cout << std::endl;

	std::list<int> listTest;

	listTest.push_front(93);
	listTest.push_front(92);
	listTest.push_front(91);

	{
		auto it = listTest.insert(listTest.begin(), 12345);
		listTest.insert(it, 123456789);

		{
			auto it = listTest.insert(--listTest.end(), 54321);
		}
	}

	listTest.push_back(8);
	listTest.push_back(4);
	listTest.push_back(9);

	listTest.push_front(111);
	listTest.push_front(222);

	std::cout << listTest.front() << std::endl;
	std::cout << listTest.back() << std::endl;

	for (std::list<int>::const_iterator it = listTest.begin(); it != listTest.end(); ++it)
	{
		std::cout << *it << ' ';
	}


	TestClass::lineShort("after erase");

	for (std::list<int>::iterator it = listTest.begin(); it != listTest.end(); ++it)
	{
		if (*it == 91)
		{
			listTest.erase(it);
			break;
		}
	}

	listTest.pop_front();
	listTest.pop_back();

	for (std::list<int>::iterator it = listTest.begin(); it != listTest.end(); ++it)
	{
		std::cout << *it << ' ';
	}


}

void functionList()
{
	funList();
}

#endif // __LIST_H__

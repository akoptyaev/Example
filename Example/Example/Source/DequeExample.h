#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "TestClass.h"
#include <deque>

void funDeque()
{
	TestClass::line("funDeque()");
	std::cout << std::endl;

	std::deque<int> dequeTest;

	dequeTest.push_front(93);
	dequeTest.push_front(92);
	dequeTest.push_front(91);

	auto it = dequeTest.insert(dequeTest.begin(), 12345);
	dequeTest.insert(it, 123456789);

	{
		auto it = dequeTest.insert(--dequeTest.end(), 54321);
	}

	dequeTest.push_back(8);
	dequeTest.push_back(4);
	dequeTest.push_back(9);

	dequeTest.push_front(111);
	dequeTest.push_front(222);

	for (std::deque<int>::const_iterator it = dequeTest.begin(); it != dequeTest.end(); ++it)
	{
		std::cout << *it << ' ';
	}

	TestClass::lineShort("after sort");

	std::sort(dequeTest.begin(), dequeTest.end());

	for (std::deque<int>::iterator it = dequeTest.begin(); it != dequeTest.end(); ++it)
	{
		std::cout << *it << ' ';
	}

	TestClass::lineShort("after erase");

	for (std::deque<int>::iterator it = dequeTest.begin(); it != dequeTest.end(); ++it)
	{
		if (*it == 91)
		{
			dequeTest.erase(it);
			break;
		}
	}

	dequeTest.pop_front();
	dequeTest.pop_back();

	for (std::deque<int>::iterator it = dequeTest.begin(); it != dequeTest.end(); ++it)
	{
		std::cout << *it << ' ';
	}
}

void functionDeque()
{
	funDeque();
}

#endif // __DEQUE_H__

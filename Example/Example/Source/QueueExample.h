#ifndef __QUEUE_H__
#define __LIST_H__

#include "TestClass.h"
#include <queue>

// Нет std::sort(...)

void funQueue()
{
	TestClass::line("funQueue()");
	std::cout << std::endl;

	std::queue<int> queueTest;

	queueTest.push(93);
	queueTest.push(92);
	queueTest.push(91);

	queueTest.push(8);
	queueTest.push(4);
	queueTest.push(9);


	std::cout << queueTest.front() << ' ';
	
	queueTest.pop();

	std::cout << queueTest.front() << ' ';
}

void functionQueue()
{
	funQueue();
}

#endif // __LIST_H__

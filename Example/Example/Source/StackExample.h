#ifndef __STACK_H__
#define __STACK_H__

#include "TestClass.h"
#include <stack>

// Нет std::sort(...)

void funStack()
{
	TestClass::line("funStack()");
	std::cout << std::endl;

	std::stack<int> stackTest;

	stackTest.push(93);
	stackTest.push(92);
	stackTest.push(91);

	stackTest.push(8);
	stackTest.push(4);
	stackTest.push(9);



	std::cout << stackTest.top() << ' ';

	stackTest.pop();

	std::cout << stackTest.top() << ' ';
}

void functionStack()
{
	funStack();
}

#endif // __STACK_H__

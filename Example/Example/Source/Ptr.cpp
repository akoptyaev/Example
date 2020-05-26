#include "Ptr.h"
#include "TestClass.h"

#include <memory>

void funSharedPtr()
{
	TestClass::line("funSharedPtr");

	shared_ptr<TestClass> objectPtr0(new TestClass());
	shared_ptr<TestClass> objectPtr1 = shared_ptr<TestClass>(new TestClass("objectPtr1"));

	objectPtr0->action();

	TestClass* object1 = objectPtr1.get();
	if (object1)
	{
		object1->action();
	}

	objectPtr1.reset();
	object1 = objectPtr1.get();
	if (object1)
	{
		object1->action();
	}
	else
	{
		TestClass::message("object1 == nullptr");
	}

	objectPtr1 = objectPtr0;
	objectPtr1->action();
}

void funWeakPtr()
{
	TestClass::line("funWeakPtr");

	std::shared_ptr<TestClass> ptr = std::make_shared<TestClass>("std::shared_ptr<TestClass> foo = w.lock()");
	std::weak_ptr<TestClass> w(ptr);

	/* Нет такого в weak_ptr
	w->action();
	w.get()->action();
	*/

	std::shared_ptr<TestClass> foo = w.lock();
	if (foo)
	{
		foo->action();
	}
}

void funRemovePtr()
{
	TestClass::line("funRemovePtr");

	TestClass* test = new TestClass();
	std::shared_ptr<TestClass> testPtr(test);

	testPtr->action();

	// Краш
	/*delete test;

	if (testPtr)
	{

		testPtr->action();
	}*/
}

void funEmptyPtr()
{
	TestClass::line("funEmptyPtr");

	std::shared_ptr<TestClass> emptyTestPtr;

	if (emptyTestPtr)
	{
		TestClass::message("HAS [0]");
	}
	else
	{
		TestClass::message("NO has [0]");
	}

	emptyTestPtr = std::make_shared<TestClass>();

	if (emptyTestPtr)
	{
		TestClass::message("HAS [1]");
	}
	else
	{
		TestClass::message("NO has [1]");
	}
}
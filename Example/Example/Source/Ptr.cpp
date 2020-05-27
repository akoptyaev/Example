#include "Ptr.h"
#include "TestClass.h"
#include "TestClassConstruct.h"

#include <memory>

void funSharedPtr()
{
	TestClass::lineShort("funSharedPtr");

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
	cout << "objectPtr1 = objectPtr0" << endl;
	objectPtr1 = objectPtr0;
	objectPtr1->action();
}

void funWeakPtr()
{
	TestClass::lineShort("funWeakPtr");

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
	TestClass::lineShort("funRemovePtr");

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
	TestClass::lineShort("funEmptyPtr");

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

//-------------------------------------

void funUniquePtr() {
	typedef TestClassConstruct TEST_CLASS; // TestClassConstruct // TestClass

	TestClass::lineShort("funUniquePtr");

	TEST_CLASS* pObj1 = new TEST_CLASS("UniquePtr");
	unique_ptr<TEST_CLASS> ptr1 = unique_ptr<TEST_CLASS>(pObj1);

	if (ptr1) {
		ptr1->action();
	}

	// unique_ptr<TestClass> ptr2 = ptr1; ERROR

	TEST_CLASS* pObj2 = new TEST_CLASS("UniquePtr_2");
	unique_ptr<TEST_CLASS> ptr2;
	ptr2 = unique_ptr<TEST_CLASS>(pObj2);

	if (ptr2) {
		ptr2->action();
	}

	cout << "ptr1 = std::move(ptr2);" << endl;
	ptr1 = std::move(ptr2);

	// Указатель из ptr2 переходит к ptr1, а указатель ptr1 удаляется (перед этим)

	if (ptr1) {
		ptr1->action();
	}
	else {
		cout << "ptr1 == nullptr" << endl;
	}

	if (ptr2) {
		ptr2->action();
	}
	else {
		cout << "ptr2 == nullptr" << endl;
	}
}

//-------------------------------------
//-------------------------------------
//-------------------------------------
//-------------------------------------

void funPtr() {
	TestClass::line("funSharedPtr");

	//funSharedPtr();
	//funWeakPtr();
	//funRemovePtr();
	//funEmptyPtr();

	//funUniquePtr();
}
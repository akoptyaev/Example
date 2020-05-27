
#include "Source/TestClass.h"
#include "Source/Ptr.h"
#include "Source/Common.h"
#include "Source/Template.h"
#include "Source/VectorExample.h"
#include "Source/SetExample.h"
#include "Source/MapExample.h"
#include "Source/DequeExample.h"
#include "Source/ListExample.h"
#include "Source/QueueExample.h"
#include "Source/StackExample.h"
#include "Source/SortExample.h"
#include "Source/For.h"
#include "Source/DataClass.h"

#include "Source/Cpp11.h"
#include "Source/Cpp14.h"
#include "Source/Cpp17.h"

#include <string>
#include <iostream>
#include <memory>
#include <ctime>

using namespace std;

void funTemp();

template <typename TA, typename TB>
class A {
public:
	TA _v;
	TB _v2;
	virtual void fun()
	{
		int i = 0;
	}

	virtual void fun1()
	{
		int i = 0;
	}

	virtual void fun2()
	{
		int i = 0;
	}

	virtual void fun3()
	{
		int i = 0;
	}

	virtual void fun4()
	{
		int i = 0;
	}

	virtual void fun5()
	{
		int i = 0;
	}
};

template <typename TA, typename TB>
class B {
public:
	TA _v;
	TB _v2;
};

int main(int count, char** param)
{
	A<int, char> a;
	B<int, char> b;

	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(b) = " << sizeof(b) << endl;


	string progaramName = count > 0 ? *param : "";
	cout << progaramName << "\nRUN.\n Enter text." << endl;
	TestClass::line();

	string message;

	if (!message.empty())
	{
		cout << "Message: " << message << endl;
	}

	/*testDataClass();
	testDataClassT();
	functionVector();
	// KOP_CRASH functionsSet();
	functionsMap();
	functionDeque();
	functionList();
	functionQueue();
	functionStack();

	funVirtualOveride();
	funenumClass();
	funLambda();
	funLambdaForEach();
	funArrayBeginEnd();

	funStatic_Assert();
	funSizeof();
	sort();
	// KOP_EXCEPTION funThrow();

	funCopyClass();

	functionsTemplate();

	functionSort();

	funTemp();

	funFor();*/

	//funPtr();

	functionsCpp11();
	//functionsCpp14();
	//functionsCpp17();

	// auto
	/*{
		int varInt = 0;
		int *varIntPtr = new int(1);
		int* varIntPtr2 = &varInt;

		auto varAuto1 = varInt;
		auto varAuto2 = varIntPtr;

		auto varAuto3 = varIntPtr;
		//auto* varAuto4 = varInt;
		auto& varAuto4 = varInt;
		auto& varAuto5 = varIntPtr;

		std::cout << varAuto1 << "   " << *varAuto2 << "   " << varAuto4 << "   " << *varAuto5;
	}*/


	// Лямбда
	/*std::cout << std::endl;
	{
		int var = 6;
		std::function<void(bool)> f = [&var, var2 = 11](bool) {
			var = var + var2;
		};
		f(false);
		std::cout << var << std::endl;
	}
	{
		int var = 7;
		std::function<void(bool)> f = [&var](bool) {
			var = var + 1;
		};
		f(false);
		std::cout << var << std::endl;
	}
	{
		int *var = new int(8);
		std::function<void(bool)> f = [var](bool) {
			*var = *var + 1;
		};
		f(false);
		std::cout << *var << std::endl;
	}
	{
		int *var = new int(10);
		int var2 = 0;
		std::function<void(bool)> f = [var, &var2](bool) {
			var2 = *var;
		};
		f(false);
		std::cout << *var << " " << var2 << std::endl;
	}*/

	TestClass::line();
	cout << "END.\n Enter char." << endl;
	cin >> message;
	return 0;
}


// Десять возможностей C++11 https://habrahabr.ru/post/182920/

class PrivateClass
{
public:
	int privateVar;

	PrivateClass()
	{
		cout << "PrivateClass()" << endl;
	}

	~PrivateClass()
	{
		cout << "DESTRUCTOR PrivateClass()" << endl;
	}

	void privateFun()
	{
		cout << "privateVar = " << privateVar << endl;
	}
};

class BaseClassTest: public PrivateClass
{
public:
	int varBase = 0;

	BaseClassTest()
	{
		cout << "BaseClassTest" << endl;
	}

	virtual ~BaseClassTest()
	{
		cout << "DESTRUCTOR ~BaseClassTest" << endl;
	}

	void fun(int var)
	{

	}
};

class BaseClassTestSecond: public PrivateClass
{
public:
	int varBase = 0;

	BaseClassTestSecond()
	{
		cout << "BaseClassTestSecond" << endl;
	}

	virtual ~BaseClassTestSecond()
	{
		cout << "DESTRUCTOR ~BaseClassTestSecond" << endl;
	}

	void fun(int var)
	{

	}
};

class TempClass: public BaseClassTest, public BaseClassTestSecond
{
public:
	static const int var = 10;
	static int var2;

	TempClass()
	{
		cout << "TempClass" << endl;
	}

	~TempClass()
	{
		cout << "DESTRUCTOR ~TempClass" << endl;
	}

	const int& operator[](int argVar) const
	{
		return argVar;
	}

	int& operator[](int argVar)
	{
		argVar *= var;
		return argVar;
	}


	int& fun(int argVar) const
	{
		return argVar;
	}

	int& fun(int argVar)
	{
		argVar *= var;
		return argVar;
	}

	void funAction()
	{
		BaseClassTest::privateVar = 11;
		cout << "privateVar = " << BaseClassTest::privateVar << endl;

		cout << "BaseClassTest::privateVar = " << BaseClassTest::privateVar << endl;
		cout << "BaseClassTestSecond::privateVar = " << BaseClassTestSecond::privateVar << endl;
	}
};

int funTempStaticVar(int var)
{
	static int staticVar = 0;
	staticVar += var;
	return staticVar;
}

void funTemp()
{
	TestClass::line("funTemp()");

	{
		TempClass* item = new TempClass;
		//delete item;
		
		item->funAction();

		BaseClassTest* itemBase = item;
		delete itemBase;
	}

	//return;

	for (int i = 0; i < 10; ++i)
	{
		cout << funTempStaticVar(i) << endl;
	}

	TestClass::lineShort("operator[]");
	{
		TempClass item;
		cout << "NO const item =>" << item[123] << endl;

		TempClass& itemR = item;
		cout << "NO const itemR =>" << itemR[123] << endl;

		const TempClass& itemRC = item;
		cout << "const itemRC =>" << itemRC[123] << endl;
	}

	TestClass::lineShort("fun(...)");
	{
		TempClass item;
		cout << "NO const item =>" << item.fun(123) << endl;

		TempClass item2;
		item2 = item;

		TempClass& itemR = item;
		cout << "NO const itemR =>" << itemR.fun(123) << endl;

		const TempClass& itemRC = item;
		cout << "const itemRC =>" << itemRC.fun(123) << endl;
	}
}


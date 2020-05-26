#include "Common.h"
#include "TestClass.h"

#include "DataClass.h"
#include "DataClassT.h"

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void funVirtualOveride()
{
	TestClass::line("funVirtualOveride");

	class TestClass2 : public TestClass
	{
	public:
		void virtualMethod(int var)
		{
			const string& text = to_string(var);
			cout << "virtual TestClass2::virtualMethod(int " << text << ")" << endl;
		}
	};

	class TestClass3 : public TestClass
	{
	public:
		void virtualMethod(float var) override /* только float */
		{
			const string& text = to_string(var);
			cout << "virtual TestClass3::virtualMethod(float " << text << ") override" << endl;
		}

		void virtualMethad(float var) override
		{

		}

	};

	class TestClass4 : public TestClass3
	{
	public:
		void virtualMethod(float var) final /* только float */
		{
			const string& text = to_string(var);
			cout << "virtual TestClass4::virtualMethod(bouble " << text << ") final" << endl;
		}
	};

	{
		int varInt = 10;
		TestClass item;
		item.virtualMethod(varInt);
	}

	{
		float varFloat = 10.456;
		TestClass2 item;
		item.virtualMethod(varFloat);
	}

	{
		int varInt = 33;
		TestClass3 item;
		item.virtualMethod(varInt);
	}

	{
		int varInt = 33;
		TestClass4 item;
		item.virtualMethod(varInt);
	}
}

enum TestEnum
{
	TEST_ENUM_FIRST,
	TEST_ENUM_SECOND,
	TEST_ENUM_THIRD
};

/* переопределение
enum TestEnum2
{
	FIRST
};*/

enum class TestClassEnum
{
	FIRST,
	SECOND,
	THIRD
};

enum class TestClassEnum2
{
	FIRST,
	SECOND,
	THIRD
};
void funenumClass()
{
	TestClass::line("funenumClass");

	{
		TestEnum item = TestEnum::TEST_ENUM_THIRD;

		if (item == TestEnum::TEST_ENUM_THIRD)
		{
			TestClass::message(to_string(static_cast<int>(item)));
		}
	}

	{
		TestClassEnum item = TestClassEnum::FIRST;

		if (item == TestClassEnum::FIRST)
		{
			TestClass::message(to_string(static_cast<int>(item)));
		}
	}

	{
		TestClassEnum2 item = TestClassEnum2::SECOND;

		if (item == TestClassEnum2::SECOND)
		{
			TestClass::message(to_string(static_cast<int>(item)));
		}
	}
}

void funLambda()
{
	TestClass::line("funLambda");

	function<void(void)> fVoid = []()
	{
		TestClass::lineShort("\tfunction<void(void)>");
		TestClass::message("void");
	};

	fVoid();

	{
		TestClass itemClass_0("Test_0");
		TestClass itemClass_1("Test_1");
		TestClass itemClass_2("Test_2");

		function<TestClass(TestClass)> fTestClass = [&itemClass_1](const TestClass& itemClass)
		{
			TestClass::lineShort("\tfunction<TestClass(TestClass)>");
			return itemClass_1 + itemClass;
		};

		itemClass_0.action();
		itemClass_0 = fTestClass(itemClass_2);
		itemClass_0.action();
	}

	{
		TestClass itemClass_0("Test_0");
		TestClass itemClass_1("Test_1");
		TestClass itemClass_2("Test_2");

		auto fTestClass = [&itemClass_1](const TestClass& itemClass)
		{
			TestClass::lineShort("\tauto");
			return itemClass_1 + itemClass;
		};

		itemClass_0.action();
		itemClass_0 = fTestClass(itemClass_2);
		itemClass_0.action();
	}
}

void funLambdaForEach()
{
	TestClass::line("funLambdaForEach");

	vector<TestClass> testArray;

	testArray.push_back(TestClass("item_0"));
	testArray.push_back(TestClass("item_1"));
	testArray.push_back(TestClass("item_2"));
	testArray.push_back(TestClass("item_3"));

	for_each(begin(testArray), testArray.end(), [](TestClass& item)
	{
		item.action();
	});

	TestClass::lineShort();

	function<void(TestClass&)> funL = [testArray](TestClass& item)
	{
		if (item != testArray[1])
		{
			item.action();
		}
		else
		{
			TestClass::message("hidden");
		}
	};

	vector<TestClass>::iterator itBegin = testArray.begin();
	vector<TestClass>::iterator itEnd = testArray.end();
	for_each(itBegin, itEnd, funL);
}

void funStatic_Assert()
{
	TestClass::line("funStatic_Assert");

	{
		const int var = 10;
		static_assert(var == 10, "ERROR var != 10");

		TestClass::message("const int var = 1 - is int, OK");
	}

	/* ERROR
	{
		const int var = 9;
		static_assert(var == 10, "ERROR var != 10");
	}*/
}

void funSizeof()
{
	TestClass::line("funSizeof");

	class TCEmpty
	{
	public:
		//char c;
		//void fun() {};
	};

	TCEmpty itemEmpty;
	int sizeEmpty = sizeof(itemEmpty);

	//---------------

	class TCBase
	{
	public:
		void fun() {};
		virtual void vFun() {};
		virtual void vFun2() {};
		virtual void vFun3() {};
		virtual void vFun4() {};
		virtual void vFun5() {};
		virtual void vFun6() {};
		virtual void vFun7() {};
		virtual void vFun8() {};
		virtual void vFun9() {};
		virtual void vFun10() {};
	};

	TCBase itemB;
	int sizeB = sizeof(itemB);

	//---------------

	class TC2 : public TCBase
	{
	public:
		int i;
		//char c;
		
		//void vFun() {};
	};

	TC2 item2;
	int size2 = sizeof(item2);

	//---------------

	class TCIntBoolChar
	{
	public:
		//bool _b1;
		//bool _b2;
		//bool _b3;
		//bool _b4;
		//bool _b5;
		int _i;
	};

	class TC3
	{
	public:
		//int i;
		bool b;
		//char c;
		//bool b2;
		//bool b3;
		//bool b4;
		//bool b5;

		TCIntBoolChar data;

		void vFun() {};
	};

	TC3 item3;
	int size3 = sizeof(item3);

	//----------------------

	class TCChar
	{
	public:
		char c;

		void vFun() {};
	};

	TCChar itemChar;
	int sizeChar = sizeof(itemChar);

	//-------------------

	class TCBool
	{
	public:
		bool b;

		void vFun() {};
	};

	TCBool itemBool;
	int sizeBool = sizeof(itemBool);

	//-------------------

	class TCBoolInt
	{
	public:
		bool b;
		int i;

		void vFun() {};
	};

	TCBoolInt itemBoolInt;
	int sizeBoolInt = sizeof(itemBoolInt);

	//-------------------
	class TCIntBool
	{
	public:
		int i;
		bool b;

		void vFun() {};
	};

	TCIntBool itemIntBool;
	int sizeIntBool = sizeof(itemIntBool);

	//-------------------

	string text;
	text = "TCEmpty sizeof = " + to_string(sizeEmpty) + "\n" +
			"TCB sizeof = " + to_string(sizeB) + "\n" +
			"TC2 sizeof = " + to_string(size2) + "\n" +
			"TC3 sizeof = " + to_string(size3) + "\n" +
			"TCChar sizeof = " + to_string(sizeChar) + "\n" +
			"TCBool sizeof = " + to_string(sizeBool) + "\n" +
			"TCBoolInt sizeof = " + to_string(sizeBoolInt) + "\n" +
			"TCIntBool sizeof = " + to_string(sizeIntBool);
	TestClass::message(text);
}

void sort()
{
	TestClass::line("sort");

	int array[] = {8, 4, 0, 1, 2, 5, 7, 3, 9, 6};
	int count = sizeof(array)/sizeof(array[0]);

	for (int i = 0; i < count; ++i)
	{
		cout << array[i] << ' ';
	}

	for (int i = 0; i < count; ++i)
	{
		for (int j = (count - 1); j >= 0; --j)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}

	TestClass::line();
	for (int i = 0; i < count; ++i)
	{
		cout << array[i] << ' ';
	}
}

//---

class ThrowClass
{
private:
	int i = 0;

public:
	ThrowClass()
	{
		TestClass::message("ThrowClass");
	}

	~ThrowClass()
	{
		TestClass::message("~ThrowClass");
	}

	virtual string fun()
	{
		return "ThrowClass::fun()";
	}
};

class ThrowClassTwo : public ThrowClass
{
public:
	ThrowClassTwo()
	{
		TestClass::message("ThrowClassTwo");
	}

	~ThrowClassTwo()
	{
		TestClass::message("~ThrowClassTwo");
	}

	string fun()
	{
		return "ThrowClassTwo::fun()";
	}
};


double divide(int a, int b)
{
	if (b == 1)
		throw b;

	if (b == 2)
	{
		throw ThrowClass();
	}

	if (b == 3)
	{
		throw ThrowClassTwo();
	}

	if (b == 0)
		throw "throw: Division by zero!";

	int c = a / b;

	return c;
}

void funThrow()
{
	TestClass::line("funThrow");

	{
		TestClass::lineShort("0");

		int a = 123;
		int b = 0;

		try
		{
			double z = a / b;
			TestClass::message("OK: ...");
		}
		catch (...)
		{
			TestClass::message("ERROR: ...");
			TestClass::message("ERROR: ...");
		}
	}

	{
		TestClass::lineShort("1");

		int a = 123;
		int b = 1;
		double z;

		try
		{
			z = divide(a, b);
			TestClass::message("OK: ...");
		}
		catch (...)
		{
			TestClass::message("ERROR: ...");
		}
	}

	{
		TestClass::lineShort("1");

		int a = 123;
		int b = 2;
		double z;

		try
		{
			z = divide(a, b);
			TestClass::message("OK: ...");
		}
		catch (const int intVar)
		{
			std::cout << "ERROR int: " << intVar << std::endl;
		}
		catch (const char* msg)
		{
			std::cout << "ERROR msg: " << msg << std::endl;
		}

		/*
		catch (ThrowClassTwo)
		{
		std::cout << "ERROR ThrowClassTwo: " << std::endl;
		}
		catch (ThrowClass)
		{
			std::cout << "ERROR ThrowClass: " << std::endl;
		}*/

		catch (ThrowClassTwo& tClass)
		{
			std::cout << "ERROR ThrowClassTwo: " << tClass.fun() << std::endl;
		}
		catch (ThrowClass& tClass)
		{
			std::cout << "ERROR ThrowClass: " << tClass.fun() << std::endl;
		}


		catch (...)
		{
			TestClass::message("ERROR: ...");
		}
	}
}

void testDataClass()
{
	TestClass::lineShort("testDataClass");

	DataClass::add("key_0");
	DataClass::add("key_1", (new DataClass("with_key_1")));
	DataClass::add("key_2");
	DataClass::add("key_3", (new DataClass("with_key_3")));
	DataClass::add("key_4");

	{
		DataClass* item = DataClass::getByName("key_0");
		printf("LOG: [ %s ] = %s\n", item->name().c_str(), item->_data.c_str());
	}

	{
		DataClass* item = DataClass::getByName("key_1");
		printf("LOG: [ %s ] = %s\n", item->name().c_str(), item->_data.c_str());
	}
	{
		DataClass* item = DataClass::getByName("key_3");
		printf("LOG: [ %s ] = %s\n", item->name().c_str(), item->_data.c_str());
	}
}


void testDataClassT()
{
	TestClass::lineShort("testDataClassT");

	class TestDataClass;
	typedef shared_ptr<TestDataClass> TestDataClassPtr;

	class TestDataClass : public DataClassT<TestDataClass>
	{
	private:
	public:
		string _data = "NONE";

	public:
		TestDataClass() {};
		TestDataClass(const string& data) { _data = data; };
	};

	TestDataClass::add("key_0");
	TestDataClass::add("key_1", (new TestDataClass("with_key_1")));
	TestDataClass::add("key_2");
	TestDataClass::add("key_3", (new TestDataClass("with_key_3")));
	TestDataClass::add("key_4");

	{
		TestDataClass* item = TestDataClass::getByName("key_0").get();
		printf("LOG: [ %s ] = %s\n", item->name().c_str(), item->_data.c_str());
	}

	{
		TestDataClassPtr& item = TestDataClass::getByName("key_1");
		printf("LOG: [ %s ] = %s\n", item->name().c_str(), item->_data.c_str());
	}

}

// virtual, override https://habrahabr.ru/post/182920/


#include "Cpp11.h"

constexpr int fun(int x, int y) {
	int z = x + y;
	return z;
}

void funConstexpr() {
	TestClass::lineShort("constexpr");

	//int* pVar23 = new int(23);
	//const int var15 = *pVar23; // если сделать так, то ERROR

	static const int Var23 = 23;
	const int var15 = Var23;

	constexpr int varRes = fun(11, var15);

	// varRes = varRes + 1; // ERROR
	cout << varRes << endl;

	//delete pVar23;
}

//------------------------------------

void funListInit() {
	TestClass::lineShort("List Init");
	{
		auto arrayInit = { "qwe", "asd", "zxc" };
		//auto arrayInit = { 12.5, 23.6, 34.7 };
		//auto arrayInit = { 12, 23, 1 };
		//auto arrayInit = { 12.0, 23, 1 }; // ERROR
		//auto arrayInit = { 12, 23, 1.6 }; // ERROR

		for (auto i: arrayInit) {
			cout << i << ' ';
		}
		cout << endl;
	}

	{
		struct S {
			char ch;
			int i;
		};

		S arrayInit[] = { {'q', 3}, {'w', 3}, {'e', 3} };

		for (auto i: arrayInit) {
			cout << '[' << i.ch << ' ' << i.i << "] ";
		}
		cout << endl;
	}
}

//------------------------------------

void funThread() {

}

//------------------------------------
//------------------------------------
//------------------------------------
//------------------------------------

void functionsCpp11() {
	TestClass::line("[ C++ 11 ]");

	funConstexpr();

	// Список инициализации
	funListInit();

	// Многопоточность
	funThread();

}

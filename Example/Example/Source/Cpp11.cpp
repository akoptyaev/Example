
#include "Cpp11.h"
#include <vector>
#include <map>
#include <tuple>
#include <functional>

#include "Inheritance.h"

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

class CWithoutEx
{
public:
	int i;

	//CWithoutEx() {}
	CWithoutEx(int _i) { i = _i; }
	CWithoutEx(int _i, int _i2) { i = _i + _i2; }
};

class CWithEx
{
public:
	int i;

	//CWithEx() {}
	explicit CWithEx(int _i) { i = _i; }
	CWithEx(int _i, int _i2) { i = _i + _i2; }
};
void funExclipt() {
	TestClass::lineShort("Exclipt");

		//CWithoutEx withoutEx0;
		CWithoutEx withoutEx1(33);
		CWithoutEx withoutEx2 = 22;
		CWithoutEx withoutEx3(55, 66);

		//CWithEx withEx0;
		CWithEx withEx1(33);
		// CWithEx withEx2 = 22; ERROR explicit запрещает использовать оператор = для инициализации
		CWithEx withEx3(55, 66);
}

//------------------------------------
int varFoo = 77;

template<typename T>
T foo(T x) {
	T _varFoo = varFoo * x;
	//cout << varFoo << endl;
	return _varFoo;
}

int foo() {
	cout << varFoo << endl;
	return varFoo;
}
int& foo1() {
	return varFoo;
}
const int foo2() {
	return varFoo;
}
const int& foo3() {
	return varFoo;
}

void funDecltype() {
	TestClass::lineShort("decltype");

	auto _i(varFoo);
	//cout << _i << endl;

	auto ri = foo();
	auto ri1 = foo1();
	auto ri2 = foo2();
	auto ri3 = foo3();

	//auto& ri4 = foo();
	//int& ri42 = foo();

	auto& ri5 = foo1();

	//auto& ri6 = foo2();
	//int& ri6 = foo2();
	
	auto& ri7 = foo3();

	auto&& ri8 = foo();
	auto&& ri9 = foo1();
	auto&& ri10 = foo2();
	auto&& ri11 = foo3();

	auto ri4a = foo(100.1f);
	cout << ri4a << endl;

	decltype(foo(10)) ri4d = foo(100.1f);
	cout << ri4d << endl;

	int k = 5;
	//decltype(k) && rk = k;

	decltype(foo()) && ri12 = foo();
	decltype(foo1()) && ri13 = foo1();

	int i = 3;
	decltype(i) ri14;
//	decltype((i)) ri15;

	decltype(auto) ri16 = foo1();
}

/*void fooAuto(auto i) {
	
}*/

template<typename T>
auto fooAutoT(T i) {
	return i;
}

template<typename T>
void fooT(T t) {
}

template<typename T>
void fooT2(T& t, const T& t2)
//void fill_from_list(T& cont, const T& l)
{
}

void funDecltype2() {
	TestClass::lineShort("decltype 2");

	auto lmbd = [](auto i) {
		return i;
	};
	
	decltype(auto) var = lmbd(234); //WTF?!
	auto var2 = { 1, 2, 3 }; //Если да, какой тип будет у var?
	
	fooT(1);
	//fooT({ 1, 2, 3 });

	{
		int varInt;
		// fooT2(varInt, { 1, 2, 3 }); // Так ошибка!
	}
	{
		std::vector<int> varInt;
		fooT2(varInt, { 1, 2, 3 }); // А так не ошибка!
	}
	{
		std::map<int, int> varInt;
		//fooT2(varInt, { 1, 2, 3 }); // А так ТОЖЕ ошибка!
	}
}

//------------------------------------

void funTuple() {
	TestClass::lineShort("tuple");


	tuple<int, Base, float, string> t;

	t = make_tuple(2, 4, 6, "9sss");

	cout << std::get<0>(t) SPACE std::get<1>(t).f SPACE std::get<2>(t) SPACE std::get<3>(t) << endl;
}

//------------------------------------

int sum(int lhs, int rhs)
{
	return lhs + rhs;
}

std::string sumStr(std::string fhs, std::string lhs, std::string rhs, std::string xhs)
{
	return fhs + '.' +  lhs + '.' + rhs + '.' + xhs;
}


void funBind() {
	TestClass::lineShort("bind");

	//auto b = std::bind(fooAutoT, 10);

	auto b = std::bind(sum, 3, std::placeholders::_2);

	COUT sum(6, 9) SPACE b(3, 6) ENDL;

	auto bStr = std::bind(sumStr, "First", std::placeholders::_3, "bbb", std::placeholders::_4);

	COUT bStr("AAA", "qwe", "asd", "BBB", "cccc") ENDL;
}

//------------------------------------

void functionsCpp11() {
	TestClass::line("[ C++ 11 ]");

	funConstexpr();

	// Список инициализации
	funListInit();

	// Многопоточность
	funThread();

	// explictic явные конструкторы
	funExclipt();

	// decltype
	funDecltype();

	funDecltype2();

	// tuple
	funTuple();

	// bind
	funBind();
}

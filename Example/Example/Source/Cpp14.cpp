
#include "Cpp14.h"
#include <functional>
#include "Inheritance.h"

auto funAuto() {
	auto var = 10; // int
	//auto var = "10"s;
	//auto var = "10"; // const char* // ERROR => var = var + var;

	return var;
}

template<typename T>
auto funAutoRecurs(T& var) {
	cout << "var = " << var << endl;

	--var;

	if (var <= 0) {
		return var; // Нужно определить возвращаемый тип перед вызавом рекурсивной функции
	} else {
			var = funAutoRecurs(var);
	}

	/*if (var > 0) { так нельзя
		var = funAutoRecurs(var);
	}
	else {
		return var;
	}*/

	return var;
}

void funReturnAuto() {
	TestClass::lineShort("funAuto()");
	std::cout << std::endl;

	auto var = funAuto();
	var = var + var;
	cout << "var = " << var << endl;

	//---

	TestClass::lineShort("funAuto() recursive");
	auto varInt = 5.1;
	funAutoRecurs(varInt);

	//funAutoRecurs(5); // ERROR
}

//------------------------------------
template<typename Tvar>
Tvar tempalteVar = 15.5;

template<typename T>
T pi = T('q');

void funTemplateVar() {
	TestClass::lineShort("TemplateVar");

	cout << tempalteVar<char> << endl;
	cout << tempalteVar<int> << endl;
	cout << tempalteVar<bool> << endl;
	cout << pi<char> << endl;
	cout << pi<float> << endl;
	cout << pi<int> << endl;

	int varInt = pi<int>;
	char varChar = pi<char>;
	float varFloat = pi<float>;
	cout << varInt << ' ' << varChar << ' ' << varFloat << ' ' << endl;
}

//-------------------------------------

void funLiteralVar() {
	TestClass::lineShort("LiteralVar");

	int i0 = 0;
	int i0l = 00;

	int i2 = 2;
	int i2l = 0x0B;

	auto ai = 1;
	auto af = 1.1f;
	auto acl = 'c';
	auto aCharl = "const char*";
	auto aStrl = "std::basic_string"s;
	auto ail = 0x0a;

	cout << i0 << ' ' << i0l << ' ' << i2 << ' ' << i2l << ' ' << ai << ' ' << af << ' ' << ' ' << acl << ' ' << aCharl << ' ' << aStrl << ' ' << ail << ' ' << endl;
}

//-------------------------------------

void funSeparateLiteral() {
	TestClass::lineShort("SeparateLiteral");

	int var1M = 1'000'000;
	float varF = 1'2'3.1'2'3f;

	cout << var1M << endl;
	cout << varF << endl;
}

//-------------------------------------

void funAutolambda() {
	TestClass::lineShort("Autolambda");

	{
		//std::function<int()> funL = []() {
		std::function<int()> funL = []{
			return 1234567;
		};
		cout << funL() << endl;

		int varForL = 10;
		int* pVarForL2 = new int(10);

		//auto funLAuto = [varForL] { // нельзя ЕСЛИ НУЖНО изменить !!!
		auto funLAuto = [&varForL, pVarForL2] { // Захват по ссылке, указатель можно передать как переменную
			varForL = varForL * 222;
			*pVarForL2 = *pVarForL2 * 333;
			return 7654321;
		};
		cout << funL() << ' ' << funLAuto() << " : " << varForL << " : " << *pVarForL2 << endl;

		delete pVarForL2;
	}

	{
		auto funL = [](auto x, auto y) {
			x += y;
			return x;
		};

		{
			auto z = funL(3, 6.7f);
			cout << z << endl;
		}
		{
			auto z = funL("Q"s, "rty"s);
			cout << z << endl;
		}
	}
}

//-------------------------------------

void funCaptureVarForLambda() {
	TestClass::lineShort("Capture Var For Lambda");

	{
		auto funForLamda = [](auto var) {
			return (var + var);
		};

		{
			auto text = "Text"s;

			auto funL = [z = funForLamda(text)](auto x, auto y) {
				x += y;
				cout << z << endl;;
				return x;
			};

			{
				auto z = funL(3, 6.7f);
				cout << z << endl;
			}
			{
				auto z = funL("Q"s, "rty"s);
				cout << z << endl;
			}
		}

		{
			auto var = 11;

			auto funL = [z = funForLamda(var)](auto x, auto y) {
				x += y;
				cout << z << endl;;
				return x;
			};

			{
				auto z = funL(99.1, 7);
				cout << z << endl;
			}
			{
				auto z = funL("Pop "s, " op"s);
				cout << z << endl;
			}
		}
	}
}

//-------------------------------------

void normFunction() {
	cout << "normFunction" << endl;
}

[[deprecated]] void depFunction() {
	cout << "depFunction" << endl;
}

[[deprecated("Not using that function!")]]
void depWithTextFunction() {
	cout << "depWithTextFunction" << endl;
}

void funDeprecated() {
	TestClass::lineShort("[[deprecated]]");

	//depWithTextFunction();
	normFunction();
	//depFunction();
}

//-------------------------------------

void funExange() {
	TestClass::lineShort("std::Exange");

	{
		int var1 = 10;
		int var2 = 20;
		int var3 = 30;

		cout << var1 SPACE var2 SPACE var3 << endl;

		var3 = std::exchange(var1, var2);

		cout << var1 SPACE var2 SPACE var3 << endl;
	}

	{
		VSPACE;

		Base var1;
		Base var2;
		Base var3;

		cout << var1.f SPACE var2.f SPACE var3.f << endl;

		var3 = std::exchange(var1, var2);

		cout << var1.f SPACE var2.f SPACE var3.f << endl;
	}
}



//-------------------------------------
//-------------------------------------
//-------------------------------------
//-------------------------------------

void functionsCpp14() {
	TestClass::line("[ C++ 14 ]");

	// Функция может возвращать auto
	funReturnAuto();

	// Шаблонные переменные. Только глобальные переменные.
	funTemplateVar();

	// Литералы, в том числе и двоичных чисел std::basic_string std::chrono
	funLiteralVar();

	// Литералы разделители для чисел
	funSeparateLiteral();

	// В лямбда функции можно использовать auto
	funAutolambda();

	// Захват переменной с фыражением/функцией
	funCaptureVarForLambda();

	// Атрибут [[deprecated]]
	funDeprecated();

	// std::Exange
	funExange();

}

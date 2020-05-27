
#include "Cpp14.h"

//auto funAuto();

auto funAuto() {
	auto var = 10; // int
	//auto var = "10"s;
	//auto var = "10"; // const char* // ERROR => var = var + var;

	return var;
}

// Функция может возвращать auto
void funReturnAuto() {
	TestClass::line("funAuto()");
	std::cout << std::endl;

	auto var = funAuto();
	var = var + var;
	cout << "var = " << var << endl;
}

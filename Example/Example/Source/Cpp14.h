#pragma once

#include "TestClass.h"

void funAuto() {
	TestClass::line("funAuto()");
	std::cout << std::endl;
}

void functionsCpp14() {
	funAuto();
}

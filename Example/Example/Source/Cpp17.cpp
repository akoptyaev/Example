
#include "Cpp17.h"
#include <optional>
#include <variant>
#include <any>
#include "Inheritance.h"

//-------------------------------------

template <typename T>
T fun(const T& var) {
	return var;
}

template <typename T>
std::optional<float> funO(const T& var, bool b) {
	if (b)
		return var;
	else
		return {};
}

void funOptional() {
	TestClass::lineShort("std::optional");
	{
		std::optional<float> floatVar = funO(3.33f, true);
		cout << floatVar.value_or(999.9f) SPACE(floatVar.has_value() ? "YES" : "no") << endl;
		std::any typeVar = floatVar.value_or(999.9f);
		std::any typeVar2 = fun(3.33f);
		cout << typeVar.type().name() SPACE typeVar2.type().name() << endl;
	}
	{
		VSPACE;
		int i = 2;
		std::optional<float> floatVar = funO(i, false);
		cout << floatVar.value_or(999.9f) SPACE(floatVar.has_value() ? "YES" : "no") << endl;
		std::any typeVar = floatVar.value_or(999.9f);
		std::any typeVar2 = fun(i);
		cout << typeVar.type().name() SPACE typeVar2.type().name() << endl;
	}
	{
		VSPACE;
		std::optional<float> floatVar = funO(3.33, true);
		cout << floatVar.value_or(999.9f) SPACE(floatVar.has_value() ? "YES" : "no") << endl;
		std::any typeVar = floatVar.value_or(999.9f);
		std::any typeVar2 = fun(3.33);
		cout << typeVar.type().name() SPACE typeVar2.type().name() << endl;
	}
	{
		VSPACE;
		std::optional<float> floatVar = funO('Q', false);
		cout << floatVar.value_or(999.9f) SPACE(floatVar.has_value() ? "YES" : "no") << endl;
		std::any typeVar = floatVar.value_or(999.9f);
		std::any typeVar2 = fun('Q');
		cout << typeVar.type().name() SPACE typeVar2.type().name() << endl;
	}
	{
		VSPACE;
		cout << "Base" << endl;

		Base obj;
		std::optional<Base> floatVar = fun(10);
		std::any typeVar = floatVar.value();
		std::any typeVar2 = fun(obj);
		cout << typeVar.type().name() SPACE typeVar2.type().name() << endl;
	}
	{
		//VSPACE
		std::optional<std::string> floatVar; // = fun("text");
		cout << (floatVar.has_value() ? "YES" : "no") << endl;
		//floatVar = fun("text"s);
		//cout << floatVar.value() SPACE(floatVar.has_value() ? "YES" : "no") << endl;
	}
	TestClass::lineShort("std::optional END");
}

void funVariant() {
	TestClass::lineShort("std::variant");
	{
		{
			std::variant<int, float> v;
			v = 12; // v contains int
			v = 3.3f;
			int i = 0;// = std::get<int>(v);
			int f = std::get<float>(v);
			cout << i SPACE f << endl;
		}

		/*std::variant<float, string, const char*> dataVariant = fun(3.33f);
		dataVariant = string("string");
		dataVariant = "char*";

		string s = std::get<string>(dataVariant);
		auto c = std::get<const char*>(dataVariant);
		auto f = std::get<float>(dataVariant);
		//cout << std::get<string>(dataVariant) SPACE std::get<const char*>(dataVariant) SPACE std::get<float>(dataVariant) SPACE std::get<float>(dataVariant) << endl;*/
	}
}

void funAny() {
	TestClass::lineShort("std::any");
	{
		std::any typeVar = fun(3.33f);
		cout << typeVar.type().name() SPACE(typeVar.has_value() ? "YES" : "no") SPACE any_cast<float>(typeVar)  << endl;
	}
	{
		int i = 2;
		std::any typeVar = fun(i);
		cout << typeVar.type().name() SPACE(typeVar.has_value() ? "YES" : "no") SPACE any_cast<int>(typeVar) << endl;
	}
	{
		std::any typeVar = fun(3.33);
		cout << typeVar.type().name() SPACE(typeVar.has_value() ? "YES" : "no") SPACE any_cast<double>(typeVar) << endl;
	}
	{
		std::any typeVar = fun('Q');
		cout << typeVar.type().name() SPACE(typeVar.has_value() ? "YES" : "no") SPACE any_cast<char>(typeVar) << endl;
	}
	{
		string text("text");
		std::any typeVar = fun(text);  //"text"; // ERROR fun("text");
		cout << typeVar.type().name() SPACE(typeVar.has_value() ? "YES" : "no") SPACE any_cast<string>(typeVar) << endl;
	}
}

//------------------------------------

void functionsCpp17() {
	TestClass::line("[ C++ 17 ]");

	// std::optional
	funOptional();

	// std::variant
	funVariant();

	// std::Any
	funAny();

}

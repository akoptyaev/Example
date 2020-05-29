
#include "Inheritance.h"

//------------------------------------
namespace Empaty_Class {
	class Empty
	{
	};

	class Base
	{
	public:
		Base() {
			cout << "\t\t\tBase" << endl;
		}
		~Base() {
			cout << "\t\t\t~Base" << endl;
		}
	};


	class ClassA : public Base
	{
	public:
		ClassA() {
			cout << "\t\tClassA" << endl;
		}
		~ClassA() {
			cout << "\t\t~ClassA" << endl;
		}
		void fun() {}
	};

	class ClassB : public Base
	{
	public:
		ClassB() {
			cout << "\t\tClassB" << endl;
		}
		~ClassB() {
			cout << "\t\t~ClassB" << endl;
		}
	};

	//class ClassDerived : public ClassA, ClassB, Base // 2
	//class ClassDerived : public ClassA, ClassB // 1
	//class ClassDerived : public ClassA, Base // 1
	//class ClassDerived : public ClassA, ClassB, Empty // 2
	class ClassDerived : public ClassA, ClassB, Base, Empty // 3 Сколько уровней, столько байт
	{
	public:
		ClassDerived() {
			cout << "\tClassDerived" << endl;
		}
		~ClassDerived() {
			cout << "\t~ClassDerived" << endl;
		}
	};

	void fun() {
		TestClass::lineShort("Empaty_Class");
		{
			ClassDerived test;
			size_t s = sizeof(test);
			cout << "size ClassDerived = " << s << endl;
		}
		{
			Base test;
			size_t s = sizeof(test);
			cout << "size Base = " << s << endl;
		}
		{
			Empty test;
			size_t s = sizeof(test);
			cout << "size Empty = " << s << endl;
		}
	}
}
//------------------------------------

namespace Var_Class {
	class Base
	{
	public:
		const float f = help::GetRandom(0, 1000);

		Base() {
			cout << "\t\t\tBase f: " << f << endl;
		}
		~Base() {
			cout << "\t\t\t~Base f: " << f << endl;
		}
	};


	class ClassA : public Base
	{
	public:
		ClassA() {
			cout << "\t\tClassA" << endl;
		}
		~ClassA() {
			cout << "\t\t~ClassA" << endl;
		}
	};

	class ClassB : public Base
	{
	public:
		ClassB() {
			cout << "\t\tClassB" << endl;
		}
		~ClassB() {
			cout << "\t\t~ClassB" << endl;
		}
	};

	class ClassDerived : public ClassA, ClassB, Base
	{
	public:
		ClassDerived() {
			cout << "\tClassDerived" << endl;
		}
		~ClassDerived() {
			cout << "\t~ClassDerived" << endl;
		}
	};

	void fun() {
	TestClass::lineShort("Var_Class");
		{
			ClassDerived test;
			size_t s = sizeof(test);
			cout << "size ClassDerived = " << s << endl;
		}
		{
			Base test;
			size_t s = sizeof(test);
			cout << "size Base = " << s << endl;
		}

		{
			cout << "ptr" << endl;
			ClassDerived* test = new ClassDerived();
			delete test;
		}
	}
}

//------------------------------------

namespace Virtual_Class {
	class Base
	{
	public:
		const float f = help::GetRandom(0, 1000);

		Base() {
			cout << "\t\t\tBase f: " << f << endl;
		}
		~Base() {
			cout << "\t\t\t~Base f: " << f << endl;
		}
		//virtual void fun() {}
	};


	class ClassA : public Base
	{
	public:
		ClassA() {
			cout << "\t\tClassA" << endl;
		}
		~ClassA() {
			cout << "\t\t~ClassA" << endl;
		}
		virtual void fun() {}
	};

	class ClassB : public Base
	{
	public:
		ClassB() {
			cout << "\t\tClassB" << endl;
		}
		~ClassB() {
			cout << "\t\t~ClassB" << endl;
		}
		virtual void fun() {}
	};

	class ClassDerived : public ClassA, ClassB, Base
	{
	public:
		ClassDerived() {
			cout << "\tClassDerived" << endl;
		}
		~ClassDerived() {
			cout << "\t~ClassDerived" << endl;
		}
	};

	void fun() {
		TestClass::lineShort("Virtual_Class");
		{
			ClassDerived test;
			size_t s = sizeof(test);
			cout << "size = " << s << endl;
		}
		{
			Base test;
			size_t s = sizeof(test);
			cout << "size Base = " << s << endl;
		}
		{
			cout << "ptr ------" << endl;
			ClassDerived* test = new ClassDerived();
			delete test;
		}
	}
}

//------------------------------------

void funSwap() {
	TestClass::lineShort("swap");

	{
		TestClass::lineShort("swap 1");

		Base item1;
			TestClass::spaceVert();
		Base item2;
			TestClass::spaceVert();
		Base itemTemp;
			TestClass::spaceVert();

		itemTemp = item1;
			TestClass::spaceVert();
		item1 = item2;
			TestClass::spaceVert();
		item2 = itemTemp;
			TestClass::spaceVert();
	}

	TestClass::spaceVert();
	{
		TestClass::lineShort("swap 2");

		Base item1;
			TestClass::spaceVert();
		Base item2;
			TestClass::spaceVert();

		Base itemTemp(item1);
			TestClass::spaceVert();
		item1 = item2;
			TestClass::spaceVert();
		item2 = itemTemp;
			TestClass::spaceVert();
	}

	TestClass::spaceVert();
	{
		TestClass::lineShort("swap 3");

		Base item1;
			TestClass::spaceVert();
		Base item2;
			TestClass::spaceVert();

			std::swap(item1, item2);
	}
}

//------------------------------------

void funAlign() {
	TestClass::lineShort("Align");

	class C_B
	{

	};

	class C_F
	{
	public:
		void fun() {}
	};

	class C_V {
	public:
		virtual ~C_V() = default;
		virtual void fun() {

		}
	};

	class C_Var
	{
	public:
		bool d;
		int i;
	};

	class C_VarF
	{
	public:
		bool d;
		int i;
		void fun() {}
	};

	class C_VarFV
	{
	public:
		bool d;
		int i;
		virtual ~C_VarFV() = default;
		virtual void fun() {}
	};

	class C_V_vVarFV
	{
	public:
		bool b;
		C_VarFV obj;
	};

	class C_V_VarFV : public C_VarFV
	{
	public:
		bool b;
		virtual void fun() {}
	};

	COUT "C_B" SPACE sizeof(C_B) ENDL;
	COUT "C_F" SPACE sizeof(C_F) ENDL;
	COUT "C_V" SPACE sizeof(C_V) ENDL;
	COUT "C_Var" SPACE sizeof(C_Var) ENDL;
	COUT "C_VarF" SPACE sizeof(C_VarF) ENDL;
	COUT "C_VarFV" SPACE sizeof(C_VarFV) ENDL;

	COUT "C_V_vVarFV" SPACE sizeof(C_V_vVarFV) ENDL;
	COUT "C_V_VarFV" SPACE sizeof(C_V_VarFV) ENDL;

	VSPACE;

	class C_ArFloat // >> 40
	{
	public:
		float f[10];
	};

	class alignas(32) C_ArFloat_alignas32 // 32 >> 64
	{
	public:
		float f[10];
	};

	class alignas(64) C_ArFloat_alignas64 // 64 >> 64
	{
	public:
		float f[10];
	};

	COUT "C_ArFloat" SPACE sizeof(C_ArFloat) ENDL;
	COUT "C_ArFloat_alignas32" SPACE sizeof(C_ArFloat_alignas32) ENDL;
	COUT "C_ArFloat_alignas64" SPACE sizeof(C_ArFloat_alignas64) ENDL;

	COUT "alignof(C_V_VarFV)" SPACE alignof(C_V_VarFV) ENDL;
	COUT "alignof(C_F)" SPACE alignof(C_F) ENDL;
}

//------------------------------------

void functionsInheritance() {
	TestClass::line("[ Inheritance ]");

	//Empaty_Class::fun();
	//Var_Class::fun();
	//Virtual_Class::fun();

	//funSwap();

	funAlign();
}

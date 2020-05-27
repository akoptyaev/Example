#include "TestClass.h"

#include <memory> 
#include <iostream> 
#include <string>

using namespace std;

class C1
{
	bool b_c1[5];
	int i_c1;
};

class C2
{
	C1 c1;
	bool b_c2;
	int i_c2;
};

int main(int argc, char * argv[])
{
	{
		cout << endl;

		int s_C1 = sizeof(C1);
		int s_C2 = sizeof(C2);

		cout << "C1 = " << s_C1 << "\nC2 = " << s_C2 << endl;
	}

	/*{ cout << endl;

		TestClass t;
		TestClass t2;
		t.generate(7);
		t2 = t;
	}*/

	{ cout << endl;
		TestClass t;
		t = TestClass();
		cout << "t.count = " << t.count << endl;
	}

	{ cout << endl;

		unsigned char c1 = std::numeric_limits<unsigned char>::max();
		unsigned char c2 = std::numeric_limits<unsigned char>::max();
		int i1 = std::numeric_limits<int>::max();
		int i2 = std::numeric_limits<int>::max();
		unsigned int u1 = std::numeric_limits<unsigned int>::max();

		cout << "c1 = '" << c1 << "' c2 = '" << c2 << "' i1 = " << i1 << " i2 = " << i2 << endl;

		auto x = c1 + c2;
		auto y = i1 + i2;
		auto z = i1 + u1;

		cout << "x = " << x << " y = " << y << " z = " << z << endl;
	}

	{ cout << endl;
		int size = sizeof(TestClass);
		cout << "TclassC = " << size << endl;

		//TclassC tclassC;
	}

	{ cout << endl;

		int int25 = 25;
		int int6 = int25 >> 2;

		int iAndI = int25 & int6;
		int iElseI = int25 | int6;

		cout << "int25 = " << int25 << endl;
		cout << "int6 = " << int6 << endl;

		cout << "iAndI = " << iAndI << endl;
		cout << "iElseI = " << iElseI << endl;
	}


	{ cout << endl;

		const int ci = 9;
		cout << "ci = " << ci << endl;

		int& i = const_cast<int&>(ci);
		i += 1;
		cout << "i = " << i << " ci = " << ci << endl;

		int* pi = const_cast<int*>(&ci);
		*pi = *pi + 1;
		cout << "ci = " << ci << " i = " << i << " *pi = " << *pi << endl;
	}

	{ cout << endl;

		const int* cpi = new int(9);
		cout << "*cpi = " << *cpi << endl;

		int* pi = const_cast<int*>(cpi);
		*pi += 1;
		cout << "*cpi = " << *cpi << " *pi = " << *pi << endl;
	}


	char message[256];
	std::cout << "END.\n Enter char." << std::endl;
	std::cin >> message;
	return 0;
}

/*
char message[256];
std::cout << "END.\n Enter char." << std::endl;
std::cin >> message;
*/
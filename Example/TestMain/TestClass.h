
#include <iostream> 

using namespace std;

class TestClass
{
public:
	int count;
	int* pArray = nullptr;

	TestClass()
	{
		cout << "TestClass" << endl;
	}

	~TestClass()
	{
		cout << "~TestClass pArray " << pArray << endl;

		delete[] pArray;
		pArray = nullptr;
	}

	TestClass(const TestClass& item)
	{
		if (&item == this)
			return;

		if (!item.pArray)
			return;

		count = item.count;
		pArray = new int[count];
		memcpy(pArray, item.pArray, (count * sizeof(int)));

		cout << "TestClass(" << item.count << ' ' << pArray  << ")" << " count = " << count << ' ' << pArray << endl;
	}

	TestClass& operator=(const TestClass& item)
	{
		if (&item == this)
			return *this;

		if (!item.pArray)
			return *this;

		count = item.count;
		pArray = new int[count];
		memcpy(pArray, item.pArray, (count * sizeof(int)));

		cout << "operator=(" << item.count << ' ' << pArray << ")" << " count = " << count << ' ' << pArray << endl;

		return *this;
	}

	TestClass(TestClass&& item)
	{
		if (&item == this)
			return;

		if (!item.pArray)
			return;

		count = move(item.count);
		pArray = move(item.pArray);

		cout << "TestClass( && " << item.count << ' ' << pArray << ")" << " count = " << count << ' ' << pArray << endl;

		item.count = 0;
		item.pArray = nullptr;
	}

	TestClass& operator=(TestClass&& item)
	{
		if (&item == this)
			return *this;

		if (!item.pArray)
			return *this;

		count = move(item.count);
		pArray = move(item.pArray);

		cout << "operator=( && " << item.count << ' ' << pArray << ")" << " count = " << count << ' ' << pArray << endl;

		item.count = 0;
		item.pArray = nullptr;

		return *this;
	}

	void generate(const int& count_)
	{
		if (pArray)
			delete[] pArray;

		count = count_;
		pArray = new int[count];

		for (int i = 0; i < count; ++i)
		{
			pArray[i] = i;
		}

		cout << "generate()" << " count = " << count << ' ' << pArray << endl;
	}
};


TestClass funTestClass()
{
	TestClass temp;
	temp.generate(5);
	return temp;
}

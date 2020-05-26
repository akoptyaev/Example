#pragma once
#include "TestClass.h"

class CA
{
public:
	int var = 5;
	int varA = 1;
};

class CB
{
public:
	int var = 6;
	int varB = 1;
};

class CC
{
public:
	int var = 7;
	int varC = 1;
};

//----------------------

template <class TA, class TB>
struct ST1_2
{
	TA _tA;
	TB _tB;
};

template <class T1, typename T2>
CC funT2(T1 v1, T2 v2)
{
	CC cC;
	return cC;
}

template <class T1, typename T2, typename T3>
T3 funT2T(T3 v3, T2 v2, T1 v1)
{
	T3 v;
	v.varC = 12;
	return v;
}

template <class T1, typename T2, typename T3>
T3 funT2T_var(T3 v3, T2 v2, T1 v1)
{
	T3 v;
	v.var = 55;
	return v;
}

template <class T4>
int funT4(T4 t)
{
	return 1;
}

template <class T4>
T4 funT4R(T4 t)
{
	T4 v;
	return v;
}

//----------------------

template <class TA>
class CAB: public ST1_2<TA, int>
{
public:
	TA _var;
};

template <class TA, class TB = void>
class CSAB : public ST1_2<TA, int>
{
public:
	ST1_2<CA, TB> _var;
};

//----------------------

void functionsTemplate()
{
	TestClass::line("functionsTemplate");

	int vInt = 0;
	CA cA;
	CB cB;
	CC cC;
	cC.varC = 0;

	cC = funT2(cA, cA);

	ST1_2<int, char> sAB;
	sAB._tA = 0;
	sAB._tB = '0';
	cC = funT2(sAB, cA);

	{
		cC = funT2T(cC, cA, cB);
		cout << "cC = " << cC.varC << endl;
	}

	{
		cB = funT2T_var(cB, cA, cC);
		cout << "cB = " << cB.var << endl;
	}

	ST1_2<CA, CB> s_cAcB;
	cC = funT2(sAB, s_cAcB);

	CAB<std::string> c_CAB;
	cC = funT2(c_CAB, s_cAcB);

	CAB<ST1_2<int*, std::string>> c_CAB2;
	cC = funT2(c_CAB2, s_cAcB);

	CSAB<ST1_2<int*, std::string>, char> c_CAB3;
	cC = funT2(c_CAB2, c_CAB3);

	c_CAB3._var._tA.varA = 11;

	vInt = funT4(cA);

	cA = funT4R(cA);

	TestClass::lineShort();
}

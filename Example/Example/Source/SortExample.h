#ifndef __SORT_H__
#define __SORT_H__

#include "TestClass.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void funBubleSort()
{
	TestClass::line("funBubleSort");

	int arrayInt[] = {9, 8, 5, 3, 0, 1, 2, 4, 7, 6};
	int size = sizeof(arrayInt) / sizeof(arrayInt[0]);

	for_each(begin(arrayInt), end(arrayInt), [](const int& var) { cout << var << ' '; });
	cout << '\n';


	for (int i = 0; i < size; ++i)
	{
		for (int i2 = (size - 1); i2 > i; --i2)
		{
			if (arrayInt[i2] < arrayInt[i2 - 1])
			{
				std::swap(arrayInt[i2], arrayInt[i2 - 1]);
			}
		}
	}

	for_each(begin(arrayInt), end(arrayInt), [](const int& var) { cout << var << ' '; });
}

void quickSort2(int* data, int const len)
{
	int const lenD = len;
	int pivot = 0;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	if (lenD>1) {
		int* L = new int[lenD];
		int* R = new int[lenD];
		pivot = data[ind];
		for (i = 0; i<lenD; i++) {
			if (i != ind) {
				if (data[i]<pivot) {
					L[j] = data[i];
					j++;
				}
				else {
					R[k] = data[i];
					k++;
				}
			}
		}
		quickSort2(L, j);
		quickSort2(R, k);
		for (int cnt = 0; cnt<lenD; cnt++) {
			if (cnt<j) {
				data[cnt] = L[cnt];;
			}
			else if (cnt == j) {
				data[cnt] = pivot;
			}
			else {
				data[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}


void quickSort(int* arrayInt, int size)
{
	if (size < 2)
		return;

	int halfSize = size / 2;
	int point = arrayInt[halfSize];

	int* leftArray = new int[size];
	int* rightArray = new int[size];

	int iL = 0;
	int iR = 0;

	for (int i = 0; i < size; ++i)
	{
		if (i != halfSize)
		{
			if (arrayInt[i] > point)
			{
				rightArray[iR] = arrayInt[i];
				++iR;
			}
			else
			{
				leftArray[iL] = arrayInt[i];
				++iL;
			}
		}
	}

	for (int i = 0; i < iL; ++i)
	{
		cout << leftArray[i] << ' ';
	}
	cout << " [iL = " << iL << "] ";
	for (int i = 0; i < iR; ++i)
	{
		cout << rightArray[i] << ' ';
	}
	cout << " [iR = " << iR << "] (point = " << point << "[" << halfSize  << "])\n\n";

	quickSort(leftArray, iL);
	quickSort(rightArray, iR);


	for (int i = 0; i < size; ++i)
	{
		if (i == iL)
		{
			arrayInt[i] = point;
		}
		else if (i < iL)
		{
			arrayInt[i] = leftArray[i];
		}
		else
		{
			arrayInt[i] = rightArray[i - (iL + 1)];
		}
	}
}

void funQuickShortSort()
{
	TestClass::line("funQuickShortSort");

	int arrayInt[] = { 9, 8, 5, 3, 0, 6, 2, 4, 7, 1, 5 };
	int size = sizeof(arrayInt) / sizeof(arrayInt[0]);

	for_each(begin(arrayInt), end(arrayInt), [](const int& var) { cout << var << ' '; });
	cout << '\n';

	quickSort(arrayInt, size);
	for_each(begin(arrayInt), end(arrayInt), [](const int& var) { cout << var << ' '; });
}

void functionSort()
{
	funBubleSort();
	funQuickShortSort();
}

#endif // !__SORT_H__

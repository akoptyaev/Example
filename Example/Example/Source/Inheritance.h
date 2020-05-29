#pragma once

#include "TestClass.h"
#include "Help.h"

class Base
{
public:
	float f = help::GetRandom(0, 1000);
	float *pF = nullptr;

	Base() {
		pF = new float(help::GetRandom(0, 1000));
		cout << "\t\t\tBase f: " << f << " pF: " << *pF << " [" << this << "] " << endl;
	}
	~Base() {
		if (pF) {
			cout << "\t\t\t~Base f: " << f << " pF: " << *pF << " [" << this << "] " << endl;
		}
		else {
			cout << "\t\t\t~Base f: " << f << " pF: nullptr" << " [" << this << "] " << endl;
		}
		delete pF;
		pF = nullptr;
	}

	Base(const float var) {
		f = var;
		cout << "\t\t\tBase(float) f: " << f << " pF: " << (pF ? *pF : 0) << " [" << this << "] " << endl;

	}
	
	Base(const float var, float *_pF) {
		f = var;

		if (_pF) {
			float *pFtemp = pF;
			pF = new float(*_pF);
			delete pFtemp;
		}
		cout << "\t\t\tBase(float, float*) f: " << f << " pF: " << (pF ? *pF : 0) << " [" << this << "] " << endl;

	}

	Base(const float var, const float var2) {
		f = var;

		float *pFtemp = pF;
		pF = new float(var2);
		delete pFtemp;
		cout << "\t\t\tBase(float, float) f: " << f << " pF: " << (pF ? *pF : 0) << " [" << this << "] " << endl;
	}

	Base(const Base& item) {
		f = item.f;

		if (item.pF) {
			float *pFtemp = pF;
			pF = new float(*item.pF);
			delete pFtemp;
		}
		cout << "\t\t\tBase(Base) f: " << f << " pF: " << (pF ? *pF : 0) << " [" << this << "] << [" << (item.pF ? &item.pF : 0)<< "] " << endl;
	}

	const Base& operator=(const Base& item) {
		f = item.f;

		if (item.pF) {
			float *pFtemp = pF;
			pF = new float(*item.pF);
			delete pFtemp;
		}

		cout << "\t\t\t\operator= f: " << f << " pF: " << (pF ? *pF : 0) << " [" << this << "] << [" << (item.pF ? &item.pF : 0) << "] " << endl;

		return *this;
	}
};


void functionsInheritance();
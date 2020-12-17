#pragma once
#include "Number.h"

class Complex : public Number
{
public:
	Complex(int* a, int* b);
	Complex(Number* a, Number* b);
	Complex(int* a, Number* b);
	Complex(Number* a, int* b);
	void Print(std::ostream& os);
	void Scan(std::istream& is);
	~Complex();
private:
	void* a;
	void* b;
};


Complex::Complex(int* a, int* b) : a(a), b(b)
{
	type = COMPLEX;
	realValue = *a;
}

Complex::Complex(Number* a, Number* b) : a(a), b(b)
{
	type = COMPLEXFRACTIONALFRACTIONAL;
	realValue = a->realValue;
}

Complex::Complex(int* a, Number* b) : a(a), b(b)
{
	type = COMPLEXINTFRACTIONAL;
	realValue = *a;
}

Complex::Complex(Number* a, int* b) : a(a), b(b)
{
	type = COMPLEXFRACTIONALINT;
	realValue = a->realValue;
}

Complex::~Complex()
{
	delete a;
	delete b;
}
void Complex::Print(std::ostream& os)
{
	switch (type)
	{
	case COMPLEX:
		os << '(' << *(int*)a << "+" << *(int*)b << "i" << ')';
		break;
	case COMPLEXINTFRACTIONAL:
		os << '(' << *(int*)a << "+" << *(Number*)b << "i" << ')';
		break;
	case COMPLEXFRACTIONALINT:
		os << '(' << *(Number*)a << "+" << *(int*)b << "i" << ')';
		break;
	case COMPLEXFRACTIONALFRACTIONAL:
		os << '(' << *(Number*)a << "+" << *(Number*)b << "i" << ')';
		break;
	}
}


void Complex::Scan(std::istream& is)
{
	is.ignore(1, '(');
	switch (type)
	{
	case COMPLEX:
		is >> *(int*)a;
		realValue = *(int*)a;
		is.ignore(1, '+');
		is >> *(int*)b;
		break;
	case COMPLEXINTFRACTIONAL:
		is >> *(int*)a;
		realValue = *(int*)a;
		is.ignore(1, '+');
		is >> *(Number*)b;
		break;
	case COMPLEXFRACTIONALINT:
		is >> *(Number*)a;
		realValue = ((Number*)a)->realValue;
		is.ignore(1, '+');
		is >> *(int*)b;
		break;
	case COMPLEXFRACTIONALFRACTIONAL:
		is >> *(Number*)a;
		realValue = ((Number*)a)->realValue;
		is.ignore(1, '+');
		is >> *(Number*)b;
		break;
	}
	is.ignore(2, ')');
}
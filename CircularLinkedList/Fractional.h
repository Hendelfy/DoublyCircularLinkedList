#pragma once
#include "Number.h"
class Fractional : public Number
{
public:
	Fractional(int*, int*);
	Fractional(Number*, Number*);
	Fractional(int*, Number*);
	Fractional(Number*, int*);
	void Print(std::ostream& os);
	void Scan(std::istream& is);
	~Fractional();
private:
	void* numerator;
	void* denominator;

};


Fractional::~Fractional()
{
	delete numerator;
	delete denominator;
}

Fractional::Fractional(int* num, int* den) : numerator(num), denominator(den)
{
	type = FRACTIONAL;
	realValue = *num / *(double*)den;
}

inline Fractional::Fractional(Number* num, Number* den) : numerator(num), denominator(den)
{
	type = FRACTIONALCOMPLEXCOMPLEX;
	realValue = num->realValue / den->realValue;

}

inline Fractional::Fractional(int* num, Number* den) : numerator(num), denominator(den)
{
	type = FRACTIONALINTCOMPLEX;
	realValue = *num / den->realValue;
}

inline Fractional::Fractional(Number* num, int* den) : numerator(num), denominator(den)
{
	type = FRACTIONALCOMPLEXINT;
	realValue = num->realValue / *den;
}

void Fractional::Print(std::ostream& os)
{
	switch (type)
	{
	case FRACTIONAL:
		os << '(' << *(int*)numerator << "/" << *(int*)denominator<< ')';
		break;
	case FRACTIONALINTCOMPLEX:
		os << '(' << *(int*)numerator << "/" << *(Number*)denominator<< ')';
		break;
	case FRACTIONALCOMPLEXINT:
		os << '(' << *(Number*)numerator << "/" << *(int*)denominator<< ')';
		break;
	case FRACTIONALCOMPLEXCOMPLEX:
		os << '(' << *(Number*)numerator << "/" << *(Number*)denominator<< ')';
		break;
	}
}

void Fractional::Scan(std::istream& is) {

	is.ignore(1, '(');
	switch (type)
	{
	case FRACTIONAL:
		is >> *(int*)numerator;
		is.ignore(1, '/');
		is >> *(int*)denominator;
		realValue = *(int*)numerator / *(double*)denominator;
		break;
	case FRACTIONALINTCOMPLEX:
		is >> *(int*)numerator;
		is.ignore(1, '/');
		is >> *(Number*)denominator;
		realValue = *(int*)numerator / ((Number*)denominator)->realValue;
		break;
	case FRACTIONALCOMPLEXINT:
		is >> *(Number*)numerator;
		is.ignore(1, '/');
		is >> *(int*)denominator;
		realValue = ((Number*)numerator)->realValue / *(int*)numerator;
		break;
	case FRACTIONALCOMPLEXCOMPLEX:
		is >> *(Number*)numerator;
		is.ignore(1, '/');
		is >> *(Number*)denominator;
		realValue = ((Number*)numerator)->realValue / ((Number*)denominator)->realValue;
		break;
	}
	is.ignore(1, ')');

}
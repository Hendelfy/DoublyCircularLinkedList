#pragma once

#include <iostream>
enum TYPE
{
	FRACTIONAL, COMPLEX, COMPLEXINTFRACTIONAL, COMPLEXFRACTIONALINT, COMPLEXFRACTIONALFRACTIONAL, FRACTIONALINTCOMPLEX, FRACTIONALCOMPLEXINT, FRACTIONALCOMPLEXCOMPLEX
};
class Number {
public:
	double realValue;
	virtual void Print(std::ostream& os) = 0;

	virtual void Scan(std::istream& is) = 0;
	virtual ~Number();
	friend std::ostream& operator<<(std::ostream& os, const Number& num);

	friend std::istream& operator>>(std::istream& is, const Number& num);
	TYPE type;
};

std::ostream& operator<<(std::ostream& os, Number& num)
{
	num.Print(os);
	return os;
}

std::istream& operator>>(std::istream& is, Number& num)
{
	num.Scan(is);
	return is;
}
Number::~Number()
{
}